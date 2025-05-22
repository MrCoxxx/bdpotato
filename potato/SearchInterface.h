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