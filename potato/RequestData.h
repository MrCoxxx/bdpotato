void AddAllToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"ID",
        L"Образец",
        L"Вкус",
        L"Консистенция",
        L"Потемнение после варки",
        L"ID1",
        L"Образец1",
        L"Вкус1",
        L"Консистенция1",
        L"Потемнение после варки1",
        L"ID2",
        L"Образец2",
        L"Вкус2",
        L"Консистенция2"
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

std::vector<std::vector<std::wstring>> GetAllDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    //const char* name = "Арамис";

    std::wstring name = L"Арамис";
    std::string utf8_name = utf16_to_utf8(name);
    double name1 = 2.25;
    //std::string utf8_name1 = utf16_to_utf8(name1);

    const char* sqlAll = "SELECT p.sample, p.origin, p.VIGRR_catalogue_number, p.productivity, p.field_resistance_to_late_blight, "
        "mf.form, mf.peel_coloring, mf.pulp_coloring, mf.eye_depth, mf.stolon_trace_depth, "
        "cq.taste, cq.pulp_consistency, cq.darkening_after_cooking, p.weight_of_commercial_tuber "
        "FROM potato p JOIN morphological_features_of_the_tuber mf ON p.id = mf.id_potato JOIN culinary_qualities cq ON p.id = cq.id_potato WHERE p.productivity = ? AND p.sample = ?  ";
    sqlite3_stmt* stmt;

    

    
    if (sqlite3_prepare_v2(db, sqlAll, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 2, utf8_name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 1, name1);
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::vector<std::wstring> row;            
            const unsigned char* sample = sqlite3_column_text(stmt, 0);
            if (sample) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(sample)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* origin = sqlite3_column_text(stmt, 1);
            if (origin) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(origin)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* VIGGR = sqlite3_column_text(stmt, 2);
            if (VIGGR) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(VIGGR)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* productivity = sqlite3_column_text(stmt, 3);
            if (productivity) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(productivity)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* field = sqlite3_column_text(stmt, 4);
            if (field) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(field)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* form = sqlite3_column_text(stmt, 5);
            if (form) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(form)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* peel = sqlite3_column_text(stmt, 6);
            if (peel) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(peel)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* pulp = sqlite3_column_text(stmt, 7);
            if (pulp) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(pulp)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* eye = sqlite3_column_text(stmt, 8);
            if (eye) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(eye)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* stolon = sqlite3_column_text(stmt, 9);
            if (stolon) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(stolon)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* taste = sqlite3_column_text(stmt, 10);
            if (taste) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(taste)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* consistency = sqlite3_column_text(stmt, 11);
            if (consistency) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(consistency)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* darkening = sqlite3_column_text(stmt, 12);
            if (darkening) {
                row.push_back(utf8_to_utf16(reinterpret_cast<const char*>(darkening)));
            }
            else {
                row.push_back(L"");
            }

            const unsigned char* weight = sqlite3_column_text(stmt, 13);
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

void LoadAllDataIntoListView(HWND hListView)
{
    ListView_DeleteAllItems(hListView);

    auto data = GetAllDataFromDatabase();

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
