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
HWND hTestWnd;
void WndTest(HWND hWnd)
{
	if (testWnd == FALSE) {
		hTestWnd = CreateWindow(
			L"TestWndClass",
			L"Окраска кожуры",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 230, 365,
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
		Test(hWnd, name);
		break;
	case WM_COMMAND:
		switch (wp) {

		case MAKEWPARAM(TestPeel, BN_CLICKED):			
			TestT(hWnd);
		}
		break;
		
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}


std::wstring GetWindowTextT(HWND hWnd) {
	wchar_t buffer[256];
	GetWindowText(hWnd, buffer, 256);
	return std::wstring(buffer);
}

std::wstring GetSelectedFilters() {
	std::wstring result;
	for (int i = 0; i < al; i++) {
		if (SendMessage(nameT[i], BM_GETCHECK, 0, 0) == BST_CHECKED) {			
			std::wstring filterValue = GetWindowTextT(hEditFilters[i]);
			if (!result.empty()) {
				result += L",";
			}
			result += filterValue;
		}
	}
	return result;
}

void TestT(HWND hWnd) {
	std::wstring selectedFilters = GetSelectedFilters();
	DestroyWindow(hWnd);
	SetWindowText(editPeel, selectedFilters.c_str());
}

void Test(HWND hWnd, LPCWSTR *name)
{
	al = sizeof(name) + 1;

	int posT = 15;	
	
	//275
	for (int i = 0; i < al; i++) {
		nameT[i] = CreateWindow(
			L"button",
			name[i],
			WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
			15, posT, 200, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);

		hEditFilters[i] = CreateWindow(
			L"EDIT",
			name[i],
			WS_CHILD | ES_LEFT,
			170, posT, 200, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);
		posT += 30;
	}
	
	complite = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, posT, 180, 30,
		hWnd,
		(HMENU)TestPeel,
		NULL,
		NULL
	);

}