void MainWndAddMenus(HWND hWnd)
{
	HMENU RootMenu = CreateMenu();
	HMENU SubMenuMain = CreateMenu();
	HMENU SubMenuTable = CreateMenu();
	HMENU SubMenuRequest = CreateMenu();

	AppendMenu(SubMenuMain, MF_STRING, MenuAdd, L"�������� ����� ������");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuRedact, L"������������� ������");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuInfo, L"����������");
	AppendMenu(SubMenuMain, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuMain, MF_STRING, MenuExit, L"�����");

	AppendMenu(SubMenuTable, MF_STRING, MenuTableShow, L"�������");
	AppendMenu(SubMenuTable, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuTable, MF_STRING, MenuTableClose, L"�������");

	AppendMenu(SubMenuRequest, MF_STRING, MenuRequestShow, L"�������");
	AppendMenu(SubMenuRequest, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenuRequest, MF_STRING, MenuRequestClose, L"�������");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuMain, L"����");
	AppendMenu(RootMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuTable, L"�������");
	AppendMenu(RootMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenuRequest, L"�������");

	SetMenu(hWnd, RootMenu);
}