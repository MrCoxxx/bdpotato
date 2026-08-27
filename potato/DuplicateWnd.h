#pragma once
#include "DuplicateSearch.h"

// ─── Новые команды (добавь в SoftwareDefinitions.h) ─────────────────────────
#define MenuDuplicate        64
#define DupBtnSearch         65
#define DupBtnClose          66
#define DupChkCommercial     70
#define DupChkNonMarket      71
#define DupChkWeightC        72
#define DupChkWeightN        73
#define DupChkTubers         74
#define DupChkMarketability  75
#define DupChkProductivity   76
#define DupChkBoilability    77
#define DupChkConsistency    78
#define DupChkFriability     79
#define DupChkWateriness     80
#define DupChkSmell          81
#define DupChkTaste          82
#define DupChkDarkRaw        83
#define DupChkDarkBoiled     84

// ─── Глобальные переменные окна ─────────────────────────────────────────────
static HWND hDupWnd = NULL;
static BOOL dupWndOpen = FALSE;
static HWND hDupCombo = NULL;
static HWND hDupLblSample = NULL;
static HWND hDupLblHint = NULL;
static HWND hDupChk[15] = {};
static HWND hDupList = NULL;
static HWND hDupBtnSearch = NULL;
static HWND hDupBtnClose = NULL;
static HWND hDupLblResult = NULL;

// ─── Метки чекбоксов (wide-литералы — русский текст всегда корректен) ────────
static const wchar_t* dupChkLabels[15] = {
    L"\u0422\u043e\u0432\u0430\u0440\u043d\u044b\u0445 \u043a\u043b\u0443\u0431\u043d\u0435\u0439 \u0432 \u043a\u043b\u043e\u043d\u0435",
    L"\u041d\u0435\u0442\u043e\u0432\u0430\u0440\u043d\u044b\u0445 \u043a\u043b\u0443\u0431\u043d\u0435\u0439 \u0432 \u043a\u043b\u043e\u043d\u0435",
    L"\u041c\u0430\u0441\u0441\u0430 \u0442\u043e\u0432\u0430\u0440\u043d\u043e\u0433\u043e \u043a\u043b\u0443\u0431\u043d\u044f",
    L"\u041c\u0430\u0441\u0441\u0430 \u043d\u0435\u0442\u043e\u0432\u0430\u0440\u043d\u043e\u0433\u043e \u043a\u043b\u0443\u0431\u043d\u044f",
    L"\u041a\u043b\u0443\u0431\u043d\u0435\u0439 \u0432 \u043a\u043b\u043e\u043d\u0435",
    L"\u0422\u043e\u0432\u0430\u0440\u043d\u043e\u0441\u0442\u044c, %",
    L"\u0423\u0440\u043e\u0436\u0430\u0439\u043d\u043e\u0441\u0442\u044c, \u043a\u0433/\u043c\u00b2",
    L"\u0420\u0430\u0437\u0432\u0430\u0440\u0438\u0432\u0430\u0435\u043c\u043e\u0441\u0442\u044c",
    L"\u041a\u043e\u043d\u0441\u0438\u0441\u0442\u0435\u043d\u0446\u0438\u044f \u043c\u044f\u043a\u043e\u0442\u0438",
    L"\u0420\u0430\u0441\u0441\u044b\u043f\u0447\u0430\u0442\u043e\u0441\u0442\u044c",
    L"\u0412\u043e\u0434\u044f\u043d\u0438\u0441\u0442\u043e\u0441\u0442\u044c",
    L"\u0417\u0430\u043f\u0430\u0445 \u0432\u0430\u0440\u0451\u043d\u043e\u0433\u043e \u043a\u0430\u0440\u0442\u043e\u0444\u0435\u043b\u044f",
    L"\u0412\u043a\u0443\u0441 \u0432\u0430\u0440\u0451\u043d\u043e\u0433\u043e \u043a\u0430\u0440\u0442\u043e\u0444\u0435\u043b\u044f",
    L"\u041f\u043e\u0442\u0435\u043c\u043d\u0435\u043d\u0438\u0435 \u043c\u044f\u043a\u043e\u0442\u0438 \u0441\u044b\u0440\u043e\u0433\u043e",
    L"\u041f\u043e\u0442\u0435\u043c\u043d\u0435\u043d\u0438\u0435 \u043c\u044f\u043a\u043e\u0442\u0438 \u0432\u0430\u0440\u0451\u043d\u043e\u0433\u043e",
};

