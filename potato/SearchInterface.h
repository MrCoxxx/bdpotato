void Search(HWND hWnd)
{
	SearchCheckBox(hWnd);
	SearchButton(hWnd);
	SearchEditzone(hWnd);
}


void SearchButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"�����",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 665, 250, 30,
		hWnd,
		(HMENU)SearchClickButtonClose,
		NULL,
		NULL
	);
}

void SearchCheckBox(HWND hWnd)
{
	int p = 15;

	//������������ ����� ����� ������
	//int m = 15;
	//int c = 15;
	//int s = 15;	

	for (int i = 0; i < 10; i++) {
		checkBoxP[i] = CreateWindow(
			L"button",
			checkBoxNameP[i],
			WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX | BS_MULTILINE,
			15, p, 250, 30,
			hWnd,
			CheckBox[0][i],
			NULL,
			NULL
		);
		p += 65;
	}


	//hToolTip = CreateToolTipForControl(checkBoxP[1], hSearchWnd, L"��� �������� ���������");

	//������������ ����� ����� ������
	//for (int i = 0; i < 6; i++) {
	//	checkBoxM[i] = CreateWindow(
	//		L"button",
	//		checkBoxNameM[i],
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX | BS_MULTILINE,
	//		280, m, 250, 30,
	//		hWnd,
	//		CheckBox[1][i],
	//		NULL,
	//		NULL
	//	);
	//	m += 65;
	//}
	//
	//for (int i = 0; i < 8; i++) {
	//	checkBoxC[i] = CreateWindow(
	//		L"button",
	//		checkBoxNameC[i],
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX | BS_MULTILINE,
	//		545, c, 250, 30,
	//		hWnd,
	//		CheckBox[2][i],
	//		NULL,
	//		NULL
	//	);
	//	c += 65;
	//}
	//
	//for (int i = 0; i < 5; i++) {
	//	checkBoxS[i] = CreateWindow( 
	//		L"button",
	//		checkBoxNameS[i],
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX | BS_MULTILINE,
	//		810, s, 250, 30,
	//		hWnd,
	//		CheckBox[3][i],
	//		NULL,
	//		NULL
	//	);
	//	s += 65;
	//}
}

void SearchEditzone(HWND hWnd) 
{
	testPeel1 = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	int j = 3;
	int p = 45;

	//������������ ����� ����� ������
	//int m = 45;
	//int c = 45;
	//int s = 45;
	

	for (int i = 0; i < 3; i++) {
		
		EditZonePS[i] = CreateWindow(
			L"edit",
			L"",
			WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE | WS_VSCROLL | WS_BORDER,
			15, p, 220, 20,
			hWnd,
			CheckBox[0][i],
			NULL,
			NULL
		);
		p += 65;
		SendMessage(EditZonePS[i], EM_SETLIMITTEXT, 0, 0);  // ������� ����������� �� ����� ������
	}

	for (int i = 0; i < 7; i++) {

		EditZonePL[i] = CreateWindow(
			L"edit",
			L"",
			WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
			15, p, 50, 20,
			hWnd,
			CheckBox[0][j],
			NULL,
			NULL
		);

		EditZonePR[i] = CreateWindow(
			L"edit",
			L"",
			WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
			115, p, 50, 20,
			hWnd,
			CheckBox[0][j],
			NULL,
			NULL
		);

		hStaticTextTable = CreateWindow(
			L"static",
			L"-",
			WS_VISIBLE | WS_CHILD | ES_CENTER,
			65, p, 50, 20,
			hWnd,
			NULL,
			NULL,
			NULL
		);

		p += 65;
		j++;
	}
	//������������ ����� ����� ������
	//for (int i = 0; i < 6; i++) {
	//
	//	EditZoneM[i] = CreateWindow(
	//		L"edit",
	//		L"",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
	//		280, m, 220, 20,
	//		hWnd,
	//		CheckBox[1][i],
	//		NULL,
	//		NULL
	//	);
	//	m += 65;
	//}

	//������������ ����� ����� ������
	//for (int i = 0; i < 8; i++) {
	//
	//	EditZoneCL[i] = CreateWindow(
	//		L"edit",
	//		L"",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
	//		545, c, 50, 20,
	//		hWnd,
	//		CheckBox[2][i],
	//		NULL,
	//		NULL
	//	);
	//
	//	EditZoneCR[i] = CreateWindow(
	//		L"edit",
	//		L"",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
	//		645, c, 50, 20,
	//		hWnd,
	//		CheckBox[2][i],
	//		NULL,
	//		NULL
	//	);
	//
	//	hStaticTextTable = CreateWindow(
	//		L"static",
	//		L"-",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER,
	//		595, c, 50, 20,
	//		hWnd,
	//		NULL,
	//		NULL,
	//		NULL
	//	);
	//
	//	c += 65;
	//}
	
	//������������ ����� ����� ������
	//for (int i = 0; i < 5; i++) {
	//
	//	EditZoneSL[i] = CreateWindow(
	//		L"edit",
	//		L"",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
	//		810, s, 50, 20,
	//		hWnd,
	//		CheckBox[3][i],
	//		NULL,
	//		NULL
	//	);
	//
	//	EditZoneSR[i] = CreateWindow(
	//		L"edit",
	//		L"",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER,
	//		910, s, 50, 20,
	//		hWnd,
	//		CheckBox[3][i],
	//		NULL,
	//		NULL
	//	);
	//
	//	hStaticTextTable = CreateWindow(
	//		L"static",
	//		L"-",
	//		WS_VISIBLE | WS_CHILD | ES_CENTER,
	//		860, s, 50, 20,
	//		hWnd,
	//		NULL,
	//		NULL,
	//		NULL
	//	);
	//
	//	s += 65;
	//}
}


void SearchCheckbox(HWND hWnd)
{
	//Sample
	if (statsCheckBoxSample == BST_CHECKED) {
		SetWindowText(EditZonePS[0], L"������");
	}
	else if (statsCheckBoxSample == BST_UNCHECKED) {
		SetWindowText(EditZonePS[0], L"");
	}
	//VIGRR
	if (statsCheckBoxVIGRR == BST_CHECKED) {
		SetWindowText(EditZonePS[1], L"��� ������");
	}
	else if (statsCheckBoxVIGRR == BST_UNCHECKED) {
		SetWindowText(EditZonePS[1], L"");
	}
	//Origin
	if (statsCheckBoxOrigin == BST_CHECKED) {
		SetWindowText(EditZonePS[2], L"��������");
	}
	else if (statsCheckBoxOrigin == BST_UNCHECKED) {
		SetWindowText(EditZonePS[2], L"");
	}
}