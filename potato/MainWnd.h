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
    case WM_CREATE:
    {

        //AuthrorizathionInt(hWnd);

        //InitializeTemplateInterface(hWnd);

        InitializeGDIplus();
        CreateImage(hWnd);

        DestroyAuthorization(hWnd);
        TableWndAdd(hWnd, (LPARAM)hInstance);
        //RequestWndAdd(hWnd, (LPARAM)hInstance);
        MainWndAddMenus(hWnd);

        
    }

    case WM_COMMAND:
    {
        int id = LOWORD(wp);
        int code = HIWORD(wp);

        // Выбор шаблона в комбобоксе
        if (id == IDC_TEMPLATE_CHANGE && code == CBN_SELCHANGE)
        {
            OnTemplateSelectionChanged();
            return 0;
        }

		switch (id)
		{
		case IDC_CREATE_TEMPLATE:
			CreateNewTemplate();
			return 0;

		case IDC_EDIT_TEMPLATE:
			SaveCurrentTemplateToVector();
			return 0;

		case IDC_DELETE_TEMPLATE:
			DeleteCurrentTemplate();
			return 0;

		case IDC_SAVE_TEMPLATES:
			if (!SaveTemplatesToFile("Sample.json"))
			{
				MessageBoxW(hWnd, L"Не удалось сохранить JSON", L"Ошибка", MB_ICONERROR);
			}
			else
			{
				MessageBoxW(hWnd, L"JSON сохранён", L"OK", MB_OK);
			}
			return 0;

		case IDC_LOAD_TEMPLATES:
			if (!LoadTemplatesFromFile("Sample.json"))
			{
				MessageBoxW(hWnd, L"Не удалось загрузить JSON", L"Ошибка", MB_ICONERROR);
			}
			else
			{
				RefreshTemplatesCombo();
				FillControlsFromCurrentTemplate();
			}
			return 0;

		case IDC_COMPARE:
		{
			if (g_currentTemplateIndex < 0 || g_currentTemplateIndex >= (int)g_templates.size())
			{
				MessageBoxW(hWnd, L"Нет выбранного шаблона", L"Ошибка", MB_ICONERROR);
				return 0;
			}

			UiTemplate t = ReadCurrentTemplateFromControls();
			std::wstring report = GenerateComparisonReport(t);
			ShowReportInUI(report);
			return 0;
		}

		case IDC_CLEAR:
			ClearCurrentTemplateUI();
			return 0;

		case IDC_ADD_TRAIT:
			AddOrUpdateTrait();
			return 0;

		case IDC_REMOVE_TRAIT:
			RemoveSelectedTrait();
			return 0;

		case IDC_OPEN_GEO_MAP:
		{
			ClearInterface(hWnd, "Table");
			ClearSampleInterface(hWnd);
			DestroyUIElements(hWnd);
			LoadFromJson("GeoData.json");
			OpenGeoMapForWindow(hWnd);
			isRequestIntCreated = FALSE;
			isTableIntCreated = FALSE;

			return 0;
		}

		case IDC_REFRESH_GEO_MAP:
		{
			RefreshGeoMap();
			return 0;
		}

		case MenuDuplicate:
			WndDuplicate(hWnd);
			break;

		case MenuAdd:
			WndAdd(hWnd);
			return 0;
		case MenuRedact:
			WndEdit(hWnd);
			return 0;
		case MenuInfo:
			MessageBoxA(hWnd, "Программа учёта видов картофеля\n"
				"разработали Павлов Кирилл Витальевич и \n"
				"Голубцов Георгий Валентинович для Университета", "Информация", MB_OK);
			return 0;
		case MenuHelp:
			MessageBoxA(hWnd, "Средняя масса клубня:\n"
				"1 — очень мелкий(до 10 г)\n"
				"3 — мелкий(10–40 г)\n"
				"5 — средний(41–90 г)\n"
				"7 — крупный(91–130 г)\n"
				"9 — очень крупный(более 130 г)\n"
				, "Справочная информация", MB_OK);
			//SaveJSON("Sample.json");
			//DeleteJSON("Sample.json", "name12");
			//process_potatoes();
			Sampling();
			//MessageBoxA(hWnd, process_potatoes(), "Èíôîðìàöèÿ", MB_OK);

			return 0;
		case  MenuExit:
			PostQuitMessage(0);
			return 0;
		case MenuTableShow:
			if (!isTableIntCreated)
			{
				ClearGeoMap();
				ClearSampleInterface(hWnd);
				DestroyUIElements(hWnd);
				TableWndAdd(hWnd, (LPARAM)hInstance);
				isTableIntCreated = TRUE;
				isRequestIntCreated = FALSE;

			}
			return 0;
		case MenuTableClose:
			ClearGeoMap();
			ClearInterface(hWnd, "Table");
			DestroyUIElements(hWnd);
			ClearSampleInterface(hWnd);
			isTableIntCreated = FALSE;
			isRequestIntCreated = FALSE;
			return 0;
		case MenuRequestShow:
			if (!isRequestIntCreated)
			{
				ClearGeoMap();
				ClearInterface(hWnd, "Table");
				DestroyUIElements(hWnd);
				ClearSampleInterface(hWnd);
				RequestWndAdd(hWnd, (LPARAM)hInstance);
				isRequestIntCreated = TRUE;
				isTableIntCreated = FALSE;

			}
			return 0;
		case MenuTemplateMgr:
			ClearGeoMap();
			ClearInterface(hWnd, "Table");
			InitializeTemplateInterface(hWnd);
			DestroyUIElements(hWnd);
			isTableIntCreated = FALSE;
			isRequestIntCreated = FALSE;
			return 0;
		case MenuRequestSample:

			DestroyUIElements(hWnd);
			return 0;
		case MenuRequestClose:
			ClearGeoMap();
			ClearInterface(hWnd, "Table");
			ClearSampleInterface(hWnd);
			DestroyUIElements(hWnd);
			isRequestIntCreated = FALSE;
			isTableIntCreated = FALSE;
			return 0;
		case OpenTableButton:
			DestroyDataTable(hWnd);
			idComboBox = SendMessage(hComboBoxTable, CB_GETCURSEL, 0, 0);
			LoadTableData(hWnd);
			return 0;
		case CloseTableButton:
			DestroyDataTable(hWnd);
			idComboBox = NULL;
			isTableCreated = FALSE;
			return 0;
		case SearchClickButtonOpen:
			WndSearch(hWnd);
			return 0;
		case AuthorizationButton:
			const wchar_t* LoginA = L"admin";
			const wchar_t* PasswordA = L"admin";
			GetWindowTextW(editLogin, Buffer1, 256);
			GetWindowTextW(editPassword, Buffer2, 256);
			if (wcscmp(Buffer1, LoginA) == 0 &&
				wcscmp(Buffer2, PasswordA) == 0) {

			}
			return 0;
		}
		break;
    }
	
    case WM_PAINT:
        CreatePaint(hWnd);
        return 0;

    case WM_DESTROY:
        Cleanup();
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, msg, wp, lp);
}