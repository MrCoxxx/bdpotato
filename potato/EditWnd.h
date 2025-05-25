WNDCLASS NewEditWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWCE = { 0 };

	NWCE.hbrBackground = BGColor;
	NWCE.hCursor = Cursor;
	NWCE.hInstance = hInst;
	NWCE.hIcon = Icon;
	NWCE.lpszClassName = Name;
	NWCE.lpfnWndProc = Procedure;

	return NWCE;
}

void WndEdit(HWND hWnd)
{
	if (editWnd == FALSE) {
		HWND hAddWnd = CreateWindow(
			L"EditWndClass",
			L"������������� ������",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 680, 485,
			hWnd, NULL, hInstance, NULL
		);
		editWnd = TRUE;
	}
}

LRESULT CALLBACK SoftwareEditProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (wp) {


		}

		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		editWnd = FALSE;
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}