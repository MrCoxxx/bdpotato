void InitializeDatabase()
{
    // Используем sqlite3_open вместо sqlite3_open16
    int rc = sqlite3_open("potato.db", &db);
    if (rc != SQLITE_OK) {
        MessageBoxW(NULL, L"Не удалось открыть базу данных", L"Ошибка", MB_ICONERROR);
        return;
    }

    // Устанавливаем кодировку UTF-8 для соединения
    sqlite3_exec(db, "PRAGMA encoding = 'UTF-8'", NULL, NULL, NULL);
}

std::wstring utf8_to_utf16(const std::string& utf8)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(utf8);
}
// Функция для конвертации UTF-16 в UTF-8 (string)
std::string utf16_to_utf8(const std::wstring& utf16)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(utf16);
}