static const int dupChkIds[15] = {
    DupChkCommercial, DupChkNonMarket, DupChkWeightC,      DupChkWeightN,
    DupChkTubers,     DupChkMarketability, DupChkProductivity,
    DupChkBoilability, DupChkConsistency, DupChkFriability, DupChkWateriness,
    DupChkSmell,      DupChkTaste,     DupChkDarkRaw,      DupChkDarkBoiled,
};

// ─────────────────────────────────────────────────────────────────────────────
//  Заполнить комбобокс сортами из БД
// ─────────────────────────────────────────────────────────────────────────────
static void DupFillCombo(HWND hCombo)
{
    SendMessageW(hCombo, CB_RESETCONTENT, 0, 0);
    if (!db) return;

    const char* sql = "SELECT sample FROM potato ORDER BY sample";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char* t = sqlite3_column_text(stmt, 0);
        if (t)
        {
            std::wstring name = utf8_to_utf16(reinterpret_cast<const char*>(t));
            SendMessageW(hCombo, CB_ADDSTRING, 0, (LPARAM)name.c_str());
        }
    }
    sqlite3_finalize(stmt);
    SendMessageW(hCombo, CB_SETCURSEL, 0, 0);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Читаем состояния чекбоксов
// ─────────────────────────────────────────────────────────────────────────────
static DupFields DupReadFields()
{
    DupFields f;
    for (int i = 0; i < 15; i++)
    {
        bool checked = (SendMessageW(hDupChk[i], BM_GETCHECK, 0, 0) == BST_CHECKED);
        switch (i)
        {
        case  0: f.commercial_tubers = checked; break;
        case  1: f.non_marketable = checked; break;
        case  2: f.weight_commercial = checked; break;
        case  3: f.weight_non_comm = checked; break;
        case  4: f.tubers_in_clone = checked; break;
        case  5: f.marketability = checked; break;
        case  6: f.productivity = checked; break;
        case  7: f.boilability = checked; break;
        case  8: f.consistency = checked; break;
        case  9: f.friability = checked; break;
        case 10: f.wateriness = checked; break;
        case 11: f.smell = checked; break;
        case 12: f.taste = checked; break;
        case 13: f.darkening_raw = checked; break;
        case 14: f.darkening_boiled = checked; break;
        }
    }
    return f;
}

