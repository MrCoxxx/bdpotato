
using json = nlohmann::json;

// -----------------------------
// Вспомогательные конверсии
// -----------------------------
inline std::string WToU8(const std::wstring& s) {
    if (s.empty()) return {};
    int sz = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0, nullptr, nullptr);
    std::string r(sz, 0);
    WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), r.data(), sz, nullptr, nullptr);
    return r;
}

inline std::wstring U8ToW(const std::string& s) {
    if (s.empty()) return {};
    int sz = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0);
    std::wstring r(sz, 0);
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), r.data(), sz);
    return r;
}

inline std::wstring GetCurrentDateTimeW() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    wchar_t buffer[32];
    swprintf_s(buffer, 32, L"%04d-%02d-%02dT%02d:%02d:%02d",
        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return buffer;
}

inline std::wstring GetCurrentDateW() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    wchar_t buffer[32];
    swprintf_s(buffer, 32, L"%04d-%02d-%02d", st.wYear, st.wMonth, st.wDay);
    return buffer;
}

// -----------------------------
// Модель шаблона для интерфейса
// -----------------------------

// -----------------------------
// Глобальные элементы UI
// -----------------------------
inline HWND g_hEditTemplateName = nullptr;
inline HWND g_hEditTemplateDescription = nullptr;
inline HWND g_hComboMethod = nullptr;
inline HWND g_hComboTemplates = nullptr;
inline HWND g_hListWeights = nullptr;
inline HWND g_hEditTraitName = nullptr;
inline HWND g_hEditTraitWeight = nullptr;
inline HWND g_hEditResult = nullptr;

inline HWND g_btnCreate = nullptr;
inline HWND g_btnEdit = nullptr;
inline HWND g_btnDelete = nullptr;
inline HWND g_btnSave = nullptr;
inline HWND g_btnLoad = nullptr;
inline HWND g_btnCompare = nullptr;
inline HWND g_btnClear = nullptr;
inline HWND g_btnAddTrait = nullptr;
inline HWND g_btnRemoveTrait = nullptr;



// -----------------------------
// JSON: сохранение/загрузка
// Формат совместим с вашим Sample.json:
// {
//   "Столовый стандарт": {
//      "description": "...",
//      "method": "WSM",
//      "weights": { "Вкус": 0.4, ... }
//   }
// }
// -----------------------------
inline bool SaveTemplatesToFile(const std::string& filename) {
    json data = json::object();

    for (const auto& t : g_templates) {
        json item;
        item["description"] = WToU8(t.description);
        item["method"] = t.method;
        item["weights"] = json::object();

        for (const auto& [trait, weight] : t.weights) {
            item["weights"][trait] = weight;
        }

        data[WToU8(t.name)] = item;
    }

    std::ofstream out(filename, std::ios::binary);
    if (!out.is_open()) return false;

    out << data.dump(4);
    return true;
}

inline bool LoadTemplatesFromFile(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in.is_open()) return false;

    json data;
    try {
        in >> data;
    }
    catch (...) {
        return false;
    }

    if (!data.is_object()) return false;

    std::vector<UiTemplate> loaded;

    for (auto& [name, item] : data.items()) {
        UiTemplate t;
        t.name = U8ToW(name);

        if (item.contains("description") && item["description"].is_string())
            t.description = U8ToW(item["description"].get<std::string>());

        if (item.contains("method") && item["method"].is_string())
            t.method = item["method"].get<std::string>();

        if (item.contains("weights") && item["weights"].is_object()) {
            for (auto& [traitName, weightVal] : item["weights"].items()) {
                if (weightVal.is_number()) {
                    t.weights[traitName] = weightVal.get<double>();
                }
            }
        }

        loaded.push_back(t);
    }

    g_templates = std::move(loaded);
    return true;
}

// -----------------------------
// Работа с ListView
// -----------------------------
inline void InitWeightsListView(HWND hListView) {
    const wchar_t* headers[] = { L"Признак", L"Вес" };
    int widths[] = { 320, 120 };

    LVCOLUMN col{};
    col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;

    for (int i = 0; i < 2; ++i) {
        col.iSubItem = i;
        col.pszText = const_cast<wchar_t*>(headers[i]);
        col.cx = widths[i];
        ListView_InsertColumn(hListView, i, &col);
    }
}

