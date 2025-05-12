void InitializeDatabase()
{
    // Используем sqlite3_open вместо sqlite3_open16
    int rc = sqlite3_open("potato.db", &db);
    if (rc != SQLITE_OK) {
        MessageBoxW(NULL, L"Не удалось открыть базу данных", L"Ошибка", MB_ICONERROR);
        return;
    }

    // Устанавливаем кодировку UTF-8 для соединения
    sqlite3_exec(db, "PRAGMA encoding = 'UTF-8'", NULL, NULL, NULL);
}

void AddPotatoColumnsToListView(HWND hListView)
{
    // Создаем массив для заголовков колонок
    const wchar_t* headers[] = {
        L"ID",
        L"Образец",
        L"Происхождение",
        L"Каталожный № ВИГРР",
        L"Урожайность",
        L"Устойчивость к фитофторозу",
        L"Вес товарного клубня"
    };

    int widths[] = { 50, 100, 150, 100, 100, 100, 100 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 7; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}

void LoadPotatoDataIntoListView(HWND hListView)
{
    // Очищаем список
    ListView_DeleteAllItems(hListView);

    // Получаем данные из БД
    auto data = GetPotatoDataFromDatabase();

    // Добавляем данные в ListView
    LVITEM lvi = { 0 };
    lvi.mask = LVIF_TEXT;

    for (size_t i = 0; i < data.size(); i++) {
        lvi.iItem = static_cast<int>(i);
        lvi.iSubItem = 0;

        wchar_t buffer[256];
        wcscpy_s(buffer, data[i][0].c_str());
        lvi.pszText = buffer;

        ListView_InsertItem(hListView, &lvi);

        // Добавляем подэлементы
        for (size_t j = 1; j < data[i].size(); j++) {
            wcscpy_s(buffer, data[i][j].c_str());
            ListView_SetItemText(hListView, i, static_cast<int>(j), buffer);
        }
    }
}

std::wstring utf8_to_utf16(const std::string& utf8)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(utf8);
}

// Функция для конвертации UTF-16 в UTF-8 (string)
std::string utf16_to_utf8(const std::wstring& utf16)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(utf16);
}

void AddPotatoSample(const std::wstring& sample, const std::wstring& origin)
{
    std::string utf8_sample = utf16_to_utf8(sample);
    std::string utf8_origin = utf16_to_utf8(origin);

    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO potato (sample, origin) VALUES (?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_origin.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}

std::vector<std::vector<std::wstring>> GetPotatoDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sql = "SELECT id, sample, origin, VIGRR_catalogue_number, "
        "productivity, field_resistance_to_late_blight, "
        "weight_of_commercial_tuber FROM potato";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row;

            // ID (число, не требует конвертации)
            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 0)));

            // Sample
            const unsigned char* sample = sqlite3_column_text(stmt, 1);
            if (sample) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(sample)));
            }
            else {
                row.push_back(L"");
            }

            // Origin
            const unsigned char* origin = sqlite3_column_text(stmt, 2);
            if (origin) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(origin)));
            }
            else {
                row.push_back(L"");
            }

            // VIGRR catalogue number
            const unsigned char* vigrr = sqlite3_column_text(stmt, 3);
            if (vigrr) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(vigrr)));
            }
            else {
                row.push_back(L"");
            }

            // Productivity
            double productivity = sqlite3_column_double(stmt, 4);
            std::wstringstream wss;
            wss << std::fixed << std::setprecision(2) << productivity;
            row.push_back(wss.str());

            // Field resistance to late blight
            int resistance = sqlite3_column_int(stmt, 5);
            row.push_back(std::to_wstring(resistance));

            // Weight of commercial tuber
            int weight = sqlite3_column_int(stmt, 6);
            row.push_back(std::to_wstring(weight));

            result.push_back(row);
        }
        sqlite3_finalize(stmt);
    }

    return result;
}

void LoadTableData(HWND hWnd) 
{

    // Создаем ListView
    hListView = CreateWindow(WC_LISTVIEW, L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_EDITLABELS,
        270, 10, 700, 570,
        hWnd, (HMENU)ID_LISTVIEW,
        hInstance, NULL);

    // Настраиваем колонки и загружаем данные
    AddPotatoColumnsToListView(hListView);
    LoadPotatoDataIntoListView(hListView);

}