void AddAllToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"Образец",
        L"Происхождение",
        L"ВИГРР",
        L"Урожайность",
        L"Полевая устойчивость к фитофторозу",
        L"Форма",
        L"Окраска кожуры",
        L"Окраска мякоти",
        L"Глубина глазков",
        L"Глубина столонного следа",
        L"Вкус",
        L"Консистенция мякоти",
        L"Потемнение после варки",
        L"Масса товарного клубня"
    };

    int widths[] = { 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 14; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}


std::vector<std::vector<std::wstring>> GetAllDataFromDatabase(sqlite3* db)
{
    std::vector<std::vector<std::wstring>> results;

    QueryData query = BuildQuery();
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, query.sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        // Обработка ошибки подготовки запроса
        const char* err = sqlite3_errmsg(db);
        MessageBoxA(nullptr, err, "Database Error", MB_ICONERROR);
        return results;
    }

    // Привязываем параметры
    for (size_t i = 0; i < query.params.size(); ++i) {
        if (sqlite3_bind_text(stmt, i + 1, query.params[i].c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
            sqlite3_finalize(stmt);
            MessageBoxA(nullptr, "Failed to bind parameter", "Database Error", MB_ICONERROR);
            return results;
        }
    }

    // Выполняем запрос и получаем результаты
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::wstring> row;
        for (int col = 0; col < sqlite3_column_count(stmt); ++col) {
            const unsigned char* text = sqlite3_column_text(stmt, col);
            if (text) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(text)));
            }
            else {
                row.push_back(L"");
            }
        }
        results.push_back(row);
    }

    sqlite3_finalize(stmt);
    return results;
}

void LoadAllDataIntoListView(HWND hListView)
{
    ListView_DeleteAllItems(hListView);

    auto data = GetAllDataFromDatabase(db);

    LVITEM lvi = { 0 };
    lvi.mask = LVIF_TEXT;

    for (size_t i = 0; i < data.size(); i++) {
        lvi.iItem = static_cast<int>(i);
        lvi.iSubItem = 0;

        wchar_t buffer[256];
        wcscpy_s(buffer, data[i][0].c_str());
        lvi.pszText = buffer;

        ListView_InsertItem(hListView, &lvi);

        for (size_t j = 1; j < data[i].size(); j++) {
            wcscpy_s(buffer, data[i][j].c_str());
            ListView_SetItemText(hListView, i, static_cast<int>(j), buffer);
        }
    }
}

void AddAllSample(const std::wstring& sample, const std::wstring& origin)
{
    std::string utf8_sample = utf16_to_utf8(sample);
    std::string utf8_origin = utf16_to_utf8(origin);

    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO morphological_features_of_the_tuber (sample, origin) VALUES (?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_origin.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}
