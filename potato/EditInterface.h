void Edit(HWND hWnd)
{
	EditStatic(hWnd);
	EditButton(hWnd);
	EditEditzone(hWnd);
}

void EditStatic(HWND hWnd)
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
void EditButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"Редактировать",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 435, 635, 30,
		hWnd,
		(HMENU)EditClickButton,
		NULL,
		NULL
	);
}

void EditEditzone(HWND hWnd)
{
	editID = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 400, 220, 20,
		hWnd,
		(HMENU)CheckBoxSample,
		NULL,
		NULL
	);

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
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 110, 200, 20,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	editPeel = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 175, 200, 20,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	editPulp = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 230, 200, 20,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	editEye = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		250, 295, 200, 20,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	editStolon = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
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
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 110, 185, 20,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	editConsistency = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		465, 175, 185, 20,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	editDarkening = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
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