inline std::wstring GetListViewText(HWND hListView, int item, int subItem) {
    wchar_t buffer[512]{};
    ListView_GetItemText(hListView, item, subItem, buffer, 512);
    return buffer;
}

inline void RefreshTemplatesCombo() {
    SendMessageW(g_hComboTemplates, CB_RESETCONTENT, 0, 0);

    for (const auto& t : g_templates) {
        SendMessageW(g_hComboTemplates, CB_ADDSTRING, 0, (LPARAM)t.name.c_str());
    }

    if (!g_templates.empty()) {
        SendMessageW(g_hComboTemplates, CB_SETCURSEL, 0, 0);
        g_currentTemplateIndex = 0;
    }
    else {
        g_currentTemplateIndex = -1;
    }
}

inline void RefreshWeightsList() {
    ListView_DeleteAllItems(g_hListWeights);

    if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size())
        return;

    const auto& tmpl = g_templates[g_currentTemplateIndex];

    int row = 0;
    for (const auto& [trait, weight] : tmpl.weights) {
        LVITEM item{};
        item.mask = LVIF_TEXT;
        item.iItem = row;
        item.iSubItem = 0;

        std::wstring traitW = U8ToW(trait);
        std::wstring weightW = U8ToW(std::to_string(weight));

        item.pszText = const_cast<wchar_t*>(traitW.c_str());
        ListView_InsertItem(g_hListWeights, &item);
        ListView_SetItemText(g_hListWeights, row, 1, const_cast<wchar_t*>(weightW.c_str()));
        ++row;
    }
}

inline void FillControlsFromCurrentTemplate() {
    if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size()) {
        SetWindowTextW(g_hEditTemplateName, L"");
        SetWindowTextW(g_hEditTemplateDescription, L"");
        SetWindowTextW(g_hEditTraitName, L"");
        SetWindowTextW(g_hEditTraitWeight, L"");
        ListView_DeleteAllItems(g_hListWeights);
        return;
    }

    const auto& t = g_templates[g_currentTemplateIndex];
    SetWindowTextW(g_hEditTemplateName, t.name.c_str());
    SetWindowTextW(g_hEditTemplateDescription, t.description.c_str());

    int idx = (t.method == "Harrington") ? 1 : 0;
    SendMessageW(g_hComboMethod, CB_SETCURSEL, idx, 0);

    RefreshWeightsList();
}

inline UiTemplate ReadCurrentTemplateFromControls() {
    UiTemplate t;

    wchar_t buffer[1024]{};

    GetWindowTextW(g_hEditTemplateName, buffer, 1024);
    t.name = buffer;

    GetWindowTextW(g_hEditTemplateDescription, buffer, 1024);
    t.description = buffer;

    int methodIndex = (int)SendMessageW(g_hComboMethod, CB_GETCURSEL, 0, 0);
    t.method = (methodIndex == 1) ? "Harrington" : "WSM";

    // Считываем веса из ListView
    int count = ListView_GetItemCount(g_hListWeights);
    for (int i = 0; i < count; ++i) {
        std::wstring traitW = GetListViewText(g_hListWeights, i, 0);
        std::wstring weightW = GetListViewText(g_hListWeights, i, 1);

        if (traitW.empty() || weightW.empty()) continue;

        double weight = 0.0;
        try {
            weight = std::stod(weightW);
        }
        catch (...) {
            continue;
        }

        t.weights[WToU8(traitW)] = weight;
    }

    return t;
}

inline void SaveCurrentTemplateToVector() {
    UiTemplate t = ReadCurrentTemplateFromControls();

    if (t.name.empty()) return;

    if (g_currentTemplateIndex >= 0 && g_currentTemplateIndex < (int)g_templates.size()) {
        g_templates[g_currentTemplateIndex] = t;
    }
    else {
        g_templates.push_back(t);
        g_currentTemplateIndex = (int)g_templates.size() - 1;
    }

    RefreshTemplatesCombo();
    SendMessageW(g_hComboTemplates, CB_SETCURSEL, g_currentTemplateIndex, 0);
}

inline void CreateNewTemplate() {
    UiTemplate t;
    t.name = L"Новый шаблон";
    t.description = L"";
    t.method = "WSM";

    g_templates.push_back(t);
    g_currentTemplateIndex = (int)g_templates.size() - 1;

    RefreshTemplatesCombo();
    SendMessageW(g_hComboTemplates, CB_SETCURSEL, g_currentTemplateIndex, 0);
    FillControlsFromCurrentTemplate();
}

