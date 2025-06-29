

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

void WndSearch(HWND hWnd) 
{
	if (secondWnd == FALSE) {
		HWND hSearchWnd = CreateWindow(
			L"SearchWndClass",
			L"Поиск",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 1060, 750,
			hWnd, NULL, hInstance, NULL
		);
		secondWnd = TRUE;
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
		
		case CheckBoxSample:
			statsCheckBoxSample = SendMessage(checkBoxP[0], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;

		case CheckBoxVIGRR:
			statsCheckBoxVIGRR = SendMessage(checkBoxP[1], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;

		case CheckBoxOrigin:
			statsCheckBoxOrigin = SendMessage(checkBoxP[2], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case SearchClickButtonClose:

			HWND hMainWnd = FindWindow(L"MainWndClass", NULL);
			DestroyDataTable(hWnd);
			LoadRequestData(hMainWnd);
			DestroyCheckBox(hWnd);
			DestroyWindow(hWnd);
		
			secondWnd = FALSE;
			break;
		}

		break;
	case WM_DESTROY:
		DestroyCheckBox(hWnd);
		DestroyWindow(hWnd);
		secondWnd = FALSE;
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}