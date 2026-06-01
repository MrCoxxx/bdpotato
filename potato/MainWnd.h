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

		case MenuAdd:
			WndAdd(hWnd);
			return 0;
		case MenuRedact:
			WndEdit(hWnd);
			return 0;
		case MenuInfo:
			MessageBoxA(hWnd, "Ïðîãðàììà ó÷¸òà âèäîâ êàðòîôåëÿ\n"
				"ðàçðàáîòàëè Ïàâëîâ Êèðèëë Âèòàëüâè÷ è \n"
				"Ãîëóáöîâ Ãåîðãèé Âàëåíòèíîâè÷ äëÿ Óíèâåðñèòåòà", "Èíôîðìàöèÿ", MB_OK);
			return 0;
		case MenuHelp:
			MessageBoxA(hWnd, "Ñðåäíÿÿ ìàññà êëóáíÿ:\n"
				"1 — î÷åíü ìåëêèé(äî 10 ã)\n"
				"3 — ìåëêèé(10–40 ã)\n"
				"5 — ñðåäíèé(41–90 ã)\n"
				"7 — êðóïíûé(91–130 ã)\n"
				"9 — î÷åíü êðóïíûé(áîëåå 130 ã)\n"
				, "Ñïðàâî÷íàÿ èíôîðìàöèÿ", MB_OK);
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

				DestroyUIElements(hWnd);
				TableWndAdd(hWnd, (LPARAM)hInstance);
				isTableIntCreated = TRUE;
				isRequestIntCreated = FALSE;

			}
			return 0;
		case MenuTableClose:
			ClearInterface(hWnd, "Table");
			DestroyUIElements(hWnd);
			isTableIntCreated = FALSE;
			isRequestIntCreated = FALSE;
			return 0;
		case MenuRequestShow:
			if (!isRequestIntCreated)
			{
				ClearInterface(hWnd, "Table");
				DestroyUIElements(hWnd);
				RequestWndAdd(hWnd, (LPARAM)hInstance);
				isRequestIntCreated = TRUE;
				isTableIntCreated = FALSE;

			}
			return 0;
		case MenuTemplateMgr:
			InitializeTemplateInterface(hWnd);
			DestroyUIElements(hWnd);
			return 0;
		case MenuRequestSample:

			DestroyUIElements(hWnd);
			return 0;
		case MenuRequestClose:
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