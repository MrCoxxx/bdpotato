void Add(HWND hWnd)
{
	AddStatic(hWnd);
	AddButton(hWnd);
	AddEditzone(hWnd);
	//AddComboboxzone(hWnd);
	//AddDataComboboxzone(hWnd);
}

void ClearAddData() {
	SetWindowText(editSample, L"");
	SetWindowText(editVIGRR, L"");
	SetWindowText(editOrigin, L"");
	SetWindowText(editCommercial_tubers, L"");
	SetWindowText(editNon_marketable, L"");
	SetWindowText(editCommercial, L"");
	SetWindowText(editNon_commercial, L"");
	SetWindowText(editTubers, L"");
	SetWindowText(editMarketability, L"");
	SetWindowText(editProductivity, L"");
	SetWindowText(editForm, L"");
	SetWindowText(editPeel, L"");
	SetWindowText(editPulp, L"");
	SetWindowText(editEye, L"");
	SetWindowText(editStolon, L"");
	SetWindowText(editSkin, L"");
	SetWindowText(editBoilability, L"");
	SetWindowText(editConsistency, L"");
	SetWindowText(editFriability, L"");
	SetWindowText(editWateriness, L"");
	SetWindowText(editSmell, L"");
	SetWindowText(editTaste, L"");
	SetWindowText(editDarkening_raw, L"");
	SetWindowText(editDarkening_boiled, L"");
}

void AddStatic(HWND hWnd) 
{

	Interface("static", staticPotato, 15, 15, 220, 20, hWnd, hNULL, 1, 65, 10);

	Interface("static", staticMorh, 250, 15, 200, 20, hWnd, hNULL, 1, 65, 6);

	Interface("static", staticCul, 465, 15, 220, 20, hWnd, hNULL, 1, 65, 8);

	//Interface("static", staticStand, 680, 15, 220, 20, hWnd, hNULL, 1, 65, 5);

	CheckInt();
}

void AddButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"Добавить",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 665, 650, 30,
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


	//Раскоментить когда будут данные
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
	
	
	
	//editField = CreateWindow(
	//	L"edit",
	//	L"",
	//	WS_VISIBLE | WS_CHILD | ES_CENTER,
	//	710, 45, 200, 20,
	//	hWnd,
	//	(HMENU)CheckBoxWeight,
	//	NULL,
	//	NULL
	//);
	//editAbility = CreateWindow(
	//	L"edit",
	//	L"",
	//	WS_VISIBLE | WS_CHILD | ES_CENTER,
	//	710, 110, 200, 20,
	//	hWnd,
	//	(HMENU)CheckBoxWeight,
	//	NULL,
	//	NULL
	//);
	//editFlowering = CreateWindow(
	//	L"edit",
	//	L"",
	//	WS_VISIBLE | WS_CHILD | ES_CENTER,
	//	710, 175, 200, 20,
	//	hWnd,
	//	(HMENU)CheckBoxWeight,
	//	NULL,
	//	NULL
	//);
	//editRipeness = CreateWindow(
	//	L"edit",
	//	L"",
	//	WS_VISIBLE | WS_CHILD | ES_CENTER,
	//	710, 240, 200, 20,
	//	hWnd,
	//	(HMENU)CheckBoxWeight,
	//	NULL,
	//	NULL
	//);
	//editYield = CreateWindow(
	//	L"edit",
	//	L"",
	//	WS_VISIBLE | WS_CHILD | ES_CENTER,
	//	710, 305, 200, 20,
	//	hWnd,
	//	(HMENU)CheckBoxWeight,
	//	NULL,
	//	NULL
	//);
}

void AddComboboxzone(HWND hWnd)
{
	comboboxForm = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 110, 200, 200,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	comboboxPeel = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 175, 200, 200,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	comboboxPulp = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 230, 200, 200,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	comboboxEye = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 295, 200, 200,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	comboboxStolon = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 370, 200, 200,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	comboboxTaste = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 110, 185, 200,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	comboboxConsistency = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 175, 185, 200,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	comboboxDarkening = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 230, 185, 200,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
}

void AddDataComboboxzone(HWND hWnd) {
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxDarkening, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxConsistency, CB_ADDSTRING, 0, (LPARAM)nameC[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxTaste, CB_ADDSTRING, 0, (LPARAM)nameTa[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxStolon, CB_ADDSTRING, 0, (LPARAM)nameS[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxEye, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxPulp, CB_ADDSTRING, 0, (LPARAM)nameE[i]);
	}
	for (int i = 0; i < 9; i++) {
		SendMessageW(comboboxPeel, CB_ADDSTRING, 0, (LPARAM)namePu[i]);
	}
	for (int i = 0; i < 9; i++) {
		SendMessageW(comboboxForm, CB_ADDSTRING, 0, (LPARAM)nameP[i]);
	}
}