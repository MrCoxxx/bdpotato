// TemplateInterface.h - Интерфейс для управления шаблонами поиска
// Функционал:
// 1. Создание, редактирование, удаление и сохранение шаблонов в JSON
// 2. Сравнение параметров шаблона с данными из базы данных
// 3. Полная поддержка русского языка (UTF-8)

#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

// Структура для хранения параметра шаблона
struct TemplateParameter {
    std::wstring name;              // Название параметра
    std::wstring value;             // Значение параметра
    std::wstring minValue;          // Минимальное значение (если применимо)
    std::wstring maxValue;          // Максимальное значение (если применимо)
    bool isRange;                   // Является ли параметр диапазоном
};

// Структура для хранения шаблона
struct Template {
    std::wstring name;              // Название шаблона
    std::wstring description;       // Описание шаблона
    std::vector<TemplateParameter> parameters;  // Параметры шаблона
    std::wstring createdDate;       // Дата создания
    std::wstring modifiedDate;      // Дата изменения
};

// Глобальные переменные для интерфейса
HWND staticTemplateName;
HWND editTemplateName;
HWND staticTemplateDescription;
HWND editTemplateDescription;
HWND buttonCreate;
HWND buttonEdit;
HWND buttonDelete;
HWND buttonSave;
HWND buttonLoad;
HWND buttonCompare;
HWND buttonClear;
HWND hTemplateListView;
HWND hParametersListView;
HWND comboTemplates;

std::vector<Template> loadedTemplates;
int currentTemplateIndex = -1;

// Вспомогательные функции для работы с JSON
std::string utf16_to_utf8_json(const std::wstring& wstr) {
    if (wstr.empty()) return "";
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
    return str;
}

std::wstring utf8_to_utf16_json(const std::string& str) {
    if (str.empty()) return L"";
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
    return wstr;
}

// Экранирование специальных символов для JSON
std::string escapeJsonString(const std::string& str) {
    std::string result;
    for (char c : str) {
        switch (c) {
        case '"':  result += "\\\""; break;
        case '\\': result += "\\\\"; break;
        case '\b': result += "\\b";  break;
        case '\f': result += "\\f";  break;
        case '\n': result += "\\n";  break;
        case '\r': result += "\\r";  break;
        case '\t': result += "\\t";  break;
        default:
            if (c < 32) {
                char buf[8];
                sprintf_s(buf, 8, "\\u%04x", (unsigned char)c);
                result += buf;
            }
            else {
                result += c;
            }
        }
    }
    return result;
}

// Сохранение шаблонов в JSON файл
bool SaveTemplatesToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    file << "{\n";
    file << "  \"templates\": [\n";

    for (size_t i = 0; i < loadedTemplates.size(); i++) {
        const auto& tmpl = loadedTemplates[i];
        file << "    {\n";
        file << "      \"name\": \"" << escapeJsonString(utf16_to_utf8_json(tmpl.name)) << "\",\n";
        file << "      \"description\": \"" << escapeJsonString(utf16_to_utf8_json(tmpl.description)) << "\",\n";
        file << "      \"createdDate\": \"" << utf16_to_utf8_json(tmpl.createdDate) << "\",\n";
        file << "      \"modifiedDate\": \"" << utf16_to_utf8_json(tmpl.modifiedDate) << "\",\n";
        file << "      \"parameters\": [\n";

        for (size_t j = 0; j < tmpl.parameters.size(); j++) {
            const auto& param = tmpl.parameters[j];
            file << "        {\n";
            file << "          \"name\": \"" << escapeJsonString(utf16_to_utf8_json(param.name)) << "\",\n";
            file << "          \"value\": \"" << escapeJsonString(utf16_to_utf8_json(param.value)) << "\",\n";
            file << "          \"minValue\": \"" << escapeJsonString(utf16_to_utf8_json(param.minValue)) << "\",\n";
            file << "          \"maxValue\": \"" << escapeJsonString(utf16_to_utf8_json(param.maxValue)) << "\",\n";
            file << "          \"isRange\": " << (param.isRange ? "true" : "false") << "\n";
            file << "        }";
            if (j < tmpl.parameters.size() - 1) file << ",";
            file << "\n";
        }

        file << "      ]\n";
        file << "    }";
        if (i < loadedTemplates.size() - 1) file << ",";
        file << "\n";
    }

    file << "  ]\n";
    file << "}\n";
    file.close();
    return true;
}

