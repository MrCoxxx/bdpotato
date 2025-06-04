WNDCLASS NewTestWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWCT = { 0 };

	NWCT.hbrBackground = BGColor;
	NWCT.hCursor = Cursor;
	NWCT.hInstance = hInst;
	NWCT.hIcon = Icon;
	NWCT.lpszClassName = Name;
	NWCT.lpfnWndProc = Procedure;

	return NWCT;
}

void WndTest(HWND hWnd)
{
	if (testWnd == FALSE) {
		HWND hTestWnd = CreateWindow(
			L"TestWndClass",
			L"Добавить данные",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 680, 485,
			hWnd, NULL, hInstance, NULL
		);
		testWnd = TRUE;
	}
}

LRESULT CALLBACK SoftwareTestProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		//Test(hWnd);
		break;
	case WM_COMMAND:
		switch (wp) {

			break;
		case WM_DESTROY:
			DestroyWindow(hWnd);
			testWnd = FALSE;
			break;
		default:
			return DefWindowProc(hWnd, msg, wp, lp);
		}
		return 0;
	}
}

void Test(HWND hWnd)
{

	//LPCWSTR name = L"Белый";
	editPeel = CreateWindow(
		L"button",
		L"Белый",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 110, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

}