inline void DeleteCurrentTemplate() {
    if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size())
        return;

    g_templates.erase(g_templates.begin() + g_currentTemplateIndex);

    if (g_templates.empty()) g_currentTemplateIndex = -1;
    else if (g_currentTemplateIndex >= (int)g_templates.size()) g_currentTemplateIndex = (int)g_templates.size() - 1;

    RefreshTemplatesCombo();
    FillControlsFromCurrentTemplate();
}

inline void ClearCurrentTemplateUI() {
    SetWindowTextW(g_hEditTemplateName, L"");
    SetWindowTextW(g_hEditTemplateDescription, L"");
    SetWindowTextW(g_hEditTraitName, L"");
    SetWindowTextW(g_hEditTraitWeight, L"");
    ListView_DeleteAllItems(g_hListWeights);
}

// -----------------------------
// Добавление / удаление признака
// -----------------------------
inline void AddOrUpdateTrait() {
    if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size())
        return;

    wchar_t traitBuf[256]{};
    wchar_t weightBuf[256]{};

    GetWindowTextW(g_hEditTraitName, traitBuf, 256);
    GetWindowTextW(g_hEditTraitWeight, weightBuf, 256);

    std::wstring traitW = traitBuf;
    std::wstring weightW = weightBuf;

    if (traitW.empty() || weightW.empty()) return;

    int rowCount = ListView_GetItemCount(g_hListWeights);
    int foundRow = -1;

    for (int i = 0; i < rowCount; ++i) {
        if (GetListViewText(g_hListWeights, i, 0) == traitW) {
            foundRow = i;
            break;
        }
    }

    if (foundRow >= 0) {
        ListView_SetItemText(g_hListWeights, foundRow, 1, const_cast<wchar_t*>(weightW.c_str()));
    }
    else {
        LVITEM item{};
        item.mask = LVIF_TEXT;
        item.iItem = rowCount;
        item.iSubItem = 0;
        item.pszText = const_cast<wchar_t*>(traitW.c_str());
        ListView_InsertItem(g_hListWeights, &item);
        ListView_SetItemText(g_hListWeights, rowCount, 1, const_cast<wchar_t*>(weightW.c_str()));
    }

    // Обновим текущий шаблон из UI
    g_templates[g_currentTemplateIndex] = ReadCurrentTemplateFromControls();
    FillControlsFromCurrentTemplate();
}

inline void RemoveSelectedTrait() {
    if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size())
        return;

    int selected = ListView_GetNextItem(g_hListWeights, -1, LVNI_SELECTED);
    if (selected < 0) return;

    ListView_DeleteItem(g_hListWeights, selected);
    g_templates[g_currentTemplateIndex] = ReadCurrentTemplateFromControls();
    FillControlsFromCurrentTemplate();
}

// -----------------------------
// Источник данных из БД
// Берём данные из GetSample() и сопоставляем признаки с колонками
// -----------------------------
inline std::unordered_map<std::string, std::unordered_map<std::string, double>>
BuildDBDataForTemplate(const std::unordered_map<std::string, double>& weights) {

    std::vector<std::wstring> headers = {
        L"Образец", L"№ по каталогу ВИГРР", L"Происхождение",
        L"Товарных клубней в клоне, шт.", L"Нетоварных клубней в клоне, шт.",
        L"Масса товарного клубня, г", L"Масса нетоварного клубня, г",
        L"Клубней в клоне, шт", L"Товарность", L"Урожайность",
        L"Форма клубня", L"Окраска кожуры", L"Окраска мякоти",
        L"Глубина глазков", L"Глубина столонного следа",
        L"Поверхность кожуры клубня", L"Разваримость клубней",
        L"Консистенция мякоти", L"Рассыпчатость", L"Водянистость клубней",
        L"Запах варёного картофеля", L"Вкус",
        L"Потемнение мякоти сырого картофеля", L"Потемнение мякоти варёного картофеля"
    };

    std::vector<std::wstring> selectedTraitsW;
    for (const auto& [trait, weight] : weights) {
        selectedTraitsW.push_back(U8ToW(trait));
    }

    std::vector<int> traitColumns;
    for (const auto& trait : selectedTraitsW) {
        for (int j = 0; j < (int)headers.size(); ++j) {
            if (headers[j] == trait) {
                traitColumns.push_back(j);
                break;
            }
        }
    }

    std::unordered_map<std::string, std::unordered_map<std::string, double>> DataBD;
    std::vector<std::vector<std::wstring>> sample = GetSample();

    for (int i = 0; i < (int)sample.size(); ++i) {
        if (sample[i].empty()) continue;

        std::string objectName = WToU8(sample[i][0]);
        std::unordered_map<std::string, double> currentData;

        for (int j = 0; j < (int)traitColumns.size(); ++j) {
            int colIndex = traitColumns[j];
            if (colIndex < 0 || colIndex >= (int)sample[i].size()) continue;

            std::wstring wideValue = sample[i][colIndex];
            if (wideValue.empty()) continue;

            std::string raw = WToU8(wideValue);

            try {
                double value = std::stod(raw);
                std::string traitName = WToU8(selectedTraitsW[j]);
                currentData[traitName] = value;
            }
            catch (...) {
                continue;
            }
        }

        if (!currentData.empty()) {
            DataBD[objectName] = currentData;
        }
    }

    return DataBD;
}

