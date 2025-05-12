void RequestWndAdd(HWND hWnd, LPARAM lp)
{
	RequestWnd(hWnd);
	RequestCombobox(hWnd, lp);
}

void RequestWnd(HWND hWnd)
{
	hStaticText = CreateWindowA(
		"static",
		"¬ыберите таблицу",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		10, 40, 200, 60,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	hButton = CreateWindowA(
		"button",
		"ќткрыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		5, 80, 120, 30,
		hWnd,
		(HMENU)ID_BUTTON_REQUEST_OPEN,
		NULL,
		NULL
	);
}

void RequestCombobox(HWND hWnd, LPARAM lp) 
{
	hComboBox = CreateWindowW(
		L"COMBOBOX",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		50, 50, 200, 200,
		hWnd,
		(HMENU)ID_COMBOBOX_REQUEST,
		(HINSTANCE)lp,
		NULL
	);

	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 1");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 2");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 3");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 4");
	SendMessage(hComboBox, CB_SETCURSEL, 0, 0);
}