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
			460, 240, 230, data.itemCount * 40 + 45,
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
	case WM_SIZE:
		if (data) {
			// Получаем новые размеры клиентской области
			RECT rcClient;
			GetClientRect(hWnd, &rcClient);
			int width = rcClient.right - rcClient.left;
			int height = rcClient.bottom - rcClient.top;

			// Вызываем функцию для изменения положения элементов
			AdjustControlsLayout(hWnd, data->itemCount, width, height);
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
				result += L" ";
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

	complite1 = CreateWindow(
		L"button",
		L"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, posT, 180, 30,
		hWnd,
		(HMENU)TestPeel,
		NULL,
		NULL
	);
}

void AdjustControlsLayout(HWND hWnd, int count, int windowWidth, int windowHeight)
{
	// Рассчитываем позиции элементов
	int buttonWidth = windowWidth - 30; // Ширина с отступами по 15 пикселей
	int checkboxWidth = buttonWidth - 10;

	int itemHeight = max(20, (windowHeight - 45) / count); // Равномерное распределение по высоте
	int posY = 15;

	for (int i = 0; i < count; i++) {
		// Изменяем положение и размер чекбокса
		SetWindowPos(nameT[i], NULL,
			15, posY,
			checkboxWidth, 20,
			SWP_NOZORDER);

		posY += itemHeight;
	}

	//Позиционируем кнопку "Поиск"
	if (complite1) {
		SetWindowPos(complite1, NULL,
			15, posY,
			buttonWidth, 30,
			SWP_NOZORDER);
	}
}