// -----------------------------
// Расчёт и вывод результата в окно
// -----------------------------
inline std::wstring GenerateComparisonReport(const UiTemplate& tmpl) {
    std::wostringstream report;

    if (tmpl.weights.empty()) {
        report << L"Шаблон не содержит признаков.\r\n";
        return report.str();
    }

    auto dbData = BuildDBDataForTemplate(tmpl.weights);

    // Здесь предполагается, что в проекте уже есть Variety и Trait
    std::vector<Variety> varieties;
    for (const auto& [name, traitsMap] : dbData) {
        Variety v(name);
        for (const auto& [traitName, traitValue] : traitsMap) {
            v.setTrait(traitName, traitValue);
        }
        varieties.push_back(v);
    }

    auto traitsDict = initTraits();

    EvaluationMethod method = (tmpl.method == "Harrington")
        ? EvaluationMethod::Harrington
        : EvaluationMethod::WSM;

    ExpertTemplate pattern(WToU8(tmpl.name), WToU8(tmpl.description), method);

    for (const auto& [trait, weight] : tmpl.weights) {
        pattern.setWeight(trait, weight);
    }

    std::vector<std::pair<Variety, double>> results;
    for (auto& v : varieties) {
        double score = pattern.evaluate(v, traitsDict);
        results.push_back({ v, score });
    }

    std::sort(results.begin(), results.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    report << L"Шаблон: " << tmpl.name << L"\r\n";
    report << L"Описание: " << tmpl.description << L"\r\n";
    report << L"Метод: " << U8ToW(tmpl.method) << L"\r\n";
    report << L"Признаков: " << tmpl.weights.size() << L"\r\n\r\n";

    for (const auto& res : results) {
        if (res.second <= 0.350) continue;

        std::ostringstream tmp;
        printRadarChartToFile(tmp, res.first, pattern, traitsDict);

        report << U8ToW(tmp.str());
        report << L"\r\n" << std::wstring(60, L'=') << L"\r\n\r\n";
    }

    if (results.empty()) {
        report << L"Нет данных для сравнения.\r\n";
    }

    return report.str();
}

inline void ShowReportInUI(const std::wstring& text) {
    SetWindowTextW(g_hEditResult, text.c_str());
}

// -----------------------------
// Создание элементов интерфейса
// -----------------------------
inline void InitializeTemplateInterface(HWND hWnd) {
    InitCommonControls();

    CreateWindowW(L"static", L"Название шаблона", WS_VISIBLE | WS_CHILD,
        15, 15, 180, 20, hWnd, nullptr, nullptr, nullptr);

    g_hEditTemplateName = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        15, 35, 230, 25, hWnd, nullptr, nullptr, nullptr);

    CreateWindowW(L"static", L"Описание", WS_VISIBLE | WS_CHILD,
        255, 15, 180, 20, hWnd, nullptr, nullptr, nullptr);

    g_hEditTemplateDescription = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        255, 35, 300, 25, hWnd, nullptr, nullptr, nullptr);

    CreateWindowW(L"static", L"Метод", WS_VISIBLE | WS_CHILD,
        570, 15, 100, 20, hWnd, nullptr, nullptr, nullptr);

    g_hComboMethod = CreateWindowW(L"combobox", L"", WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        570, 35, 140, 200, hWnd, nullptr, nullptr, nullptr);

    SendMessageW(g_hComboMethod, CB_ADDSTRING, 0, (LPARAM)L"WSM");
    SendMessageW(g_hComboMethod, CB_ADDSTRING, 0, (LPARAM)L"Harrington");
    SendMessageW(g_hComboMethod, CB_SETCURSEL, 0, 0);

    CreateWindowW(L"static", L"Шаблоны", WS_VISIBLE | WS_CHILD,
        15, 70, 120, 20, hWnd, nullptr, nullptr, nullptr);

    g_hComboTemplates = CreateWindowW(L"combobox", L"", WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
        15, 95, 300, 200, hWnd, (HMENU)IDC_TEMPLATE_CHANGE, nullptr, nullptr);

    g_hListWeights = CreateWindowW(WC_LISTVIEWW, L"", WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
        15, 130, 695, 180, hWnd, nullptr, nullptr, nullptr);

    InitWeightsListView(g_hListWeights);

    // Поля добавления/редактирования признака
    CreateWindowW(L"static", L"Признак", WS_VISIBLE | WS_CHILD,
        15, 320, 120, 20, hWnd, nullptr, nullptr, nullptr);

    g_hEditTraitName = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        15, 340, 300, 25, hWnd, nullptr, nullptr, nullptr);

    CreateWindowW(L"static", L"Вес", WS_VISIBLE | WS_CHILD,
        330, 320, 80, 20, hWnd, nullptr, nullptr, nullptr);

    g_hEditTraitWeight = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        330, 340, 120, 25, hWnd, nullptr, nullptr, nullptr);

    g_btnAddTrait = CreateWindowW(L"button", L"Добавить/Обновить признак", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        470, 318, 240, 28, hWnd, (HMENU)IDC_ADD_TRAIT, nullptr, nullptr);

    g_btnRemoveTrait = CreateWindowW(L"button", L"Удалить признак", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        470, 350, 240, 28, hWnd, (HMENU)IDC_REMOVE_TRAIT, nullptr, nullptr);

    // Кнопки CRUD + сравнение
    g_btnCreate = CreateWindowW(L"button", L"Создать", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        15, 390, 90, 30, hWnd, (HMENU)IDC_CREATE_TEMPLATE, nullptr, nullptr);

    g_btnEdit = CreateWindowW(L"button", L"Редактировать", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        110, 390, 110, 30, hWnd, (HMENU)IDC_EDIT_TEMPLATE, nullptr, nullptr);

    g_btnDelete = CreateWindowW(L"button", L"Удалить", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        225, 390, 90, 30, hWnd, (HMENU)IDC_DELETE_TEMPLATE, nullptr, nullptr);

    g_btnSave = CreateWindowW(L"button", L"Сохранить JSON", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        320, 390, 130, 30, hWnd, (HMENU)IDC_SAVE_TEMPLATES, nullptr, nullptr);

    g_btnLoad = CreateWindowW(L"button", L"Загрузить JSON", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        455, 390, 130, 30, hWnd, (HMENU)IDC_LOAD_TEMPLATES, nullptr, nullptr);

    g_btnCompare = CreateWindowW(L"button", L"Сравнить", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        590, 390, 120, 30, hWnd, (HMENU)IDC_COMPARE, nullptr, nullptr);

    g_btnClear = CreateWindowW(L"button", L"Очистить", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        15, 430, 90, 30, hWnd, (HMENU)IDC_CLEAR, nullptr, nullptr);

    // Окно результата
    CreateWindowW(L"static", L"Результат сравнения", WS_VISIBLE | WS_CHILD,
        15, 470, 180, 20, hWnd, nullptr, nullptr, nullptr);

    g_hEditResult = CreateWindowW(L"edit", L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_READONLY,
        15, 495, 695, 270, hWnd, nullptr, nullptr, nullptr);
}

// -----------------------------
// Обработчик выбора шаблона
// -----------------------------
inline void OnTemplateSelectionChanged() {
    int sel = (int)SendMessageW(g_hComboTemplates, CB_GETCURSEL, 0, 0);
    if (sel < 0 || sel >= (int)g_templates.size()) return;

    g_currentTemplateIndex = sel;
    FillControlsFromCurrentTemplate();
}

// -----------------------------
// Основной обработчик команд
// -----------------------------