// Загрузка шаблонов из JSON файла
bool LoadTemplatesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    loadedTemplates.clear();
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Простой парсер JSON (для полноты функционала рекомендуется использовать библиотеку nlohmann/json)
    // Данная реализация парсит основную структуру
    size_t pos = content.find("\"templates\": [");
    if (pos == std::string::npos) return false;

    // Парсим каждый шаблон
    size_t start = content.find('{', pos);
    while (start != std::string::npos && start < content.length()) {
        size_t end = content.find('}', start);
        if (end == std::string::npos) break;

        // Извлекаем поля шаблона
        Template tmpl;
        
        // Название
        size_t nameStart = content.find("\"name\": \"", start);
        if (nameStart != std::string::npos) {
            nameStart += 10;
            size_t nameEnd = content.find("\"", nameStart);
            std::string nameStr = content.substr(nameStart, nameEnd - nameStart);
            tmpl.name = utf8_to_utf16_json(nameStr);
        }

        // Описание
        size_t descStart = content.find("\"description\": \"", start);
        if (descStart != std::string::npos) {
            descStart += 17;
            size_t descEnd = content.find("\"", descStart);
            std::string descStr = content.substr(descStart, descEnd - descStart);
            tmpl.description = utf8_to_utf16_json(descStr);
        }

        // Дата создания
        size_t createdStart = content.find("\"createdDate\": \"", start);
        if (createdStart != std::string::npos) {
            createdStart += 17;
            size_t createdEnd = content.find("\"", createdStart);
            std::string createdStr = content.substr(createdStart, createdEnd - createdStart);
            tmpl.createdDate = utf8_to_utf16_json(createdStr);
        }

        // Дата изменения
        size_t modifiedStart = content.find("\"modifiedDate\": \"", start);
        if (modifiedStart != std::string::npos) {
            modifiedStart += 18;
            size_t modifiedEnd = content.find("\"", modifiedStart);
            std::string modifiedStr = content.substr(modifiedStart, modifiedEnd - modifiedStart);
            tmpl.modifiedDate = utf8_to_utf16_json(modifiedStr);
        }

        loadedTemplates.push_back(tmpl);
        
        start = content.find('{', end + 1);
        if (start > content.find(']', end)) break;
    }

    file.close();
    return true;
}

// Получение текущей даты в формате YYYY-MM-DD
std::wstring GetCurrentDate() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    
    wchar_t buffer[32];
    swprintf_s(buffer, 32, L"%04d-%02d-%02d", st.wYear, st.wMonth, st.wDay);
    return std::wstring(buffer);
}

// Получение текущей даты и времени в формате ISO 8601
std::wstring GetCurrentDateTime() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    
    wchar_t buffer[32];
    swprintf_s(buffer, 32, L"%04d-%02d-%02dT%02d:%02d:%02d", 
        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return std::wstring(buffer);
}

