void AddAllToListView(HWND hListView)
{
    const wchar_t* headers[] = {
        L"�������",
        L"� �� �������� �����",
        L"�������������",
        L"�������� ������� � �����, ��.",
        L"���������� ������� � �����, ��.",
        L"����� ��������� ������, �",
        L"����� ����������� ������, �",
        L"������� � �����, ��",
        L"����������, %",
        L"�����������, ��/�2",
        L"����� ������",
        L"������� ������",
        L"������� ������",
        L"������� �������",
        L"������� ���������� �����",
        L"����������� ������ ������",
        L"������������ �������",
        L"�������������",
        L"������������ �������",
        L"����� ������� ���������",
        L"���� ������� ���������",
        L"���������� ������ ������ ���������",
        L"���������� ������ ������� ���������",
        L"������� ������������ � �����������, ����",
        L"����������� � ���������������� �� ������������ (����)",
        L"����������������� ��������,���",
        L"������ ��������",
        L"�����������, %"
        
    };

    int widths[] = { 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 28; i++) {
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
        // ��������� ������ ���������� �������
        const char* err = sqlite3_errmsg(db);
        MessageBoxA(nullptr, err, "Database Error", MB_ICONERROR);
        return results;
    }

    // ����������� ���������
    for (size_t i = 0; i < query.params.size(); ++i) {
        if (sqlite3_bind_text(stmt, i + 1, query.params[i].c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
            sqlite3_finalize(stmt);
            MessageBoxA(nullptr, "Failed to bind parameter", "Database Error", MB_ICONERROR);
            return results;
        }
    }

    // ��������� ������ � �������� ����������
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