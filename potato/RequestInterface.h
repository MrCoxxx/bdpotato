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

	RequestCheckBox(hWnd);

}

void RequestCheckBox(HWND hWnd) 
{
	CheckBox1 = new Widgets(
		"button",
		"CheckBox",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 120, 100, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox2 = new Widgets(
		"button",
		"CheckBox",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 150, 100, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox3 = new Widgets(
		"button",
		"CheckBox",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 180, 100, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	CheckBox4 = new Widgets(
		"button",
		"CheckBox",
		WS_VISIBLE | WS_CHILD | ES_CENTER | BS_CHECKBOX,
		15, 210, 100, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void RequestCombobox(HWND hWnd, LPARAM lp) 
{
	hComboBoxRequest = CreateWindowW(
		L"COMBOBOX",
		L"",
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