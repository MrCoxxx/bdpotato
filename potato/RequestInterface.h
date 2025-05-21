void RequestWndAdd(HWND hWnd, LPARAM lp)
{
	RequestWnd(hWnd);
	//RequestCombobox(hWnd, lp);
	LoadRequestData(hWnd);
}

Widgets* textRequest;
Widgets* searchOpen;
Widgets* searchClose;
Widgets* complite;
Widgets* min;
Widgets* avg;
Widgets* max;
Widgets* edit;
Widgets* CheckBox1;
Widgets* CheckBox2;
Widgets* CheckBox3;
Widgets* CheckBox4;

void RequestWnd(HWND hWnd)
{
	textRequest = new Widgets(
		"static",
		"Выберите запрос",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		40, 20, 200, 60,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	searchOpen = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15,
		90,
		240,
		30,
		hWnd,
		(HMENU)SearchClickButtonOpen,
		NULL,
		NULL
	);	
}

void Search(HWND hWnd) 
{	
	SearchCheckBox(hWnd);
	SearchButton(hWnd);
}

void SearchCheckBox(HWND hWnd) 
{
	CheckBox1 = new Widgets(
		"button",
		"Урожайность",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 120, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox2 = new Widgets(
		"button",
		"Полевая устойчивость",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 170, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox3 = new Widgets(
		"button",
		"Номер по каталогу",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 200, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox4 = new Widgets(
		"button",
		"Масса",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 230, 150, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void SearchButton(HWND hWnd) 
{

	searchClose = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 90, 240, 30,
		hWnd,
		(HMENU)SearchClickButtonClose,
		NULL,
		NULL
	);

	complite = new Widgets(
		"button",
		"Поиск",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 500, 240, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	min = new Widgets(
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
	);
	edit = new Widgets(
		"edit",
		"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		165, 150, 100, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void RequestCombobox(HWND hWnd, LPARAM lp) 
{
	hComboBoxRequest = CreateWindowA(
		"COMBOBOX",
		"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		50, 50, 200, 200,
		hWnd,
		NULL,
		(HINSTANCE)lp,
		NULL
	);

	SendMessageW(hComboBoxRequest, CB_ADDSTRING, 0, (LPARAM)L"Элемент 1");
	SendMessageW(hComboBoxRequest, CB_ADDSTRING, 0, (LPARAM)L"Элемент 2");
	SendMessageW(hComboBoxRequest, CB_ADDSTRING, 0, (LPARAM)L"Элемент 3");
	SendMessageW(hComboBoxRequest, CB_ADDSTRING, 0, (LPARAM)L"Элемент 4");
	SendMessage(hComboBoxRequest, CB_SETCURSEL, 0, 0);
}

void LoadRequestData(HWND hWnd)
{

	hListView = CreateWindow(WC_LISTVIEW, L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_EDITLABELS,
		270, 10, 700, 570,
		hWnd, NULL,
		hInstance, NULL);

}