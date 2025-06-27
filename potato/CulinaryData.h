void AddCulinaryColumnsToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"Образец",
        L"Разваримость клубней",
        L"Консистенция мякоти",
        L"Рассыпчатость",
        L"Водянистость клубней",
        L"Запах варёного картофеля",
        L"Вкус варёного картофеля",
        L"Потемнение мякоти сырого картофеля",
        L"Потемнение мякоти варёного картофеля"
    };

    int widths[] = { 100, 100, 100, 100, 100, 100, 100, 100, 100 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 9; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}

std::vector<std::vector<std::wstring>> GetCulinaryDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sqlCulinary = "SELECT id_potato, tuber_boilability, pulp_consistency, "
        "friability, wateriness_of_tubers, the_smell_of_boiled_potatoes, "
        "the_taste_of_boiled_potatoes, darkening_of_the_flesh_of_raw_potatoes, darkening_of_the_flesh_of_boiled_potatoes FROM culinary_qualities";
    sqlite3_stmt* stmt;
    int i = 0;
    if (sqlite3_prepare_v2(db, sqlCulinary, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row;
            
            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 0)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 1)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 2)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 3)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 4)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 5)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 6)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 7)));

            row.push_back(std::to_wstring(sqlite3_column_int(stmt, 8)));

            result.push_back(row);
        }
        sqlite3_finalize(stmt);
    }

    return result;
}

void LoadCulinaryDataIntoListView(HWND hListView)
{
    ListView_DeleteAllItems(hListView);

    auto data = GetCulinaryDataFromDatabase();

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