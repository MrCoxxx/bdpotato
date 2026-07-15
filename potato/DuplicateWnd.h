#pragma once

// ─── Глобальные переменные окна ─────────────────────────────────────────────
static HWND hDupWnd       = NULL; // само окно модуля
static BOOL dupWndOpen    = FALSE;

// Выпадающий список выбора сорта
static HWND hDupCombo     = NULL;
// Метки
static HWND hDupLblSample = NULL;
static HWND hDupLblHint   = NULL;
// Чекбоксы признаков
static HWND hDupChk[15];
// ListView с результатами
static HWND hDupList      = NULL;
// Кнопки
static HWND hDupBtnSearch = NULL;
static HWND hDupBtnClose  = NULL;
// Метка «Результаты»
static HWND hDupLblResult = NULL;

// Метки чекбоксов
static const wchar_t* dupChkLabels[15] = {
    L"Товарных клубней в клоне",
    L"Нетоварных клубней в клоне",
    L"Масса товарного клубня",
    L"Масса нетоварного клубня",
    L"Клубней в клоне",
    L"Товарность, %",
    L"Урожайность, кг/м²",
    L"Развариваемость",
    L"Консистенция мякоти",
    L"Рассыпчатость",
    L"Водянистость",
    L"Запах варёного картофеля",
    L"Вкус варёного картофеля",
    L"Потемнение мякоти сырого",
    L"Потемнение мякоти варёного",
};
static const int dupChkIds[15] = {
    DupChkCommercial, DupChkNonMarket, DupChkWeightC,  DupChkWeightN,
    DupChkTubers,     DupChkMarketability, DupChkProductivity,
    DupChkBoilability, DupChkConsistency, DupChkFriability, DupChkWateriness,
    DupChkSmell, DupChkTaste, DupChkDarkRaw, DupChkDarkBoiled,
};

// Заполнить комбобокс всеми сортами из БД
static void DupFillCombo(HWND hCombo) {
    SendMessage(hCombo, CB_RESETCONTENT, 0, 0);
    if (!db) return;

    const char* sql = "SELECT sample FROM potato ORDER BY sample";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* t = sqlite3_column_text(stmt, 0);
        if (t) {
            std::wstring name = utf8_to_utf16(reinterpret_cast<const char*>(t));
            SendMessageW(hCombo, CB_ADDSTRING, 0, (LPARAM)name.c_str());
        }
    }
    sqlite3_finalize(stmt);
    SendMessage(hCombo, CB_SETCURSEL, 0, 0);
}

