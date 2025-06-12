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
			460, 240, 680, 485,
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
			statsCheckBoxSample = SendMessage(checkBoxSample, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxOrigin:
			statsCheckBoxOrigin = SendMessage(checkBoxOrigin, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxVIGRR:
			statsCheckBoxVIGRR = SendMessage(checkBoxVIGRR, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxProductivity:
			statsCheckBoxProductivity = SendMessage(checkBoxProductivity, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxField:
			statsCheckBoxField = SendMessage(checkBoxField, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxForm:
			statsCheckBoxForm = SendMessage(checkBoxForm, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxPeel:
			statsCheckBoxPeel = SendMessage(checkBoxPeel, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			
			break;
		/*case CheckBoxPeel1:
			statsCheckBoxPeel1 = SendMessage(editPeel, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxPeel2:
			statsCheckBoxPeel2 = SendMessage(editPeel1, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;*/
		case CheckBoxPulp:
			statsCheckBoxPulp = SendMessage(checkBoxPulp, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxEye:
			statsCheckBoxEye = SendMessage(checkBoxEye, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxStolon:
			statsCheckBoxStolon = SendMessage(checkBoxStolon, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxTaste:
			statsCheckBoxTaste = SendMessage(checkBoxTaste, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxConsistency:
			statsCheckBoxConsistency = SendMessage(checkBoxConsistency, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxDarkening:
			statsCheckBoxDarkening = SendMessage(checkBoxDarkening, BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxWeight:
			statsCheckBoxWeight = SendMessage(checkBoxWeight, BM_GETCHECK, 0, 0);
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