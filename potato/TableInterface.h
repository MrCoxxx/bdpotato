void TableWndAdd(HWND hWnd, LPARAM lp) 
{
	TableWnd(hWnd);
	TableCombobox(hWnd, lp);
}

void TableWnd(HWND hWnd)
{
	hStaticText = CreateWindowA(
		"static",
		"¬ыберите таблицу",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		10, 20, 200, 60,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	hButton = CreateWindowA(
		"button",
		"ќткрыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		5, 90, 120, 30,
		hWnd,
		(HMENU)OpenTableButton,
		NULL,
		NULL
	);

	hButton = CreateWindowA(
		"button",
		"«акрыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		5, 120, 120, 30,
		hWnd,
		(HMENU)CloseTableButton,
		NULL,
		NULL
	);
}

void TableCombobox(HWND hWnd, LPARAM lp)
{
	hComboBox = CreateWindowW(
		L"COMBOBOX",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		20, 40, 200, 200,
		hWnd,
		(HMENU)ID_COMBOBOX_TABLE,
		(HINSTANCE)lp,
		NULL
	);

	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 1");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 2");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 3");
	SendMessageW(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"Ёлемент 4");
	SendMessage(hComboBox, CB_SETCURSEL, 0, 0);
}