// ─────────────────────────────────────────────────────────────────────────────
//  Колонки ListView
// ─────────────────────────────────────────────────────────────────────────────
static void DupAddColumns(HWND hList)
{
    // №  Сорт  Сходство, %  Дистанция
    const wchar_t* hdrs[] = {
        L"\u2116",
        L"\u0421\u043e\u0440\u0442",
        L"\u0421\u0445\u043e\u0434\u0441\u0442\u0432\u043e, %",
        L"\u0414\u0438\u0441\u0442\u0430\u043d\u0446\u0438\u044f"
    };
    int widths[] = { 36, 280, 110, 90 };

    LVCOLUMNW lvc = {};
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvc.fmt = LVCFMT_LEFT;
    for (int i = 0; i < 4; i++)
    {
        lvc.iSubItem = i;
        lvc.pszText = const_cast<wchar_t*>(hdrs[i]);
        lvc.cx = widths[i];
        ListView_InsertColumn(hList, i, &lvc);
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  Заполнить ListView результатами
// ─────────────────────────────────────────────────────────────────────────────
static void DupFillList(const std::vector<DupResult>& results)
{
    ListView_DeleteAllItems(hDupList);
    if (results.empty()) return;

    LVITEMW lvi = {};
    lvi.mask = LVIF_TEXT;

    for (int i = 0; i < (int)results.size(); i++)
    {
        wchar_t num[16];
        swprintf_s(num, L"%d", i + 1);
        lvi.iItem = i;
        lvi.iSubItem = 0;
        lvi.pszText = num;
        ListView_InsertItem(hDupList, &lvi);

        ListView_SetItemText(hDupList, i, 1,
            const_cast<wchar_t*>(results[i].name.c_str()));

        wchar_t sim[32];
        swprintf_s(sim, L"%.1f%%", results[i].similarity);
        ListView_SetItemText(hDupList, i, 2, sim);

        wchar_t dist[32];
        swprintf_s(dist, L"%.4f", results[i].distance);
        ListView_SetItemText(hDupList, i, 3, dist);
    }
}

// ─────────────────────────────────────────────────────────────────────────────
//  Создание всех элементов управления (всё через CreateWindowW)
// ─────────────────────────────────────────────────────────────────────────────
static void DupCreateControls(HWND hWnd)
{
    // Метка «Выберите сорт»
    CreateWindowW(L"static",
        L"\u0412\u044b\u0431\u0435\u0440\u0438\u0442\u0435 "
        L"\u0441\u043e\u0440\u0442 \u0434\u043b\u044f "
        L"\u0441\u0440\u0430\u0432\u043d\u0435\u043d\u0438\u044f:",
        WS_VISIBLE | WS_CHILD,
        10, 12, 400, 20,
        hWnd, NULL, hInstance, NULL);

    // Комбобокс
    hDupCombo = CreateWindowW(L"COMBOBOX", L"",
        WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
        10, 36, 360, 220,
        hWnd, NULL, hInstance, NULL);
    DupFillCombo(hDupCombo);

    // Подсказка про признаки
    CreateWindowW(L"static",
        L"\u041f\u0440\u0438\u0437\u043d\u0430\u043a\u0438 "
        L"\u0434\u043b\u044f \u0441\u0440\u0430\u0432\u043d\u0435\u043d\u0438\u044f "
        L"(\u0435\u0441\u043b\u0438 \u043d\u0438 \u043e\u0434\u0438\u043d \u043d\u0435 "
        L"\u0432\u044b\u0431\u0440\u0430\u043d \u2013 "
        L"\u0441\u0440\u0430\u0432\u043d\u0435\u043d\u0438\u0435 \u043f\u043e "
        L"\u0432\u0441\u0435\u043c):",
        WS_VISIBLE | WS_CHILD,
        10, 72, 560, 20,
        hWnd, NULL, hInstance, NULL);

    // 15 чекбоксов, два столбца
    for (int i = 0; i < 15; i++)
    {
        int x = (i < 8) ? 10 : 290;
        int y = 96 + ((i < 8 ? i : i - 8) * 28);
        hDupChk[i] = CreateWindowW(
            L"button",
            dupChkLabels[i],
            WS_VISIBLE | WS_CHILD | BS_CHECKBOX | BS_MULTILINE,
            x, y, 265, 24,
            hWnd,
            (HMENU)(UINT_PTR)dupChkIds[i],
            hInstance, NULL);
    }

    // Кнопка «Найти похожие»
    hDupBtnSearch = CreateWindowW(L"button",
        L"\u041d\u0430\u0439\u0442\u0438 "
        L"\u043f\u043e\u0445\u043e\u0436\u0438\u0435",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        10, 324, 170, 30,
        hWnd, (HMENU)DupBtnSearch, hInstance, NULL);

    // Кнопка «Закрыть»
    hDupBtnClose = CreateWindowW(L"button",
        L"\u0417\u0430\u043a\u0440\u044b\u0442\u044c",
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        195, 324, 110, 30,
        hWnd, (HMENU)DupBtnClose, hInstance, NULL);

    // Метка над таблицей
    hDupLblResult = CreateWindowW(L"static",
        L"\u0420\u0435\u0437\u0443\u043b\u044c\u0442\u0430\u0442\u044b "
        L"\u0441\u0440\u0430\u0432\u043d\u0435\u043d\u0438\u044f:",
        WS_VISIBLE | WS_CHILD,
        10, 364, 560, 20,
        hWnd, NULL, hInstance, NULL);

    // ListView
    hDupList = CreateWindowW(WC_LISTVIEWW, L"",
        WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
        10, 388, 560, 320,
        hWnd, NULL, hInstance, NULL);
    ListView_SetExtendedListViewStyle(hDupList,
        LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    DupAddColumns(hDupList);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Выполнить поиск
// ─────────────────────────────────────────────────────────────────────────────
static void DupRunSearch()
{
    int idx = (int)SendMessageW(hDupCombo, CB_GETCURSEL, 0, 0);
    if (idx == CB_ERR)
    {
        MessageBoxW(hDupWnd,
            L"\u0412\u044b\u0431\u0435\u0440\u0438\u0442\u0435 "
            L"\u0441\u043e\u0440\u0442 \u0438\u0437 \u0441\u043f\u0438\u0441\u043a\u0430.",
            L"\u0412\u043d\u0438\u043c\u0430\u043d\u0438\u0435",
            MB_OK | MB_ICONWARNING);
        return;
    }

    wchar_t buf[256] = {};
    SendMessageW(hDupCombo, CB_GETLBTEXT, idx, (LPARAM)buf);
    std::wstring targetName(buf);

    DupFields fields = DupReadFields();
    auto results = FindSimilar(db, targetName, fields);

    if (results.empty())
    {
        MessageBoxW(hDupWnd,
            L"\u0412 \u0431\u0430\u0437\u0435 \u0434\u0430\u043d\u043d\u044b\u0445 "
            L"\u043d\u0435\u0442 \u0434\u0440\u0443\u0433\u0438\u0445 "
            L"\u0437\u0430\u043f\u0438\u0441\u0435\u0439 "
            L"\u0434\u043b\u044f \u0441\u0440\u0430\u0432\u043d\u0435\u043d\u0438\u044f.",
            L"\u0418\u043d\u0444\u043e\u0440\u043c\u0430\u0446\u0438\u044f",
            MB_OK | MB_ICONINFORMATION);
        return;
    }

    DupFillList(results);

    wchar_t lbl[400];
    swprintf_s(lbl, 400,
        L"\u0420\u0435\u0437\u0443\u043b\u044c\u0442\u0430\u0442\u044b "
        L"\u0434\u043b\u044f \u00ab%s\u00bb "
        L"(%d \u0441\u043e\u0440\u0442\u043e\u0432, "
        L"\u043e\u0442\u0441\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u0430\u043d\u043e "
        L"\u043f\u043e \u0443\u0431\u044b\u0432\u0430\u043d\u0438\u044e "
        L"\u0441\u0445\u043e\u0434\u0441\u0442\u0432\u0430):",
        targetName.c_str(), (int)results.size());
    SetWindowTextW(hDupLblResult, lbl);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Оконная процедура
// ─────────────────────────────────────────────────────────────────────────────
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
        for (int i = 0; i < 15; i++)
        {
            if (id == (WORD)dupChkIds[i])
            {
                LRESULT state = SendMessageW(hDupChk[i], BM_GETCHECK, 0, 0);
                SendMessageW(hDupChk[i], BM_SETCHECK,
                    (state == BST_CHECKED) ? BST_UNCHECKED : BST_CHECKED, 0);
                return 0;
            }
        }

        if (id == DupBtnSearch) DupRunSearch();
        else if (id == DupBtnClose)  DestroyWindow(hWnd);
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

// ─────────────────────────────────────────────────────────────────────────────
//  Регистрация класса (вызвать один раз в WinMain)
// ─────────────────────────────────────────────────────────────────────────────
static void RegisterDuplicateWindowClass(HINSTANCE hInst)
{
    WNDCLASSW wc = {};
    wc.lpfnWndProc = SoftwareDuplicateProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = L"DuplicateWndClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    RegisterClassW(&wc);
}

// ─────────────────────────────────────────────────────────────────────────────
//  Открытие окна (вызвать из обработчика MenuDuplicate)
// ─────────────────────────────────────────────────────────────────────────────
static void WndDuplicate(HWND hParent)
{
    if (dupWndOpen) { SetForegroundWindow(hDupWnd); return; }

    hDupWnd = CreateWindowW(
        L"DuplicateWndClass",
        L"\u041f\u043e\u0438\u0441\u043a "
        L"\u043f\u043e\u0445\u043e\u0436\u0438\u0445 "
        L"\u0441\u043e\u0440\u0442\u043e\u0432",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        200, 100, 596, 760,
        hParent, NULL, hInstance, NULL);

    dupWndOpen = TRUE;
}