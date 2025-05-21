void InitializeDatabase()
{
    // ���������� sqlite3_open ������ sqlite3_open16
    int rc = sqlite3_open("potato.db", &db);
    if (rc != SQLITE_OK) {
        MessageBoxW(NULL, L"�� ������� ������� ���� ������", L"������", MB_ICONERROR);
        return;
    }

    // ������������� ��������� UTF-8 ��� ����������
    sqlite3_exec(db, "PRAGMA encoding = 'UTF-8'", NULL, NULL, NULL);
}

std::wstring utf8_to_utf16(const std::string& utf8)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(utf8);
}
// ������� ��� ����������� UTF-16 � UTF-8 (string)
std::string utf16_to_utf8(const std::wstring& utf16)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(utf16);
}