void AuthrorizathionInt(HWND hWnd) {
	hButtonAuthorization = CreateWindowA(
		"button",
		"��������������",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		400, 300, 120, 30,
		hWnd,
		(HMENU)AuthorizationButton,
		NULL,
		NULL
	);
	editLogin = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		400, 180, 120, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	editPassword = CreateWindow(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		400, 240, 120, 20,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	hStaticLogin = CreateWindowA(
		"static",
		"�����",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		400, 150, 120, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);
	hStaticPassword = CreateWindowA(
		"static",
		"������",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		400, 210, 120, 30,
		hWnd,
		NULL,
		NULL,
		NULL
	);
}