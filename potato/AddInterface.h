void Add(HWND hWnd)
{
	AddStatic(hWnd);
	AddButton(hWnd);
	AddEditzone(hWnd);
	AddComboboxzone(hWnd);
	AddDataComboboxzone(hWnd);
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
	staticOrigin = CreateWindow(
		L"static",
		L"Происхождение",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 80, 220, 20,
		hWnd,
		(HMENU)CheckBoxOrigin,
		NULL,
		NULL
	);
	staticVIGRR = CreateWindow(
		L"static",
		L"Каталожный №ВИГРР",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 145, 220, 20,
		hWnd,
		(HMENU)CheckBoxVIGRR,
		NULL,
		NULL
	);
	staticProductivity = CreateWindow(
		L"static",
		L"Урожайность",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 210, 220, 20,
		hWnd,
		(HMENU)CheckBoxProductivity,
		NULL,
		NULL
	);
	staticField = CreateWindow(
		L"static",
		L"Устойчивость к фитофторозу",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 275, 220, 20,
		hWnd,
		(HMENU)CheckBoxField,
		NULL,
		NULL
	);
	staticIDPotatoM = CreateWindow(
		L"static",
		L"ID образца",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 15, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	staticForm = CreateWindow(
		L"static",
		L"Форма",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 80, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	staticPeel = CreateWindow(
		L"static",
		L"Окраска кожуры",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 145, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	staticPulp = CreateWindow(
		L"static",
		L"Окраска мякоти",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 200, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	staticEye = CreateWindow(
		L"static",
		L"Глубина глазков",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 265, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	staticStolon = CreateWindow(
		L"static",
		L"Глубина столонного следа",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 340, 200, 20,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	staticIDPotatoC = CreateWindow(
		L"static",
		L"ID Образца",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 15, 185, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	staticTaste = CreateWindow(
		L"static",
		L"Вкус",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 80, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	staticConsistency = CreateWindow(
		L"static",
		L"Консинстенция",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 145, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	staticDarkening = CreateWindow(
		L"static",
		L"Потемнение после варки",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 200, 185, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	staticWeight = CreateWindow(
		L"static",
		L"Вес товарного клубня",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 340, 220, 20,
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
		15, 400, 635, 30,
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
	editIDPotatoM = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 45, 200, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	editForm = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	editPeel = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	editPulp = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 230, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	editEye = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 295, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	editStolon = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		250, 370, 200, 20,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	editIDPotatoC = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 45, 185, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	editTaste = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		465, 110, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	editConsistency = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		465, 175, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	editDarkening = CreateWindow(
		L"edit",
		L"",
		WS_CHILD | ES_CENTER,
		465, 230, 185, 20,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
	editWeightN = CreateWindow(
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