// Читаем состояния чекбоксов → DupFields
static DupFields DupReadFields() {
    DupFields f;
    f.commercial_tubers  = SendMessage(hDupChk[0],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.non_marketable     = SendMessage(hDupChk[1],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.weight_commercial  = SendMessage(hDupChk[2],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.weight_non_comm    = SendMessage(hDupChk[3],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.tubers_in_clone    = SendMessage(hDupChk[4],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.marketability      = SendMessage(hDupChk[5],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.productivity       = SendMessage(hDupChk[6],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.boilability        = SendMessage(hDupChk[7],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.consistency        = SendMessage(hDupChk[8],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.friability         = SendMessage(hDupChk[9],  BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.wateriness         = SendMessage(hDupChk[10], BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.smell              = SendMessage(hDupChk[11], BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.taste              = SendMessage(hDupChk[12], BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.darkening_raw      = SendMessage(hDupChk[13], BM_GETCHECK, 0, 0) == BST_CHECKED;
    f.darkening_boiled   = SendMessage(hDupChk[14], BM_GETCHECK, 0, 0) == BST_CHECKED;
    return f;
}

// Заполнить ListView результатами
static void DupFillList(const std::vector<DupResult>& results) {
    ListView_DeleteAllItems(hDupList);
    if (results.empty()) return;

    LVITEMW lvi = {};
    lvi.mask = LVIF_TEXT;

    for (int i = 0; i < (int)results.size(); i++) {
        // Столбец 0: порядковый номер
        wchar_t num[16];
        swprintf(num, 16, L"%d", i + 1);
        lvi.iItem    = i;
        lvi.iSubItem = 0;
        lvi.pszText  = num;
        ListView_InsertItem(hDupList, &lvi);

        // Столбец 1: название сорта
        ListView_SetItemText(hDupList, i, 1,
            const_cast<wchar_t*>(results[i].name.c_str()));

        // Столбец 2: сходство %
        wchar_t sim[32];
        swprintf(sim, 32, L"%.1f%%", results[i].similarity);
        ListView_SetItemText(hDupList, i, 2, sim);

        // Столбец 3: дистанция (для справки)
        wchar_t dist[32];
        swprintf(dist, 32, L"%.4f", results[i].distance);
        ListView_SetItemText(hDupList, i, 3, dist);
    }
}

// Добавить колонки ListView (вызывается один раз при создании окна)
static void DupAddColumns(HWND hList) {
    const wchar_t* headers[] = { L"№", L"Сорт", L"Сходство, %", L"Дистанция" };
    int widths[]              = {  35,    280,       110,            90 };

    LVCOLUMNW lvc = {};
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvc.fmt  = LVCFMT_LEFT;
    for (int i = 0; i < 4; i++) {
        lvc.iSubItem = i;
        lvc.pszText  = const_cast<wchar_t*>(headers[i]);
        lvc.cx       = widths[i];
        ListView_InsertColumn(hList, i, &lvc);
    }
}

static void DupCreateControls(HWND hWnd) {
    
    // Метка + комбобокс выбора сорта
    HWND hLabel = CreateWindow(L"static", L"Выберите сорт для сравнения",
        WS_VISIBLE | WS_CHILD | ES_CENTER,
        10, 12, 400, 20, hWnd, NULL, NULL, NULL);

    hDupCombo = CreateWindow(L"COMBOBOX", L"",
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
        10, 36, 360, 220, hWnd, NULL, hInstance, NULL);
    DupFillCombo(hDupCombo);

    // Разделитель и подсказка
    hLabel = CreateWindow(L"static",
        L"Признаки для сравнения (если ни один не выбран – сравнение по всем):",
        WS_VISIBLE | WS_CHILD,
        10, 72, 540, 20, hWnd, NULL, NULL, NULL);

    // Чекбоксы (у вас уже есть массив hDupChk[15])
    int col1x = 10, col2x = 290;
    for (int i = 0; i < 15; i++) {
        int x = (i < 8) ? col1x : col2x;
        int y = 96 + ((i < 8 ? i : i - 8) * 28);
        hDupChk[i] = CreateWindow(L"button", dupChkLabels[i],
            WS_VISIBLE | WS_CHILD | BS_CHECKBOX | BS_MULTILINE,
            x, y, 265, 24, hWnd, (HMENU)(UINT_PTR)dupChkIds[i], NULL, NULL);
    }

    // Кнопка «Найти похожие»
    hDupBtnSearch = CreateWindow(L"button", L"Найти похожие",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        10, 324, 170, 30, hWnd, (HMENU)DupBtnSearch, NULL, NULL);

    // Кнопка «Закрыть»
    hDupBtnClose = CreateWindow(L"button", L"Закрыть",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        195, 324, 110, 30, hWnd, (HMENU)DupBtnClose, NULL, NULL);

    // Метка над таблицей
    hDupLblResult = CreateWindow(L"static", L"Результаты сравнения:",
        WS_VISIBLE | WS_CHILD,
        10, 364, 260, 20, hWnd, NULL, NULL, NULL);

    // ListView
    hDupList = CreateWindow(WC_LISTVIEWW, L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
        10, 388, 560, 320, hWnd, NULL, hInstance, NULL);
    ListView_SetExtendedListViewStyle(hDupList,
        LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    DupAddColumns(hDupList);
}

static void DupRunSearch() {
    // Читаем выбранный сорт из комбобокса
    int idx = (int)SendMessage(hDupCombo, CB_GETCURSEL, 0, 0);
    if (idx == CB_ERR) {
        MessageBox(hDupWnd, L"Выберите сорт из списка.", L"Внимание", MB_OK | MB_ICONWARNING);
        return;
    }
    wchar_t buf[256] = {};
    SendMessageW(hDupCombo, CB_GETLBTEXT, idx, (LPARAM)buf);
    std::wstring targetName(buf);

    // Читаем состояние чекбоксов
    DupFields fields = DupReadFields();

    // Выполняем поиск
    auto results = FindSimilar(db, targetName, fields);

    if (results.empty()) {
        MessageBox(hDupWnd,
            L"В базе данных нет других записей для сравнения.",
            L"Информация", MB_OK | MB_ICONINFORMATION);
        return;
    }

    // Отображаем результаты
    DupFillList(results);

    // Обновляем заголовок над таблицей
    wchar_t lbl[300];
    swprintf(lbl, 300,
        L"Результаты сравнения для «%s» (%d сортов, отсортировано по убыванию сходства):",
        targetName.c_str(), (int)results.size());
    SetWindowTextW(hDupLblResult, lbl);
}

LRESULT CALLBACK SoftwareDuplicateProcedure(HWND hWnd, UINT msg,
                                             WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        DupCreateControls(hWnd);
        break;

    case WM_COMMAND:
    {
        WORD id = LOWORD(wp);

        // Переключение чекбоксов
        for (int i = 0; i < 15; i++) {
            if (id == (WORD)dupChkIds[i]) {
                LRESULT state = SendMessage(hDupChk[i], BM_GETCHECK, 0, 0);
                SendMessage(hDupChk[i], BM_SETCHECK,
                    (state == BST_CHECKED) ? BST_UNCHECKED : BST_CHECKED, 0);
                return 0;
            }
        }

        if (id == DupBtnSearch) {
            DupRunSearch();
        }
        else if (id == DupBtnClose) {
            DestroyWindow(hWnd);
        }
        break;
    }

    case WM_DESTROY:
        hDupWnd = NULL;
        dupWndOpen = FALSE;
        break;

    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

static void RegisterDuplicateWindowClass(HINSTANCE hInst) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc   = SoftwareDuplicateProcedure;
    wc.hInstance     = hInst;
    wc.lpszClassName = L"DuplicateWndClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    RegisterClassW(&wc);
}

static void WndDuplicate(HWND hParent) {
    if (dupWndOpen) {
        SetForegroundWindow(hDupWnd);
        return;
    }
    hDupWnd = CreateWindow(
        L"DuplicateWndClass",
        L"Поиск похожих сортов",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        200, 100, 596, 760,
        hParent, NULL, hInstance, NULL
    );
    dupWndOpen = TRUE;
}
