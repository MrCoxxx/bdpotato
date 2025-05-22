void Search(HWND hWnd)
{
	SearchCheckBox(hWnd);
	SearchButton(hWnd);
}

void SearchCheckBox(HWND hWnd)
{
	checkBoxSample = CreateWindow(
		L"button",
		L"�������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 120, 150, 30,
		hWnd,
		(HMENU)Checkbox1,
		NULL,
		NULL
	);

	checkBoxOrigin = CreateWindow(
		L"button",
		L"�������������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 170, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxVIGRR = CreateWindow(
		L"button",
		L"���������� � �����",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 200, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxProductivity = CreateWindow(
		L"button",
		L"�����������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 230, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxField = CreateWindow(
		L"button",
		L"������������ � �����������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		120, 120, 150, 30,
		hWnd,
		(HMENU)Checkbox1,
		NULL,
		NULL
	);

	checkBoxForm = CreateWindow(
		L"button",
		L"�����",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		120, 170, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxPeel = CreateWindow(
		L"button",
		L"������� ������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		120, 200, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxPulp = CreateWindow(
		L"button",
		L"������� ������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		120, 230, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxEye = CreateWindow(
		L"button",
		L"������� �������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		240, 120, 150, 30,
		hWnd,
		(HMENU)Checkbox1,
		NULL,
		NULL
	);

	checkBoxStolon = CreateWindow(
		L"button",
		L"������� ���������� �����",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		240, 170, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxTaste = CreateWindow(
		L"button",
		L"����",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		240, 200, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxConsistency = CreateWindow(
		L"button",
		L"������������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		240, 230, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	checkBoxDarkening = CreateWindow(
		L"button",
		L"���������� ����� �����",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		360, 120, 150, 30,
		hWnd,
		(HMENU)Checkbox1,
		NULL,
		NULL
	);

	checkBoxWeight = CreateWindow(
		L"button",
		L"��� ��������� ������",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		360, 170, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

}

void SearchButton(HWND hWnd)
{

	complite = new Widgets(
		"button",
		"�����",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 90, 240, 30,
		hWnd,
		(HMENU)SearchClickButtonClose,
		NULL,
		NULL
	);

	/*min = new Widgets(
		"button",
		"min",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 150, 50, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	avg = new Widgets(
		"button",
		"avg",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		65, 150, 50, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	max = new Widgets(
		"button",
		"max",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		115, 150, 50, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);*/
	editSample = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		165, 150, 100, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void SearchCheckbox(HWND hWnd) 
{
	//Sample
	if (statsCheckBoxSample == BST_CHECKED) {
		SetWindowText((HWND)editSample, L"������");
	}
	if (statsCheckBoxSample == BST_UNCHECKED) {
		SetWindowText((HWND)editSample, L"");
	}
	//Origin
	if (statsCheckBoxOrigin == BST_CHECKED) {
		SetWindowText((HWND)editOrigin, L"������");
	}
	if (statsCheckBoxOrigin == BST_UNCHECKED) {
		SetWindowText((HWND)editOrigin, L"");
	}
	//VIGRR
	if (statsCheckBoxVIGRR == BST_CHECKED) {
		SetWindowText((HWND)editVIGRR, L"������");
	}
	if (statsCheckBoxVIGRR == BST_UNCHECKED) {
		SetWindowText((HWND)editVIGRR, L"");
	}
	//Productivity
	if (statsCheckBoxProductivity == BST_CHECKED) {
		SetWindowText((HWND)editProductivity, L"������");
	}
	if (statsCheckBoxProductivity == BST_UNCHECKED) {
		SetWindowText((HWND)editProductivity, L"");
	}
	//Field
	if (statsCheckBoxField == BST_CHECKED) {
		SetWindowText((HWND)editField, L"������");
	}
	if (statsCheckBoxField == BST_UNCHECKED) {
		SetWindowText((HWND)editField, L"");
	}
	//Form
	if (statsCheckBoxForm == BST_CHECKED) {
		SetWindowText((HWND)editForm, L"������");
	}
	if (statsCheckBoxForm == BST_UNCHECKED) {
		SetWindowText((HWND)editForm, L"");
	}
	//Peel
	if (statsCheckBoxPeel == BST_CHECKED) {
		SetWindowText((HWND)editPeel, L"������");
	}
	if (statsCheckBoxPeel == BST_UNCHECKED) {
		SetWindowText((HWND)editPeel, L"");
	}
	//Pulp
	if (statsCheckBoxPulp == BST_CHECKED) {
		SetWindowText((HWND)editPulp, L"������");
	}
	if (statsCheckBoxPulp == BST_UNCHECKED) {
		SetWindowText((HWND)editPulp, L"");
	}
	//Eye
	if (statsCheckBoxEye == BST_CHECKED) {
		SetWindowText((HWND)editEye, L"������");
	}
	if (statsCheckBoxEye == BST_UNCHECKED) {
		SetWindowText((HWND)editEye, L"");
	}
	//Stolon
	if (statsCheckBoxStolon == BST_CHECKED) {
		SetWindowText((HWND)editStolon, L"������");
	}
	if (statsCheckBoxStolon == BST_UNCHECKED) {
		SetWindowText((HWND)editStolon, L"");
	}
	//Taste
	if (statsCheckBoxTaste == BST_CHECKED) {
		SetWindowText((HWND)editTaste, L"������");
	}
	if (statsCheckBoxTaste == BST_UNCHECKED) {
		SetWindowText((HWND)editTaste, L"");
	}
	//Consistency
	if (statsCheckBoxConsistency == BST_CHECKED) {
		SetWindowText((HWND)editConsistency, L"������");
	}
	if (statsCheckBoxConsistency == BST_UNCHECKED) {
		SetWindowText((HWND)editConsistency, L"");
	}
	//Darkening
	if (statsCheckBoxDarkening == BST_CHECKED) {
		SetWindowText((HWND)editDarkening, L"������");
	}
	if (statsCheckBoxDarkening == BST_UNCHECKED) {
		SetWindowText((HWND)editDarkening, L"");
	}
	//Weight
	if (statsCheckBoxWeight == BST_CHECKED) {
		SetWindowText((HWND)editWeight, L"������");
	}
	if (statsCheckBoxWeight == BST_UNCHECKED) {
		SetWindowText((HWND)editWeight, L"");
	}
}