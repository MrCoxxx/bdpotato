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

void WndTest(HWND hWnd, const WindowData& data)
{
	if (testWnd == FALSE) {
		// Создаем копию данных в куче (они должны существовать после выхода из функции)
		WindowData* pData = new WindowData(data);

		hTestWnd = CreateWindow(
			L"TestWndClass",
			data.title,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 230, data.itemCount * 40 + 25,
			hWnd, NULL, hInstance, pData  // Передаем данные как параметр создания
		);
		testWnd = TRUE;
	}
}

LRESULT CALLBACK SoftwareTestProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	WindowData* data = nullptr;

	if (msg == WM_CREATE) {
		// Получаем данные из параметров создания
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lp;
		data = (WindowData*)pCreate->lpCreateParams;
		// Сохраняем в GWLP_USERDATA для последующего использования
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)data);
	}
	else {
		// Для других сообщений получаем данные из GWLP_USERDATA
		data = (WindowData*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	}

	switch (msg)
	{
	case WM_CREATE:
		if (data) {
			Test(hWnd, data->items, data->itemCount);
		}
		break;
	case WM_COMMAND:
		switch (wp) {

		case MAKEWPARAM(TestPeel, BN_CLICKED):			
			TestT(hWnd, data->itemCount, data->editWnd);
			testWnd = FALSE;
		}
		break;
		
	case WM_DESTROY:
		DestroyWindow(hWnd);
		// Освобождаем память, выделенную для данных
		//delete data;
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

std::wstring GetSelectedFilters(int count) {
	std::wstring result;
	for (int i = 0; i < count; i++) {
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

void TestT(HWND hWnd, int count, static HWND editWnd) {
	std::wstring selectedFilters = GetSelectedFilters(count);
	DestroyWindow(hWnd);
	SetWindowText(editWnd, selectedFilters.c_str());
}

void Test(HWND hWnd, LPCWSTR* nameC, int count)
{
	int posT = 15;

	for (int i = 0; i < count; i++) {
		nameT[i] = CreateWindow(
			L"button",
			nameC[i],
			WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
			15, posT, 200, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);

		hEditFilters[i] = CreateWindow(
			L"EDIT",
			nameC[i],
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