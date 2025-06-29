void Add(HWND hWnd)
{
	AddStatic(hWnd);
	AddButton(hWnd);
	AddEditzone(hWnd);
	//AddComboboxzone(hWnd);
	//AddDataComboboxzone(hWnd);
}

void AddStatic(HWND hWnd) 
{
	staticSample = CreateWindow(
		L"static",
		L"Образец",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 15, 220, 20,
		hWnd,
		(HMENU)CheckBoxSample,
		NULL,
		NULL
	);
	staticVIGRR = CreateWindow(
		L"static",
		L"№ по каталогу ВИГРР",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 80, 220, 20,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	staticOrigin = CreateWindow(
		L"static",
		L"Происхождение",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 145, 220, 20,
		hWnd,
		(HMENU)CheckBoxOrigin,
		NULL,
		NULL
	);
	staticCommercial_tubers = CreateWindow(
		L"static",
		L"Товарных клубней в клоне, шт.",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 210, 220, 20,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	staticNon_marketable = CreateWindow(
		L"static",
		L"Нетоварных клубней в клоне, шт.",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 275, 220, 20,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);
	staticCommercial = CreateWindow(
		L"static",
		L"Масса товарного клубня, г",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 340, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	staticNon_commercial = CreateWindow(
		L"static",
		L"Масса нетоварного клубня, г",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 405, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	staticTubers = CreateWindow(
		L"static",
		L"Клубней в клоне, шт",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 470, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	staticMarketability = CreateWindow(
		L"static",
		L"Товарность, %",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 535, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	staticProductivity = CreateWindow(
		L"static",
		L"Урожайность, кг/м2",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 600, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);



	staticForm = CreateWindow(
		L"static",
		L"Форма",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 15, 200, 20,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	staticPeel = CreateWindow(
		L"static",
		L"Окраска кожуры",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 80, 185, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	staticPulp = CreateWindow(
		L"static",
		L"Окраска мякоти",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 145, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	staticEye = CreateWindow(
		L"static",
		L"Глубина глазков",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 210, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	staticStolon = CreateWindow(
		L"static",
		L"Глубина столонного следа",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 275, 185, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	staticSkin = CreateWindow(
		L"static",
		L"Поверхность кожуры клубня",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 340, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);


	staticBoilability = CreateWindow(
		L"static",
		L"Разваримость клубней",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 15, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticConsistency = CreateWindow(
		L"static",
		L"Консистенция мякоти",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 80, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticFriability = CreateWindow(
		L"static",
		L"Рассыпчатость",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 145, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticWateriness = CreateWindow(
		L"static",
		L"Водянистость клубней",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 210, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticSmell = CreateWindow(
		L"static",
		L"Запах варёного картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 275, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticTaste = CreateWindow(
		L"static",
		L"Вкус варёного картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 340, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticDarkening_raw = CreateWindow(
		L"static",
		L"Потемнение мякоти сырого картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 405, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticDarkening_boiled = CreateWindow(
		L"static",
		L"Потемнение мякоти варёного картофеля",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 470, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);


	staticField = CreateWindow(
		L"static",
		L"Полевая устойчивость к фитофторозу, балл",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 15, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticAbility = CreateWindow(
		L"static",
		L"Способность к ягодообразованию от самоопыления (балл)",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 80, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticFlowering = CreateWindow(
		L"static",
		L"Продолжительность цветения,дни",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 145, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticRipeness = CreateWindow(
		L"static",
		L"Группа спелости",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 210, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	staticYield = CreateWindow(
		L"static",
		L"Урожайность, %",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		680, 275, 220, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
}
void AddButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"Добавить",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 665, 900, 30,
		hWnd,
		(HMENU)AddClickButton,
		NULL,
		NULL
	);
}

void AddEditzone(HWND hWnd)
{
	editSample = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 45, 200, 20,
		hWnd,
		(HMENU)CheckBoxSample,
		NULL,
		NULL
	);
	editVIGRR = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	editOrigin = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxOrigin,
		NULL,
		NULL
	);
	editCommercial_tubers = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 240, 200, 20,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	editNon_marketable = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 305, 200, 20,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);
	editCommercial = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 370, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	editNon_commercial = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 435, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	editTubers = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 500, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	editMarketability = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 565, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	editProductivity = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 630, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);



	editForm = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 45, 200, 20,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	editPeel = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
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
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	editEye = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 240, 200, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	editStolon = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 305, 200, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	editSkin = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 370, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);



	editBoilability = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 45, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editConsistency = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editFriability = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editWateriness = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 240, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editSmell = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 305, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editTaste = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 370, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editDarkening_raw = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 435, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editDarkening_boiled = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		480, 500, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);



	editField = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		710, 45, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editAbility = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		710, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editFlowering = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		710, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editRipeness = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		710, 240, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
	editYield = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		710, 305, 200, 20,
		hWnd,
		(HMENU)CheckBoxWeight,
		NULL,
		NULL
	);
}
//
//void AddComboboxzone(HWND hWnd)
//{
//	comboboxForm = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		250, 110, 200, 200,
//		hWnd,
//		(HMENU)CheckBoxForm,
//		NULL,
//		NULL
//	);
//	comboboxPeel = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		250, 175, 200, 200,
//		hWnd,
//		(HMENU)CheckBoxPeel,
//		NULL,
//		NULL
//	);
//	comboboxPulp = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		250, 230, 200, 200,
//		hWnd,
//		(HMENU)CheckBoxPulp,
//		NULL,
//		NULL
//	);
//	comboboxEye = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		250, 295, 200, 200,
//		hWnd,
//		(HMENU)CheckBoxEye,
//		NULL,
//		NULL
//	);
//	comboboxStolon = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		250, 370, 200, 200,
//		hWnd,
//		(HMENU)CheckBoxStolon,
//		NULL,
//		NULL
//	);
//	comboboxTaste = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		465, 110, 185, 200,
//		hWnd,
//		(HMENU)CheckBoxTaste,
//		NULL,
//		NULL
//	);
//	comboboxConsistency = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		465, 175, 185, 200,
//		hWnd,
//		(HMENU)CheckBoxConsistency,
//		NULL,
//		NULL
//	);
//	comboboxDarkening = CreateWindow(
//		L"combobox",
//		L"",
//		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
//		465, 230, 185, 200,
//		hWnd,
//		(HMENU)CheckBoxDarkening,
//		NULL,
//		NULL
//	);
//}
//
//void AddDataComboboxzone(HWND hWnd) {
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxDarkening, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
//	}
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxConsistency, CB_ADDSTRING, 0, (LPARAM)nameC[i]);
//	}
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxTaste, CB_ADDSTRING, 0, (LPARAM)nameTa[i]);
//	}
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxStolon, CB_ADDSTRING, 0, (LPARAM)nameS[i]);
//	}
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxEye, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
//	}
//	for (int i = 0; i < 5; i++) {
//		SendMessageW(comboboxPulp, CB_ADDSTRING, 0, (LPARAM)nameE[i]);
//	}
//	for (int i = 0; i < 9; i++) {
//		SendMessageW(comboboxPeel, CB_ADDSTRING, 0, (LPARAM)namePu[i]);
//	}
//	for (int i = 0; i < 9; i++) {
//		SendMessageW(comboboxForm, CB_ADDSTRING, 0, (LPARAM)nameP[i]);
//	}
//}