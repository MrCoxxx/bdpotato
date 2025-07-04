void TableWndAdd(HWND hWnd, LPARAM lp) 
{
	TableWnd(hWnd);
	TableCombobox(hWnd, lp);
	LoadTableData(hWnd);
}

void TableWnd(HWND hWnd)
{
	hStaticTextTable = CreateWindowA(
		"static",
		"Выберите таблицу",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		30, 20, 200, 60,
		hWnd,
		NULL,
		NULL,
		NULL
	);

	hButtonOpenTable = CreateWindowA(
		"button",
		"Открыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		15, 90, 120, 30,
		hWnd,
		(HMENU)OpenTableButton,
		NULL,
		NULL
	);

	hButtonCloseTable = CreateWindowA(
		"button",
		"Закрыть",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		135, 90, 120, 30,
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
		15, 40, 240, 200,
		hWnd,
		NULL,
		(HINSTANCE)lp,
		NULL
	);
	//Раскоментить когда будут данные
	//SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Все данные");
	
	SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Основные характеристики");	

	//SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Морфологические особенности клубня");
	//SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"Кулинарные качества");
	//SendMessageW(hComboBoxTable, CB_ADDSTRING, 0, (LPARAM)L"По отношению к стандартам");

	SendMessage(hComboBoxTable, CB_SETCURSEL, 0, 0);
	idComboBox = SendMessage(hComboBoxTable, CB_GETCURSEL, 0, 0);
}


void LoadTableData(HWND hWnd)
{

	hListView = CreateWindow(WC_LISTVIEW, L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_EDITLABELS,
		270, 10, 700, 570,
		hWnd, NULL,
		hInstance, NULL);
	//Раскоментить когда будут данные
	//if (idComboBox == 0)
	//{	
	//	AddAllToListView(hListView);
	//	LoadAllDataIntoListView(hListView);
	//}
	//
	
	if (idComboBox == 0)
	{
		AddPotatoColumnsToListView(hListView);
		LoadPotatoDataIntoListView(hListView);
	}
		
	//if (idComboBox == 2)
	//{
	//	AddMorphologicalColumnsToListView(hListView);
	//	LoadMorphologicalDataIntoListView(hListView);
	//}
	//if (idComboBox == 3)
	//{
	//	AddCulinaryColumnsToListView(hListView);
	//	LoadCulinaryDataIntoListView(hListView);
	//}
	//if (idComboBox == 4)
	//{
	//	
	//	AddStandartColumnsToListView(hListView);
	//	LoadStandartDataIntoListView(hListView);
	//}

}