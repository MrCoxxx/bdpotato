void AddMorphologicalColumnsToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"Образец",
        L"Форма",
        L"Окраска кожуры",
        L"Окраска мякоти",
        L"Глубина глазков",
        L"Глубина столонного следа",
        L"Поверхность кожуры клубня"
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

    const char* sqlMorphological = "SELECT id_potato, form, peel_coloring, "
        "pulp_coloring, eye_depth, "
        "stolon_trace_depth, tuber_skin_surface FROM morphological_features_of_the_tuber";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sqlMorphological, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row; 

            const unsigned char* sample = sqlite3_column_text(stmt, 0);
            if (sample) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(sample)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* form = sqlite3_column_text(stmt, 1);
            if (form) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(form)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* peel_coloring = sqlite3_column_text(stmt, 2);
            if (peel_coloring) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(peel_coloring)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* pulp_coloring = sqlite3_column_text(stmt, 3);
            if (pulp_coloring) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(pulp_coloring)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* eye_depth = sqlite3_column_text(stmt, 4);
            if (eye_depth) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(eye_depth)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* stolon_trace_depth = sqlite3_column_text(stmt, 5);
            if (stolon_trace_depth) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(stolon_trace_depth)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* tuber_skin_surface = sqlite3_column_text(stmt, 6);
            if (tuber_skin_surface) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(tuber_skin_surface)));
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