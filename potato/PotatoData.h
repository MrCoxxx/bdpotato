void AddPotatoColumnsToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"Образец",
        L"№ по каталогу ВИГРР",
        L"Происхождение",
        L"Товарных клубней в клоне, шт.",
        L"Нетоварных клубней в клоне, шт.",
        L"Масса товарного клубня, г",
        L"Масса нетоварного клубня, г",
        L"Клубней в клоне, шт",
        L"Товарность, %",
        L"Урожайность, кг/м2",
    };

    int widths[] = { 50, 100, 150, 100, 100, 100, 100, 100, 100, 100 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 10; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}

std::vector<std::vector<std::wstring>> GetPotatoDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sqlPotato = "SELECT sample, VIGRR_catalogue_number, origin, "
        "commercial_tubers_in_clone, non_marketable_tubers_in_clone, "
        "weight_of_commercial_tuber, weight_of_non_commercial_tuber, tubers_in_clone, "
        "marketability, productivity FROM potato";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sqlPotato, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row;

            const unsigned char* sample = sqlite3_column_text(stmt, 0);
            if (sample) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(sample)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* vigrr = sqlite3_column_text(stmt, 1);
            if (vigrr) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(vigrr)));
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

            double commercial = sqlite3_column_double(stmt, 3);
            std::wstringstream wss;
            wss << std::fixed << std::setprecision(2) << commercial;
            row.push_back(wss.str());

            double non_marketable = sqlite3_column_double(stmt, 4);
            std::wstringstream wss1;
            wss1 << std::fixed << std::setprecision(2) << non_marketable;
            row.push_back(wss1.str());

            double commercial_tuber = sqlite3_column_double(stmt, 5);
            std::wstringstream wss2;
            wss2 << std::fixed << std::setprecision(2) << commercial_tuber;
            row.push_back(wss2.str());

            double non_commercial_tuber = sqlite3_column_double(stmt, 6);
            std::wstringstream wss3;
            wss3 << std::fixed << std::setprecision(2) << non_commercial_tuber;
            row.push_back(wss3.str());

            double tubers = sqlite3_column_double(stmt, 7);
            std::wstringstream wss4;
            wss4 << std::fixed << std::setprecision(2) << tubers;
            row.push_back(wss4.str());

            double marketability = sqlite3_column_double(stmt, 8);
            std::wstringstream wss5;
            wss5 << std::fixed << std::setprecision(2) << marketability;
            row.push_back(wss5.str());

            double productivity = sqlite3_column_double(stmt, 9);
            std::wstringstream wss6;
            wss6 << std::fixed << std::setprecision(2) << productivity;
            row.push_back(wss6.str());

            result.push_back(row);
        }
        sqlite3_finalize(stmt);
    }

    return result;
}

void LoadPotatoDataIntoListView(HWND hListView)
{
    ListView_DeleteAllItems(hListView);

    auto data = GetPotatoDataFromDatabase();

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