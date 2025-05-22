WNDCLASS NewMainWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWC = { 0 };

	NWC.hbrBackground = BGColor;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.hIcon = Icon;
	NWC.lpszClassName = Name;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{
		case MenuAdd:
			MessageBoxA(hWnd, "В разработке", "Добавление данных", MB_OK);
			break;
		case MenuRedact:
			MessageBoxA(hWnd, "В разработке", "Редактирование данных", MB_OK);
			break;
		case MenuInfo:
			MessageBoxA(hWnd, "В разработке", "Информация", MB_OK);
			break;
		case  MenuExit:
			PostQuitMessage(0);
			break;
		case MenuTableShow:
			if (!isTableIntCreated)
			{
				DestroyUIElements(hWnd);
				TableWndAdd(hWnd, (LPARAM)hInstance);
				isTableIntCreated = TRUE;
				isRequestIntCreated = FALSE;

			}
			break;
		case MenuTableClose:
			DestroyUIElements(hWnd);
			isTableIntCreated = FALSE;
			isRequestIntCreated = FALSE;
			break;
		case MenuRequestShow:
			if (!isRequestIntCreated)
			{
				DestroyUIElements(hWnd);
				RequestWndAdd(hWnd, (LPARAM)hInstance);
				isRequestIntCreated = TRUE;
				isTableIntCreated = FALSE;

			}
			break;
		case MenuRequestClose:
			DestroyUIElements(hWnd);
			isRequestIntCreated = FALSE;
			isTableIntCreated = FALSE;
			break;
		case OpenTableButton:
			DestroyDataTable(hWnd);
			idComboBox = SendMessage(hComboBoxTable, CB_GETCURSEL, 0, 0);
			LoadTableData(hWnd);
			break;
		case CloseTableButton:
			DestroyDataTable(hWnd);
			idComboBox = NULL;
			isTableCreated = FALSE;
			break;
		case SearchClickButtonOpen:
			WndSearch(hWnd);
			break;	
		
		
		}
		break;
	case WM_CREATE:
		TableWndAdd(hWnd, (LPARAM)hInstance);
		//RequestWndAdd(hWnd, (LPARAM)hInstance);
		MainWndAddMenus(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}