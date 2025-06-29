

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
		case CheckBoxCommercial:
			statsCheckBoxCommercial = SendMessage(checkBoxP[3], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxNon_marketable:
			statsCheckBoxNon_marketable = SendMessage(checkBoxP[4], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxCommercial_tuber:
			statsCheckBoxCommercial_tuber = SendMessage(checkBoxP[5], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxNon_commercial_tuber:
			statsCheckBoxNon_commercial_tuber = SendMessage(checkBoxP[6], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxTubers:
			statsCheckBoxTubers = SendMessage(checkBoxP[7], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxMarketability:
			statsCheckBoxMarketability = SendMessage(checkBoxP[8], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;
		case CheckBoxProductivity:
			statsCheckBoxProductivity = SendMessage(checkBoxP[9], BM_GETCHECK, 0, 0);
			SearchCheckbox(hWnd);
			break;



		case CheckBoxForm:
			statsCheckBoxForm = SendMessage(checkBoxM[0], BM_GETCHECK, 0, 0);
			if (statsCheckBoxForm == BST_CHECKED) {
				WindowData formData = { nameF, 7, L"Форма", EditZoneM[0]};
				WndTest(hWnd, formData);
			}
			else if (statsCheckBoxForm == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			break;
		case CheckBoxPeel:
			statsCheckBoxPeel = SendMessage(checkBoxM[1], BM_GETCHECK, 0, 0);
			if (statsCheckBoxPeel == BST_CHECKED) {
				WindowData peelData = { nameP, 9, L"Окраска кожуры", EditZoneM[1] };
				WndTest(hWnd, peelData);
			}
			else if (statsCheckBoxPeel == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			break;
		case CheckBoxPulp:
			statsCheckBoxPulp = SendMessage(checkBoxM[2], BM_GETCHECK, 0, 0);
			if (statsCheckBoxPulp == BST_CHECKED) {
				WindowData pulpData = { namePu, 9, L"Окраска мякоти", EditZoneM[2] };
				WndTest(hWnd, pulpData);
			}
			else if (statsCheckBoxPulp == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			break;
		case CheckBoxEye:
			statsCheckBoxEye = SendMessage(checkBoxM[3], BM_GETCHECK, 0, 0);
			if (statsCheckBoxEye == BST_CHECKED) {
				WindowData eyeData = { nameE, 5, L"Глубина глазков", EditZoneM[3] };
				WndTest(hWnd, eyeData);
			}
			else if (statsCheckBoxEye == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			break;
		case CheckBoxStolon:
			statsCheckBoxStolon = SendMessage(checkBoxM[4], BM_GETCHECK, 0, 0);
			if (statsCheckBoxStolon == BST_CHECKED) {
				WindowData stolonData = { nameS, 5, L"Глубина столонного следа", EditZoneM[4] };
				WndTest(hWnd, stolonData);
			}
			else if (statsCheckBoxStolon == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
			break;
		case CheckBoxSkin:
			statsCheckBoxSkin = SendMessage(checkBoxM[5], BM_GETCHECK, 0, 0);
			if (statsCheckBoxSkin == BST_CHECKED) {
				WindowData skinData = { nameTu, 3, L"Поверхность кожуры клубня", EditZoneM[5] };
				WndTest(hWnd, skinData);
			}
			else if (statsCheckBoxSkin == BST_UNCHECKED) {
				DestroyWindow(hTestWnd);
				testWnd = FALSE;
			}
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