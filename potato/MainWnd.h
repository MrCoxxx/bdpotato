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
			WndAdd(hWnd);
			break;
		case MenuRedact:
			WndEdit(hWnd);
			break;
		case MenuExport:
			ExportToExcel(db, "potato_data.xlsx");
			break;
		case MenuInfo:
			MessageBoxA(hWnd, "ѕрограмма учЄта видов картофел€\n"
				"разработали ѕавлов  ирилл ¬итальвич и \n"
				"√олубцов √еоргий ¬алентинович дл€ ”ниверситета", "»нформаци€", MB_OK);
			break;
		case MenuHelp:
			MessageBoxA(hWnd, "—редн€€ масса клубн€:\n"
				"1 Ч очень мелкий(до 10 г)\n"
				"3 Ч мелкий(10Ц40 г)\n"
				"5 Ч средний(41Ц90 г)\n"
				"7 Ч крупный(91Ц130 г)\n"
				"9 Ч очень крупный(более 130 г)\n"
				, "—правочна€ информаци€", MB_OK);
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
		case AuthorizationButton:
			const wchar_t* LoginA = L"admin";
			const wchar_t* PasswordA = L"admin";
			GetWindowTextW(editLogin, Buffer1, 256);
			GetWindowTextW(editPassword, Buffer2, 256);
			if (wcscmp(Buffer1, LoginA) == 0 &&
				wcscmp(Buffer2, PasswordA) == 0) {
				
			}
			break;
		
		}
		break;
	case WM_CREATE:
		//AuthrorizathionInt(hWnd);

		InitializeGDIplus();
		CreateImage(hWnd);

		DestroyAuthorization(hWnd);
		TableWndAdd(hWnd, (LPARAM)hInstance);
		//RequestWndAdd(hWnd, (LPARAM)hInstance);
		MainWndAddMenus(hWnd);

		break;
	case WM_PAINT:	
		CreatePaint(hWnd);
		break;
	case WM_DESTROY:
		
		Cleanup();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}