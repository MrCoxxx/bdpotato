WNDCLASS NewAddWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWCA = { 0 };

	NWCA.hbrBackground = BGColor;
	NWCA.hCursor = Cursor;
	NWCA.hInstance = hInst;
	NWCA.hIcon = Icon;
	NWCA.lpszClassName = Name;
	NWCA.lpfnWndProc = Procedure;

	return NWCA;
}

void WndAdd(HWND hWnd)
{
	if (addWnd == FALSE) {
		HWND hAddWnd = CreateWindow(
			L"AddWndClass",
			L"Добавить данные",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 280, 745,
			hWnd, NULL, hInstance, NULL
		);
		addWnd = TRUE;
	}
}

LRESULT CALLBACK SoftwareAddProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		Add(hWnd);
		break;
	case WM_COMMAND:
		switch (wp) {
		case AddClickButton:
			AddData();
			DestroyWindow(hWnd);
			addWnd = FALSE;
			break;
		}

		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		addWnd = FALSE;
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}