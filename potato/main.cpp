#include <windows.h>
#include <commctrl.h>
#include <sqlite3.h>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <xlsxwriter.h>
#include <gdiplus.h>
#include <shlwapi.h> // ��� PathFileExists
#include <unordered_map>
#include <functional>
#include <cctype>

using namespace Gdiplus;

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "sqlite3.lib")
#pragma comment(lib, "xlsxwriter.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "shlwapi.lib")

#include "resource.h"

#include "SoftwareDefinitions.h"
#include "CreateWidgets.h"

#include "GlobalVariable.h"
#include "Image.h"
#include "MainWnd.h"
#include "TestWnd.h"
#include "SearchWnd.h"
#include "Tooltip.h"
#include "StandardData.h"
#include "Menu.h"
#include "DataBaseInit.h"
#include "TableInterface.h"
#include "RequestInterface.h"
#include "SearchInterface.h"
#include "AddInterface.h"
#include "DeleteInterface.h"
#include "EditInterface.h"
#include "AuthorizationInterface.h"
#include "DestroyUI.h"
#include "SqlRequestData.h"
#include "PotatoData.h"
#include "MorphologicalData.h"
#include "CulinaryData.h"
#include "RequestData.h"
#include "AddData.h"
#include "DeleteData.h"
#include "EditData.h"
#include "AddWnd.h"
#include "EditWnd.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
#pragma comment(linker, "\"/manifestdependency:type='win32' \
    name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
    processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

	// ������������� ����� ��������� ����������
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icc);

	// ������������� ���� ������
	InitializeDatabase();

	hInstance = hInst;

	WNDCLASS SoftwareMainClass = NewMainWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"MainWndClass", SoftwareMainProcedure);
	WNDCLASS SoftwareSearchClass = NewSearchWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"SearchWndClass", SoftwareSearchProcedure);
	WNDCLASS SoftwareAddClass = NewAddWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"AddWndClass", SoftwareAddProcedure);
	WNDCLASS SoftwareEditClass = NewEditWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"EditWndClass", SoftwareEditProcedure);
	WNDCLASS SoftwareTestClass = NewTestWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"TestWndClass", SoftwareTestProcedure);


	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };
	if (!RegisterClassW(&SoftwareSearchClass)) { return -1; }
	MSG SoftwareSearchMessage = { 0 };
	if (!RegisterClassW(&SoftwareAddClass)) { return -1; }
	MSG SoftwareAddMessage = { 0 };
	if (!RegisterClassW(&SoftwareEditClass)) { return -1; }
	MSG SoftwareEditMessage = { 0 };
	if (!RegisterClassW(&SoftwareTestClass)) { return -1; }
	MSG SoftwareTestMessage = { 0 };

	HWND hWnd = CreateWindow(
		L"MainWndClass",
		L"���� ������",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		460, 240, 1000, 650,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) 
	{
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	if (db) {
		sqlite3_close(db);
	}

	return 0;

}