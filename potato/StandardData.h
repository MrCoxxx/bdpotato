void AddStandartColumnsToListView(HWND hListView) {
    const wchar_t* headers[] = {
        L"Образец", 
        L"Полевая устойчивость к фитофторозу, балл",
        L"Способность к ягодообразованию от самоопыления (балл)",
        L"Продолжительность цветения,дни",
        L"Группа спелости",
        L"Урожайность, %"
    };

    int widths[] = { 100, 150, 150, 150, 150, 150 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 6; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}

std::vector<std::vector<std::wstring>> GetStandartDataFromDatabase() {
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sqlStandart = "SELECT id_potato, field_resistance_to_late_blight, the_ability_to_form_berries_from_self_pollination, "
        "flowering_duration, ripeness_group, yield_percentage FROM standart";
    sqlite3_stmt* stmt;
    int i = 0;
    if (sqlite3_prepare_v2(db, sqlStandart, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row;

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 0)));

            double field = sqlite3_column_double(stmt, 1);
            std::wstringstream wss7;
            wss7 << std::fixed << std::setprecision(2) << field;
            row.push_back(wss7.str());

            double ability = sqlite3_column_double(stmt, 2);
            std::wstringstream wss8;
            wss8 << std::fixed << std::setprecision(2) << ability;
            row.push_back(wss8.str());

            double flowering = sqlite3_column_double(stmt, 3);
            std::wstringstream wss9;
            wss9 << std::fixed << std::setprecision(2) << flowering;
            row.push_back(wss9.str());

            double ripeness = sqlite3_column_double(stmt, 4);
            std::wstringstream wss0;
            wss0 << std::fixed << std::setprecision(2) << ripeness;
            row.push_back(wss0.str());

            double yield = sqlite3_column_double(stmt, 5);
            std::wstringstream wss10;
            wss10 << std::fixed << std::setprecision(2) << yield;
            row.push_back(wss10.str());
            
            result.push_back(row);
        }
        sqlite3_finalize(stmt);
    }

    return result;
}

void LoadStandartDataIntoListView(HWND hListView) {
    ListView_DeleteAllItems(hListView);

    auto data = GetStandartDataFromDatabase();

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