void AddMorphologicalColumnsToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"ID",
        L"Образец",
        L"Форма",
        L"Окраска кожуры",
        L"Окраска мякоти",
        L"Глубина глазков",
        L"Глубина столонного следа"
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

std::vector<std::vector<std::wstring>> GetMorphologicalDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sqlMorphological = "SELECT id, id_potato, form, peel_coloring, "
        "pulp_coloring, eye_depth, "
        "stolon_trace_depth FROM morphological_features_of_the_tuber";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sqlMorphological, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row; 

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 0)));

            const unsigned char* sample = sqlite3_column_text(stmt, 1);
            if (sample) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(sample)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* origin = sqlite3_column_text(stmt, 2);
            if (origin) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(origin)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* vigrr = sqlite3_column_text(stmt, 3);
            if (vigrr) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(vigrr)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* productivity = sqlite3_column_text(stmt, 4);
            if (productivity) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(productivity)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* resistance = sqlite3_column_text(stmt, 5);
            if (resistance) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(resistance)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* weight = sqlite3_column_text(stmt, 6);
            if (weight) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(weight)));
            }
            else {
                row.push_back(L"");
            }

            result.push_back(row);
        }
        sqlite3_finalize(stmt);
    }

    return result;
}

void LoadMorphologicalDataIntoListView(HWND hListView)
{
    ListView_DeleteAllItems(hListView);

    auto data = GetMorphologicalDataFromDatabase();

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

void AddMorphologicalSample(const std::wstring& sample, const std::wstring& origin)
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
