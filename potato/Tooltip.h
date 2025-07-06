void ShowError(const wchar_t* message) {
    MessageBoxW(NULL, message, L"Ошибка", MB_ICONERROR);
}
HWND CreateToolTipForControl(HWND hwndControl, HWND hwndParent, const wchar_t* pszText, HWND hToolTip) {
    // Уничтожаем старый ToolTip (если есть)
    if (hToolTip && IsWindow(hToolTip)) {
        DestroyWindow(hToolTip);
        hToolTip = NULL;
    }

    // Создаем новый ToolTip
    hToolTip = CreateWindowExW(
        WS_EX_TOPMOST,
        TOOLTIPS_CLASSW,
        NULL,
        WS_POPUP | TTS_ALWAYSTIP | TTS_NOPREFIX | TTS_BALLOON,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        hwndParent,
        NULL,
        GetModuleHandleW(NULL),
        NULL
    );

    if (!hToolTip) {
        DWORD err = GetLastError();
        wchar_t buf[256];
        swprintf(buf, 256, L"CreateWindowEx for Tooltip failed. Error: %d", err);
        ShowError(buf);
        return NULL;
    }

    // Настройка TOOLINFO
    TOOLINFOW ti = { sizeof(ti) };
    ti.hwnd = hwndParent;
    ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    ti.uId = (UINT_PTR)hwndControl;
    ti.lpszText = (LPWSTR)pszText;

    if (!SendMessageW(hToolTip, TTM_ADDTOOLW, 0, (LPARAM)&ti)) {
        ShowError(L"TTM_ADDTOOLW failed");
        DestroyWindow(hToolTip);
        hToolTip = NULL;
        return NULL;
    }

    SendMessageW(hToolTip, TTM_SETMAXTIPWIDTH, 0, 300);
    SendMessageW(hToolTip, TTM_SETDELAYTIME, TTDT_INITIAL, 300);
    SendMessageW(hToolTip, TTM_ACTIVATE, TRUE, 0);

    return hToolTip;
}