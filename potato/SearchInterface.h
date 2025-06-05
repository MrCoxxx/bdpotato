void Search(HWND hWnd)
{
	SearchCheckBox(hWnd);
	SearchButton(hWnd);
	SearchEditzone(hWnd);
}

void SearchCheckBox(HWND hWnd)
{
	checkBoxSample = CreateWindow(
		L"button",
		L"Образец",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 15, 80, 30,
		hWnd,
		(HMENU)CheckBoxSample,
		NULL,
		NULL
	);

	checkBoxOrigin = CreateWindow(
		L"button",
		L"Происхождение",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 80, 130, 30,
		hWnd,
		(HMENU)CheckBoxOrigin,
		NULL,
		NULL
	);
	
	checkBoxVIGRR = CreateWindow(
		L"button",
		L"Каталожный № ВИГРР",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 145, 170, 30,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	
	checkBoxProductivity = CreateWindow(
		L"button",
		L"Урожайность",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 200, 110, 30,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	
	checkBoxField = CreateWindow(
		L"button",
		L"Устойчивость к фитофторозу",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 265, 220, 30,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);
	
	checkBoxForm = CreateWindow(
		L"button",
		L"Форма",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 15, 70, 30,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	
	checkBoxPeel = CreateWindow(
		L"button",
		L"Окраска кожуры",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 80, 130, 30,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	
	checkBoxPulp = CreateWindow(
		L"button",
		L"Окраска мякоти",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 145, 125, 30,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	
	checkBoxEye = CreateWindow(
		L"button",
		L"Глубина глазков",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 200, 135, 30,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	
	checkBoxStolon = CreateWindow(
		L"button",
		L"Глубина столонного следа",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 265, 200, 30,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	
	checkBoxTaste = CreateWindow(
		L"button",
		L"Вкус",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 15, 55, 30,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	
	checkBoxConsistency = CreateWindow(
		L"button",
		L"Консистенция",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 80, 110, 30,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	
	checkBoxDarkening = CreateWindow(
		L"button",
		L"Потемнение после варки",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 145, 185, 30,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	
	checkBoxWeight = CreateWindow(
		L"button",
		L"Вес товарного клубня",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 330, 165, 30,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);

	LPCWSTR name[4] = { L"Жёлтый", L"Красный", L"Голубой", L"Чёрный"};

	editPeel = CreateWindow(
		L"button",
		name[0],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 110, 75, 20,
		hWnd,
		(HMENU)CheckBoxPeel1,
		NULL,
		NULL
	);
	editPeel1 = CreateWindow(
		L"button",
		name[1],
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 130, 75, 20,
		hWnd,
		(HMENU)CheckBoxPeel2,
		NULL,
		NULL
	);
	editPeel2 = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	editPeel3 = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
}

void SearchButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 400, 635, 30,
		hWnd,
		(HMENU)SearchClickButtonClose,
		NULL,
		NULL
	);
}

void SearchEditzone(HWND hWnd) 
{
	editSample = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 45, 220, 20,
		hWnd,
		(HMENU)CheckBoxSample,
		NULL,
		NULL
	);
	editOrigin = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 110, 220, 20,
		hWnd,
		(HMENU)CheckBoxOrigin,
		NULL,
		NULL
	);
	editVIGRR = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 175, 220, 20,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	editProductivity = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 240, 220, 20,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	editField = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 305, 220, 20,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);
	editForm = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 45, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	/*editPeel = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);*/
	editPulp = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	editEye = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 230, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	editStolon = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 295, 200, 20,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	editTaste = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 45, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	editConsistency = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 110, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	editDarkening = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 175, 185, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	editWeight = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 370, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
}

void SearchCheckbox(HWND hWnd)
{
	//Sample
	if (statsCheckBoxSample == BST_CHECKED) {
		SetWindowText(editSample, L"Ирбитский");
	}
	else if (statsCheckBoxSample == BST_UNCHECKED) {
		SetWindowText(editSample, L"");
	}
	//Origin
	if (statsCheckBoxOrigin == BST_CHECKED) {
		SetWindowText(editOrigin, L"УрФАНИЦ УрОРАН");
	}
	else if (statsCheckBoxOrigin == BST_UNCHECKED) {
		SetWindowText(editOrigin, L"");
	}
	//VIGRR
	if (statsCheckBoxVIGRR == BST_CHECKED) {
		SetWindowText(editVIGRR, L"24712");
	}
	else if (statsCheckBoxVIGRR == BST_UNCHECKED) {
		SetWindowText(editVIGRR, L"");
	}
	//Productivity
	if (statsCheckBoxProductivity == BST_CHECKED) {
		SetWindowText(editProductivity, L"2.36");
	}
	else if (statsCheckBoxProductivity == BST_UNCHECKED) {
		SetWindowText(editProductivity, L"");
	}
	//Field
	if (statsCheckBoxField == BST_CHECKED) {
		SetWindowText(editField, L"3");
	}
	else if (statsCheckBoxField == BST_UNCHECKED) {
		SetWindowText(editField, L"");
	}
	//Form
	if (statsCheckBoxForm == BST_CHECKED) {
		SetWindowText(editForm, L"Округлый");
	}
	else if (statsCheckBoxForm == BST_UNCHECKED) {
		SetWindowText(editForm, L"");
	}
	//Peel
	//if (statsCheckBoxPeel == BST_CHECKED) {
	//	SetWindowText(editPeel, L"Красная");
	//}
	//else if (statsCheckBoxPeel == BST_UNCHECKED) {
	//	SetWindowText(editPeel, L"");
	//}
	if (statsCheckBoxPeel1 == BST_CHECKED) {
		SetWindowText(editPeel2, L"Жёлтая");
	}
	else if (statsCheckBoxPeel1 == BST_UNCHECKED) {
		SetWindowText(editPeel2, L"");
	}
	if (statsCheckBoxPeel2 == BST_CHECKED) {
		SetWindowText(editPeel3, L"Красная");
	}
	else if (statsCheckBoxPeel2 == BST_UNCHECKED) {
		SetWindowText(editPeel3, L"");
	}
	//Pulp
	if (statsCheckBoxPulp == BST_CHECKED) {
		SetWindowText(editPulp, L"Светло-жёлтая");
	}
	else if (statsCheckBoxPulp == BST_UNCHECKED) {
		SetWindowText(editPulp, L"");
	}
	//Eye
	if (statsCheckBoxEye == BST_CHECKED) {
		SetWindowText(editEye, L"Мелкие до средних");
	}
	else if (statsCheckBoxEye == BST_UNCHECKED) {
		SetWindowText(editEye, L"");
	}
	//Stolon
	if (statsCheckBoxStolon == BST_CHECKED) {
		SetWindowText(editStolon, L"Мелкая");
	}
	else if (statsCheckBoxStolon == BST_UNCHECKED) {
		SetWindowText(editStolon, L"");
	}
	//Taste
	if (statsCheckBoxTaste == BST_CHECKED) {
		SetWindowText(editTaste, L"Хороший");
	}
	else if (statsCheckBoxTaste == BST_UNCHECKED) {
		SetWindowText(editTaste, L"");
	}
	//Consistency
	if (statsCheckBoxConsistency == BST_CHECKED) {
		SetWindowText(editConsistency, L"Плотная");
	}
	else if (statsCheckBoxConsistency == BST_UNCHECKED) {
		SetWindowText(editConsistency, L"");
	}
	//Darkening
	if (statsCheckBoxDarkening == BST_CHECKED) {
		SetWindowText(editDarkening, L"Среднее");
	}
	else if (statsCheckBoxDarkening == BST_UNCHECKED) {
		SetWindowText(editDarkening, L"");
	}
	//Weight
	if (statsCheckBoxWeight == BST_CHECKED) {
		SetWindowText(editWeight, L"146");
	}
	else if (statsCheckBoxWeight == BST_UNCHECKED) {
		SetWindowText(editWeight, L"");
	}
}