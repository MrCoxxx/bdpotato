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
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 500, 850, 30,
		hWnd,
		(HMENU)SearchClickButtonClose,
		NULL,
		NULL
	);
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
		L"№ по каталогу ВИГРР",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 145, 170, 30,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	
	checkBoxProductivity = CreateWindow(
		L"button",
		L"Урожайность, кг/м2",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 200, 110, 30,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	
	checkBoxField = CreateWindow(
		L"button",
		L"Масса товарного клубня, г",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 265, 220, 30,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);

	checkBoxWeight = CreateWindow(
		L"button",
		L"Полевая устойчивость к фитофторозу, балл",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 330, 165, 30,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	
	checkBoxForm = CreateWindow(
		L"button",
		L"Форма клубня",
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

	checkBoxTuber = CreateWindow(
		L"button",
		L"Поверхность кожуры клубня",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		250, 330, 200, 30,
		hWnd,
		(HMENU)CheckBoxTuber,
		NULL,
		NULL
	);
	
	checkBoxTaste = CreateWindow(
		L"button",
		L"Вкус варёного картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 15, 55, 30,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	
	checkBoxConsistency = CreateWindow(
		L"button",
		L"Консистенция мякоти",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 80, 110, 30,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	
	checkBoxDarkening = CreateWindow(
		L"button",
		L"Потемнение мякоти после варки",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 145, 185, 30,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);

	checkBoxBoil = CreateWindow(
		L"button",
		L"Разваримость клубней",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 210, 185, 30,
		hWnd,
		(HMENU)CheckBoxBoil,
		NULL,
		NULL
	);

	checkBoxFriability = CreateWindow(
		L"button",
		L"Рассыпчатость",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 275, 185, 30,
		hWnd,
		(HMENU)CheckBoxFriability,
		NULL,
		NULL
	);

	checkBoxWater = CreateWindow(
		L"button",
		L"Водянистость клубней",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 340, 185, 30,
		hWnd,
		(HMENU)CheckBoxWater,
		NULL,
		NULL
	);

	checkBoxBoiled = CreateWindow(
		L"button",
		L"Запах варёного картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		465, 405, 185, 30,
		hWnd,
		(HMENU)CheckBoxBoiled,
		NULL,
		NULL
	);

	checkBoxYield = CreateWindow(
		L"button",
		L"Урожайность, %",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 15, 55, 30,
		hWnd,
		(HMENU)CheckBoxYield,
		NULL,
		NULL
	);

	checkBoxStarch = CreateWindow(
		L"button",
		L"Содержание крахмала, %",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 80, 110, 30,
		hWnd,
		(HMENU)CheckBoxStarch,
		NULL,
		NULL
	);

	checkBoxDry = CreateWindow(
		L"button",
		L"Содержание сухого вещества, %",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 145, 185, 30,
		hWnd,
		(HMENU)CheckBoxDry,
		NULL,
		NULL
	);

	checkBoxContent = CreateWindow(
		L"button",
		L"Содержание редуцирующих сахараов. %",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 210, 185, 30,
		hWnd,
		(HMENU)CheckBoxContent,
		NULL,
		NULL
	);

	checkBoxRip = CreateWindow(
		L"button",
		L"Группа спелости",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 275, 185, 30,
		hWnd,
		(HMENU)CheckBoxRip,
		NULL,
		NULL
	);

	checkBoxAbility = CreateWindow(
		L"button",
		L"Способность к ягодообразованию от самоопыления (балл)",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 340, 185, 30,
		hWnd,
		(HMENU)CheckBoxAbility,
		NULL,
		NULL
	);

	checkBoxDuration = CreateWindow(
		L"button",
		L"Продолжительность цветения, дни",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		680, 405, 185, 30,
		hWnd,
		(HMENU)CheckBoxDuration,
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
	editWeight = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 370, 50, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editWeight1 = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		85, 370, 50, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	hStaticTextTable1 = CreateWindowA(
		"static",
		"-",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		70, 370, 10, 20,
		hWnd,
		NULL,
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
	editPeel = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
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
	editTuber = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 360, 200, 20,
		hWnd,
		(HMENU)CheckBoxTuber,
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
	editBoil = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 240, 185, 20,
		hWnd,
		(HMENU)CheckBoxBoil,
		NULL,
		NULL
	);
	editFriability = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 305, 185, 20,
		hWnd,
		(HMENU)CheckBoxFriability,
		NULL,
		NULL
	);
	editWater = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 370, 185, 20,
		hWnd,
		(HMENU)CheckBoxWater,
		NULL,
		NULL
	);
	editBoiled = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 435, 185, 20,
		hWnd,
		(HMENU)CheckBoxBoiled,
		NULL,
		NULL
	);
	editYield = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 45, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	editStarch = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 110, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	editDry = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 175, 185, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	editContent = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 240, 185, 20,
		hWnd,
		(HMENU)CheckBoxBoil,
		NULL,
		NULL
	);
	editRip = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 305, 185, 20,
		hWnd,
		(HMENU)CheckBoxFriability,
		NULL,
		NULL
	);
	editAbility = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 370, 185, 20,
		hWnd,
		(HMENU)CheckBoxWater,
		NULL,
		NULL
	);
	editDuration = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 435, 185, 20,
		hWnd,
		(HMENU)CheckBoxBoiled,
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
	//Weight
	if (statsCheckBoxWeight == BST_CHECKED) {
		SetWindowText(editWeight, L"132");
	}
	else if (statsCheckBoxWeight == BST_UNCHECKED) {
		SetWindowText(editWeight, L"");
	}
	if (statsCheckBoxWeight == BST_CHECKED) {
		SetWindowText(editWeight1, L"150");
	}
	else if (statsCheckBoxWeight == BST_UNCHECKED) {
		SetWindowText(editWeight1, L"");
	}
}