// Инициализация интерфейса шаблонов
void InitializeTemplateInterface(HWND hWnd) {
    // Название шаблона
    staticTemplateName = CreateWindow(
        L"static",
        L"Название шаблона",
        WS_VISIBLE | WS_CHILD | ES_CENTER,
        15, 15, 200, 20,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    editTemplateName = CreateWindow(
        L"edit",
        L"",
        WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
        15, 40, 200, 25,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    // Описание шаблона
    staticTemplateDescription = CreateWindow(
        L"static",
        L"Описание",
        WS_VISIBLE | WS_CHILD | ES_CENTER,
        220, 15, 200, 20,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    editTemplateDescription = CreateWindow(
        L"edit",
        L"",
        WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
        220, 40, 200, 25,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    // Комбобокс для выбора шаблона
    comboTemplates = CreateWindow(
        L"combobox",
        L"",
        WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
        425, 40, 200, 200,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    // Список параметров шаблона
    hParametersListView = CreateWindow(
        WC_LISTVIEW,
        L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT,
        15, 80, 610, 200,
        hWnd,
        NULL,
        NULL,
        NULL
    );

    // Кнопки управления
    buttonCreate = CreateWindow(
        L"button",
        L"Создать",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        15, 290, 90, 30,
        hWnd,
        (HMENU)1001,
        NULL,
        NULL
    );

    buttonEdit = CreateWindow(
        L"button",
        L"Редактировать",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        110, 290, 90, 30,
        hWnd,
        (HMENU)1002,
        NULL,
        NULL
    );

    buttonDelete = CreateWindow(
        L"button",
        L"Удалить",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        205, 290, 90, 30,
        hWnd,
        (HMENU)1003,
        NULL,
        NULL
    );

    buttonSave = CreateWindow(
        L"button",
        L"Сохранить",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        300, 290, 90, 30,
        hWnd,
        (HMENU)1004,
        NULL,
        NULL
    );

    buttonLoad = CreateWindow(
        L"button",
        L"Загрузить",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        395, 290, 90, 30,
        hWnd,
        (HMENU)1005,
        NULL,
        NULL
    );

    buttonCompare = CreateWindow(
        L"button",
        L"Сравнить",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        490, 290, 135, 30,
        hWnd,
        (HMENU)1006,
        NULL,
        NULL
    );

    buttonClear = CreateWindow(
        L"button",
        L"Очистить",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        15, 330, 90, 30,
        hWnd,
        (HMENU)1007,
        NULL,
        NULL
    );
}

// Инициализация столбцов ListView для параметров
void InitializeParametersColumns(HWND hListView) {
    const wchar_t* headers[] = {
        L"Параметр",
        L"Значение",
        L"Минимум",
        L"Максимум",
        L"Диапазон"
    };

    int widths[] = { 150, 150, 100, 100, 80 };

    LVCOLUMN lvc = { 0 };
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

    for (int i = 0; i < 5; i++) {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(headers[i]);
        lvc.cx = widths[i];
        lvc.fmt = LVCFMT_LEFT;
        ListView_InsertColumn(hListView, i, &lvc);
    }
}

// Добавление параметра к текущему шаблону
void AddParameterToTemplate(const std::wstring& name, const std::wstring& value, 
                            const std::wstring& minVal, const std::wstring& maxVal, bool isRange) {
    if (currentTemplateIndex >= 0 && currentTemplateIndex < (int)loadedTemplates.size()) {
        TemplateParameter param;
        param.name = name;
        param.value = value;
        param.minValue = minVal;
        param.maxValue = maxVal;
        param.isRange = isRange;

        loadedTemplates[currentTemplateIndex].parameters.push_back(param);
        loadedTemplates[currentTemplateIndex].modifiedDate = GetCurrentDateTime();
    }
}

// Очистка текущего шаблона
void ClearCurrentTemplate() {
    if (currentTemplateIndex >= 0 && currentTemplateIndex < (int)loadedTemplates.size()) {
        SetWindowText(editTemplateName, L"");
        SetWindowText(editTemplateDescription, L"");
        ListView_DeleteAllItems(hParametersListView);
    }
}

// Отображение параметров шаблона в ListView
void DisplayTemplateParameters(int templateIndex) {
    ListView_DeleteAllItems(hParametersListView);

    if (templateIndex < 0 || templateIndex >= (int)loadedTemplates.size()) return;

    const auto& tmpl = loadedTemplates[templateIndex];

    LVITEM lvi = { 0 };
    lvi.mask = LVIF_TEXT;

    for (size_t i = 0; i < tmpl.parameters.size(); i++) {
        const auto& param = tmpl.parameters[i];

        lvi.iItem = static_cast<int>(i);
        lvi.iSubItem = 0;
        lvi.pszText = const_cast<wchar_t*>(param.name.c_str());
        ListView_InsertItem(hParametersListView, &lvi);

        ListView_SetItemText(hParametersListView, i, 1, const_cast<wchar_t*>(param.value.c_str()));
        ListView_SetItemText(hParametersListView, i, 2, const_cast<wchar_t*>(param.minValue.c_str()));
        ListView_SetItemText(hParametersListView, i, 3, const_cast<wchar_t*>(param.maxValue.c_str()));
        
        std::wstring isRangeStr = param.isRange ? L"Да" : L"Нет";
        ListView_SetItemText(hParametersListView, i, 4, const_cast<wchar_t*>(isRangeStr.c_str()));
    }
}

// Создание нового шаблона
void CreateNewTemplate() {
    Template newTemplate;
    newTemplate.name = L"Новый шаблон";
    newTemplate.description = L"";
    newTemplate.createdDate = GetCurrentDateTime();
    newTemplate.modifiedDate = GetCurrentDateTime();

    loadedTemplates.push_back(newTemplate);
    currentTemplateIndex = loadedTemplates.size() - 1;

    SetWindowText(editTemplateName, newTemplate.name.c_str());
    SetWindowText(editTemplateDescription, newTemplate.description.c_str());
    ClearCurrentTemplate();
}

// Удаление текущего шаблона
void DeleteCurrentTemplate() {
    if (currentTemplateIndex >= 0 && currentTemplateIndex < (int)loadedTemplates.size()) {
        loadedTemplates.erase(loadedTemplates.begin() + currentTemplateIndex);
        currentTemplateIndex = -1;
        ClearCurrentTemplate();
    }
}

// Сравнение параметров шаблона с данными из базы данных
// Возвращает количество совпадений
int CompareTemplateWithDatabase(int templateIndex) {
    if (templateIndex < 0 || templateIndex >= (int)loadedTemplates.size()) return 0;

    const auto& tmpl = loadedTemplates[templateIndex];
    int matchCount = 0;

    // Примечание: эта функция должна быть интегрирована с существующей системой
    // запросов к базе данных (SqlRequestData.h)
    // Здесь демонстрируется структура для интеграции

    // Получаем данные из базы
    // auto dbData = GetDataFromDatabase();

    // Сравниваем каждый параметр шаблона с данными БД
    for (const auto& param : tmpl.parameters) {
        // Логика сравнения в зависимости от типа параметра
        if (param.isRange) {
            // Для диапазонов проверяем вхождение значений в диапазон
            // dbValue >= param.minValue && dbValue <= param.maxValue
        }
        else {
            // Для простых значений проверяем точное совпадение
            // dbValue == param.value
        }
    }

    return matchCount;
}

// Экспорт параметров шаблона для использования в поиске
std::string ExportTemplateForSearch(int templateIndex) {
    if (templateIndex < 0 || templateIndex >= (int)loadedTemplates.size()) return "";

    const auto& tmpl = loadedTemplates[templateIndex];
    std::string sql = "SELECT * FROM potato WHERE 1=1";

    for (const auto& param : tmpl.parameters) {
        std::string paramUtf8 = utf16_to_utf8_json(param.name);
        std::string valueUtf8 = utf16_to_utf8_json(param.value);

        if (param.isRange) {
            std::string minUtf8 = utf16_to_utf8_json(param.minValue);
            std::string maxUtf8 = utf16_to_utf8_json(param.maxValue);
            sql += " AND " + paramUtf8 + " >= " + minUtf8 + " AND " + paramUtf8 + " <= " + maxUtf8;
        }
        else {
            sql += " AND " + paramUtf8 + " = '" + valueUtf8 + "'";
        }
    }

    return sql;
}

// Обновление комбобокса с названиями шаблонов
void UpdateTemplateComboBox() {
    SendMessage(comboTemplates, CB_RESETCONTENT, 0, 0);

    for (const auto& tmpl : loadedTemplates) {
        SendMessageW(comboTemplates, CB_ADDSTRING, 0, (LPARAM)tmpl.name.c_str());
    }
}

// Обновление информации о текущем шаблоне в интерфейсе
void UpdateCurrentTemplateInfo() {
    if (currentTemplateIndex >= 0 && currentTemplateIndex < (int)loadedTemplates.size()) {
        const auto& tmpl = loadedTemplates[currentTemplateIndex];
        SetWindowText(editTemplateName, tmpl.name.c_str());
        SetWindowText(editTemplateDescription, tmpl.description.c_str());
        DisplayTemplateParameters(currentTemplateIndex);
    }
}
