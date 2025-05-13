void TableWndAdd(HWND hWnd, LPARAM lp) 
{
	TableWnd(hWnd);
	TableCombobox(hWnd, lp);
}

void TableWnd(HWND hWnd)
{
	hStaticTextTable = CreateWindowA(
		"static",
		"Выберите таблицу",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		10, 20, 200, 60,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	hButtonOpenTable = CreateWindowA(
		"button",
		"Открыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		5, 90, 120, 30,
		hWnd,
		(HMENU)OpenTableButton,
		NULL,
		NULL
	);

	hButtonCloseTable = CreateWindowA(
		"button",
		"Закрыть",
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
	hComboBoxTable = CreateWindowW(
		L"COMBOBOX",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		20, 40, 200, 200,
		hWnd,
		NULL,
		(HINSTANCE)lp,
		NULL
	);

	SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Все данные");
	SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Картошка");
	SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Морфологические признаки");
	SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Кулинарные качества");
	SendMessage(hComboBoxTable, CB_SETCURSEL, 0, 0);
}