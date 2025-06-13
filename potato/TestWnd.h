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

HWND hEditFilters[9];
static HWND nameT[9];
LPCWSTR name[9] = { L"белая", L"Светло-жёлтая", L"жёлтая", L"Жёлто-коричневая", L"Розовая", L"Красная", L"Красно-фиолетовая", L"Сине-фиолетовая", L"Тёмно-фиолетовая" };
bool isChecked[9] = { false };
static LRESULT statsCheckPeel[9];
LRESULT CALLBACK SoftwareTestProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		Test(hWnd);
		break;
	case WM_COMMAND:
		switch (wp) {

		case MAKEWPARAM(TestPeel, BN_CLICKED):
			for (int i = 0; i < 9; i++) {
				statsCheckPeel[i] = SendMessage(nameT[i], BM_GETCHECK, 0, 0);
			}
			
			TestT(hWnd);
		}
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



/*void TestS(HWND hWnd) {
	if ((LRESULT)nameT[0] == BST_CHECKED) {
		SetWindowText(hEditFilters[0], L"Белая");
	}
	else{
		SetWindowText(hEditFilters[0], L"");
	}
	if ((LRESULT)nameT[1] == BST_CHECKED) {
		SetWindowText(hEditFilters[1], L"Светло-жёлтая");
	}
	else {
		SetWindowText(hEditFilters[1], L"");
	}
	if ((LRESULT)nameT[2] == BST_CHECKED) {
		SetWindowText(hEditFilters[2], L"Жёлтая");
	}
	else {
		SetWindowText(hEditFilters[2], L"");
	}
	if ((LRESULT)nameT[3] == BST_CHECKED) {
		SetWindowText(hEditFilters[3], L"Жёлто-коричневая");
	}
	else {
		SetWindowText(hEditFilters[3], L"");
	}
	if ((LRESULT)nameT[4] == BST_CHECKED) {
		SetWindowText(hEditFilters[4], L"Розовая");
	}
	else {
		SetWindowText(hEditFilters[4], L"");
	}
	if ((LRESULT)nameT[5] == BST_CHECKED) {
		SetWindowText(hEditFilters[5], L"Красная");
	}
	else {
		SetWindowText(hEditFilters[5], L"");
	}
	if ((LRESULT)nameT[6] == BST_CHECKED) {
		SetWindowText(hEditFilters[6], L"Красно-фиолетовая");
	}
	else {
		SetWindowText(hEditFilters[6], L"");
	}
	if ((LRESULT)nameT[7] == BST_CHECKED) {
		SetWindowText(hEditFilters[7], L"Сине-фиолетовая");
	}
	else {
		SetWindowText(hEditFilters[7], L"");
	}
	if ((LRESULT)nameT[8] == BST_CHECKED) {
		SetWindowText(hEditFilters[8], L"Тёмно-фиолетовая");
	}
	else {
		SetWindowText(hEditFilters[8], L"");
	}
}*/

void TestT(HWND hWnd) {
	std::wstring selectedFilters = GetSelectedFilters();
	DestroyWindow(hWnd);
	SetWindowText(editPeel, selectedFilters.c_str());
	
}

std::wstring GetWindowText1(HWND hWnd) {
	wchar_t buffer[256];
	GetWindowText(hWnd, buffer, 256);
	return std::wstring(buffer);
}

std::wstring GetSelectedFilters() {
	std::wstring result;
	for (int i = 0; i < 9; i++) {
		if (SendMessage(nameT[i], BM_GETCHECK, 0, 0) == BST_CHECKED) {			
			std::wstring filterValue = GetWindowText1(hEditFilters[i]);
			if (!result.empty()) {
				result += L", ";
			}
			result += filterValue;
		}
	}
	return result;
}

void Test(HWND hWnd)
{
	int posT[9]{ 15,45,75,105,135,165,195,225,255 };
	
	

	for (int i = 0; i < 9; i++) {
		nameT[i] = CreateWindow(
			L"button",
			name[i],
			WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
			15, posT[i], 200, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);

		hEditFilters[i] = CreateWindow(
			L"EDIT",
			name[i],
			WS_CHILD | ES_LEFT,
			170, posT[i], 200, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);

	}
	
	complite = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 275, 180, 30,
		hWnd,
		(HMENU)TestPeel,
		NULL,
		NULL
	);

}






/*nameT[0] = CreateWindow(
		L"button",
		name[0],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 15, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[1] = CreateWindow(
		L"button",
		name[1],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 45, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[2] = CreateWindow(
		L"button",
		name[2],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 75, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[3] = CreateWindow(
		L"button",
		name[3],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 105, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[4] = CreateWindow(
		L"button",
		name[4],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 135, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[5] = CreateWindow(
		L"button",
		name[5],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 165, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[6] = CreateWindow(
		L"button",
		name[6],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 195, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[7] = CreateWindow(
		L"button",
		name[7],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 225, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	nameT[8] = CreateWindow(
		L"button",
		name[8],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 255, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);*/