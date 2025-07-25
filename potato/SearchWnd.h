

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
		hSearchWnd = CreateWindow(
			L"SearchWndClass",
			L"�����",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			460, 240, 300, 750,
			NULL, NULL, hInstance, NULL
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
		SearchMenu(hWnd);
		// ������������� ������� ����
		break;
	case WM_MOUSEHOVER: {
		for (int i = 0; i < 10; i++) {
			if ((HWND)wp == checkBoxP[0] && hToolTip[i]) {
				MSG relayMsg = { hWnd, WM_MOUSEMOVE, 0, lp };
				SendMessageW(hToolTip[i], TTM_RELAYEVENT, 0, (LPARAM)&relayMsg);
			}
			TrackMouseEvent(&tme); // ���������� ������������
		}
		break;
	}
	case WM_COMMAND:
		switch (wp) {
		case Help:
			for (int i = 0; i < 10; i++) {
				if (!hToolTip[i]) {
					hToolTip[i] = CreateToolTipForControl(checkBoxP[i], hSearchWnd, helpText[i], hToolTip[i]);
				}
				else {
					DestroyWindow(hToolTip[i]);
					hToolTip[i] = NULL;
				}
				
			}
			
			//hToolTip = CreateToolTipForControl(checkBoxP[1], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[2], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[3], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[4], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[5], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[6], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[7], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[8], hSearchWnd, L"��� �������� ���������");
			//hToolTip = CreateToolTipForControl(checkBoxP[9], hSearchWnd, L"��� �������� ���������");

			// ��������� ������������ ����
			tme.hwndTrack = checkBoxP[0];
			tme.dwFlags = TME_HOVER | TME_LEAVE;
			tme.dwHoverTime = 300;
			TrackMouseEvent(&tme);
			break;		
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


		//������������ ����� ����� ������
		//case CheckBoxForm:
		//	statsCheckBoxForm = SendMessage(checkBoxM[0], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxForm == BST_CHECKED) {
		//		WindowData formData = { nameF, 7, L"�����", EditZoneM[0]};
		//		WndTest(hWnd, formData);
		//	}
		//	else if (statsCheckBoxForm == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//case CheckBoxPeel:
		//	statsCheckBoxPeel = SendMessage(checkBoxM[1], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxPeel == BST_CHECKED) {
		//		WindowData peelData = { nameP, 9, L"������� ������", EditZoneM[1] };
		//		WndTest(hWnd, peelData);
		//	}
		//	else if (statsCheckBoxPeel == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//case CheckBoxPulp:
		//	statsCheckBoxPulp = SendMessage(checkBoxM[2], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxPulp == BST_CHECKED) {
		//		WindowData pulpData = { namePu, 9, L"������� ������", EditZoneM[2] };
		//		WndTest(hWnd, pulpData);
		//	}
		//	else if (statsCheckBoxPulp == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//case CheckBoxEye:
		//	statsCheckBoxEye = SendMessage(checkBoxM[3], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxEye == BST_CHECKED) {
		//		WindowData eyeData = { nameE, 5, L"������� �������", EditZoneM[3] };
		//		WndTest(hWnd, eyeData);
		//	}
		//	else if (statsCheckBoxEye == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//case CheckBoxStolon:
		//	statsCheckBoxStolon = SendMessage(checkBoxM[4], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxStolon == BST_CHECKED) {
		//		WindowData stolonData = { nameS, 5, L"������� ���������� �����", EditZoneM[4] };
		//		WndTest(hWnd, stolonData);
		//	}
		//	else if (statsCheckBoxStolon == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//case CheckBoxSkin:
		//	statsCheckBoxSkin = SendMessage(checkBoxM[5], BM_GETCHECK, 0, 0);
		//	if (statsCheckBoxSkin == BST_CHECKED) {
		//		WindowData skinData = { nameTu, 3, L"����������� ������ ������", EditZoneM[5] };
		//		WndTest(hWnd, skinData);
		//	}
		//	else if (statsCheckBoxSkin == BST_UNCHECKED) {
		//		DestroyWindow(hTestWnd);
		//		testWnd = FALSE;
		//	}
		//	break;
		//
		//
		//
		//case CheckBoxBoilability:
		//	statsCheckBoxBoilability = SendMessage(checkBoxC[0], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxConsistency:
		//	statsCheckBoxConsistency = SendMessage(checkBoxC[1], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxFriability:
		//	statsCheckBoxFriability = SendMessage(checkBoxC[2], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxWateriness:
		//	statsCheckBoxWateriness = SendMessage(checkBoxC[3], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxSmell:
		//	statsCheckBoxSmell = SendMessage(checkBoxC[4], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxTaste:
		//	statsCheckBoxTaste = SendMessage(checkBoxC[5], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxDarkening_raw:
		//	statsCheckBoxDarkening_raw = SendMessage(checkBoxC[6], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxDarkening_boiled:
		//	statsCheckBoxDarkening_boiled = SendMessage(checkBoxC[7], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//
		//
		//
		//case CheckBoxField:
		//	statsCheckBoxField = SendMessage(checkBoxS[0], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxAbility:
		//	statsCheckBoxAbility = SendMessage(checkBoxS[1], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxFlowering:
		//	statsCheckBoxFlowering = SendMessage(checkBoxS[2], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxRipeness:
		//	statsCheckBoxRipeness = SendMessage(checkBoxS[3], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;
		//case CheckBoxYield:
		//	statsCheckBoxYield = SendMessage(checkBoxS[4], BM_GETCHECK, 0, 0);
		//	SearchCheckbox(hWnd);
		//	break;



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
		//if (hToolTip && IsWindow(hToolTip)) {
		//	DestroyWindow(hToolTip);
		//	hToolTip = NULL;
		//}
		secondWnd = FALSE;
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
	return 0;
}