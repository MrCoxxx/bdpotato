void MainWndAddMenus(HWND hWnd)
{
	HMENU RootMenu = CreateMenu();
	HMENU SubMenuMain = CreateMenu();
	HMENU SubMenuTable = CreateMenu();
	HMENU SubMenuRequest = CreateMenu();

	AppendMenu(SubMenuMain, MF_STRING, MenuAdd, L"Добавить новые данные");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuRedact, L"Редактировать данные");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuInfo, L"Информация");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuExit, L"Выход");

	AppendMenu(SubMenuTable, MF_STRING, MenuTableShow, L"Открыть");
	AppendMenu(SubMenuTable, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuTable, MF_STRING, MenuTableClose, L"Закрыть");

	AppendMenu(SubMenuRequest, MF_STRING, MenuRequestShow, L"Открыть");
	AppendMenu(SubMenuRequest, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuRequest, MF_STRING, MenuRequestClose, L"Закрыть");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuMain, L"Меню");
	AppendMenu(RootMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuTable, L"Таблицы");
	AppendMenu(RootMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuRequest, L"Запросы");

	SetMenu(hWnd, RootMenu);
}