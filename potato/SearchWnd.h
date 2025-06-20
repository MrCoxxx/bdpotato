

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
			460, 240, 680, 600,
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
			if (statsCheckBoxForm == BST_CHECKED) {
				WindowData formData = { nameF, 7, L"Форма", editForm };
				WndTest(hWnd, formData);
			}
			else if (statsCheckBoxForm == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxPeel:
			statsCheckBoxPeel = SendMessage(checkBoxPeel, BM_GETCHECK, 0, 0);
			if (statsCheckBoxPeel == BST_CHECKED) {
				WindowData peelData = { nameP, 9, L"Окраска кожуры", editPeel };
				WndTest(hWnd, peelData);
			}
			else if (statsCheckBoxPeel == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxPulp:
			statsCheckBoxPulp = SendMessage(checkBoxPulp, BM_GETCHECK, 0, 0);
			if (statsCheckBoxPulp == BST_CHECKED) {
				WindowData pulpData = { namePu, 9, L"Окраска мякоти", editPulp };
				WndTest(hWnd, pulpData);
			}
			else if (statsCheckBoxPulp == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxEye:
			statsCheckBoxEye = SendMessage(checkBoxEye, BM_GETCHECK, 0, 0);
			if (statsCheckBoxEye == BST_CHECKED) {
				WindowData eyeData = { nameE, 5, L"Глубина глазков", editEye };
				WndTest(hWnd, eyeData);
			}
			else if (statsCheckBoxEye == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxStolon:
			statsCheckBoxStolon = SendMessage(checkBoxStolon, BM_GETCHECK, 0, 0);
			if (statsCheckBoxStolon == BST_CHECKED) {
				WindowData stolonData = { nameS, 5, L"Глубина столонного следа", editStolon };
				WndTest(hWnd, stolonData);
			}
			else if (statsCheckBoxStolon == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxTaste:
			statsCheckBoxTaste = SendMessage(checkBoxTaste, BM_GETCHECK, 0, 0);
			if (statsCheckBoxTaste == BST_CHECKED) {
				WindowData tasteData = { nameTa, 5, L"Вкус варёного картофеля", editTaste };
				WndTest(hWnd, tasteData);
			}
			else if (statsCheckBoxTaste == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxConsistency:
			statsCheckBoxConsistency = SendMessage(checkBoxConsistency, BM_GETCHECK, 0, 0);
			if (statsCheckBoxConsistency == BST_CHECKED) {
				WindowData consistencyData = { nameC, 5, L"Консистенция мякоти", editConsistency };
				WndTest(hWnd, consistencyData);
			}
			else if (statsCheckBoxConsistency == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
			break;
		case CheckBoxDarkening:
			statsCheckBoxDarkening = SendMessage(checkBoxDarkening, BM_GETCHECK, 0, 0);
			if (statsCheckBoxDarkening == BST_CHECKED) {
				WindowData darkeningData = { nameD, 5, L"Потемнение мякоти после варки", editDarkening };
				WndTest(hWnd, darkeningData);
			}
			else if (statsCheckBoxDarkening == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			//SearchCheckbox(hWnd);
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