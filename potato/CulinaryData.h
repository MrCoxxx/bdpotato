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

void AddCulinarySample()
{
    IDPotatoC = GetEditText(editIDPotatoC);
    Taste = GetEditText(editTaste);
    Consistency = GetEditText(editConsistency);
    Darkening = GetEditText(editDarkening);

    utf8_IDPotatoC = utf16_to_utf8(IDPotatoC);
    utf8_Taste = utf16_to_utf8(Taste);
    utf8_Consistency = utf16_to_utf8(Consistency);
    utf8_Darkening = utf16_to_utf8(Darkening);   


    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO culinary_qualities (id_potato, taste, pulp_consistency, darkening_after_cooking) VALUES (?, ?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_IDPotatoC.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Taste.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_Consistency.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Darkening.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_ID.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}

void EditCulinarySample()
{
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE culinary_qualities SET id_potato = ?, taste = ?, pulp_consistency = ?, darkening_after_cooking = ? WHERE id = ?";

    Sample = GetEditText(editSample);
    Origin = GetEditText(editOrigin);
    VIGRR = GetEditText(editVIGRR);
    Productivity = GetEditText(editProductivity);
    Field = GetEditText(editField);
    Weight = GetEditText(editWeightN);


    utf8_Sample = utf16_to_utf8(Sample);
    utf8_Origin = utf16_to_utf8(Origin);
    utf8_VIGRR = utf16_to_utf8(VIGRR);
    utf8_Productivity = utf16_to_utf8(Productivity);
    utf8_Field = utf16_to_utf8(Field);
    utf8_Weight = utf16_to_utf8(Weight);

    ID = GetEditText(editID);
    utf8_ID = utf16_to_utf8(ID);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_Sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Origin.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_VIGRR.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Productivity.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_ID.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}