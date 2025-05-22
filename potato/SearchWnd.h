WNDCLASS NewSearchWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWCS = { 0 };

	NWCS.hbrBackground = BGColor;
	NWCS.hCursor = Cursor;
	NWCS.hInstance = hInst;
	NWCS.hIcon = Icon;
	NWCS.lpszClassName = Name;
	NWCS.lpfnWndProc = Procedure;

	return NWCS;
}

void WndSearch(HWND hWnd) {

	if (secondWnd == FALSE) {
		HWND hSearchWnd = CreateWindow(
			L"SearchWndClass",
			L"Второе окно",
			WS_OVERLAPPEDWINDOW,
			460, 240, 300, 200,
			hWnd, NULL, hInstance, NULL
		);
		if (hSearchWnd) {
			ShowWindow(hSearchWnd, SW_SHOW);
			UpdateWindow(hSearchWnd);
			secondWnd = TRUE;
		}

	}
}

LRESULT CALLBACK SoftwareSearchProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		Search(hWnd);
		// Инициализация второго окна
		break;
	case WM_COMMAND:
		switch (wp) {

		}
		break;

	case WM_DESTROY:
		DestroyWindow(hWnd);
		secondWnd = FALSE;
		// Не вызываем PostQuitMessage, так как это не главное окно
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}