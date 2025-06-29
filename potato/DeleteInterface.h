void Delete(HWND hWnd)
{
	DeleteStatic(hWnd);
	DeleteButton(hWnd);
	DeleteEditzone(hWnd);
}

void DeleteStatic(HWND hWnd)
{
	staticSample = CreateWindow(
		L"static",
		L"Образец",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 15, 220, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void DeleteEditzone(HWND hWnd)
{
	editID = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 45, 220, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}

void DeleteButton(HWND hWnd)
{
	complite = new Widgets(
		"button",
		"Удалить данные",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 90, 220, 30,
		hWnd,
		(HMENU)EditClickButton,
		NULL,
		NULL
	);
}