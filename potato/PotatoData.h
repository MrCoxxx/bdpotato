void AddPotatoColumnsToListView(HWND hListView)
{
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

std::vector<std::vector<std::wstring>> GetPotatoDataFromDatabase()
{
    std::vector<std::vector<std::wstring>> result;

    if (!db) return result;

    const char* sqlPotato = "SELECT id, sample, origin, VIGRR_catalogue_number, "
        "productivity, field_resistance_to_late_blight, "
        "weight_of_commercial_tuber FROM potato";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sqlPotato, -1, &stmt, NULL) == SQLITE_OK) {
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

            double productivity = sqlite3_column_double(stmt, 4);
            std::wstringstream wss;
            wss << std::fixed << std::setprecision(2) << productivity;
            row.push_back(wss.str());

            int resistance = sqlite3_column_int(stmt, 5);
            row.push_back(std::to_wstring(resistance));

            int weight = sqlite3_column_int(stmt, 6);
            row.push_back(std::to_wstring(weight));

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

void AddPotatoSample()
{
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO potato (sample, origin, VIGRR_catalogue_number, productivity, field_resistance_to_late_blight, weight_of_commercial_tuber) VALUES (?, ?, ?, ?, ?, ?)";

    Sample = GetEditText(editSample);
    Origin = GetEditText(editOrigin);
    VIGRR = GetEditText(editVIGRR);
    Productivity = GetEditText(editProductivity);
    Field = GetEditText(editField);
    Weight = GetEditText(editWeight);

    utf8_Sample = utf16_to_utf8(Sample);
    utf8_Origin = utf16_to_utf8(Origin);
    utf8_VIGRR = utf16_to_utf8(VIGRR);
    utf8_Productivity = utf16_to_utf8(Productivity);
    utf8_Field = utf16_to_utf8(Field);
    utf8_Weight = utf16_to_utf8(Weight);

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, utf8_Sample.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, utf8_Origin.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, utf8_VIGRR.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, utf8_Productivity.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 5, utf8_Field.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, utf8_Weight.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}

void EditPotatoSample()
{
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE potato SET sample = ?, origin = ?, VIGRR_catalogue_number = ?, productivity = ?, field_resistance_to_late_blight = ?, weight_of_commercial_tuber = ? WHERE id = ?";

    Sample = GetEditText(editSample);
    Origin = GetEditText(editOrigin);
    VIGRR = GetEditText(editVIGRR);
    Productivity = GetEditText(editProductivity);
    Field = GetEditText(editField);
    Weight = GetEditText(editWeight);


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
        sqlite3_bind_text(stmt, 5, utf8_Field.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 6, utf8_Weight.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 7, utf8_ID.c_str(), -1, SQLITE_TRANSIENT);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // Обработка ошибки
        }

        sqlite3_finalize(stmt);
    }
}