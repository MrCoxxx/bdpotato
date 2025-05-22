#include <windows.h>
#include <sqlite3.h>
#include <commctrl.h>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <locale>
#include <codecvt>

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "sqlite3.lib")

#include "SoftwareDefinitions.h"
#include "CreateWidgets.h"

#include "GlobalVariable.h"

#include "MainWnd.h"
#include "SearchWnd.h"
#include "Menu.h"
#include "DataBaseInit.h"
#include "TableInterface.h"
#include "RequestInterface.h"
#include "SearchInterface.h"
#include "DestroyUI.h"
#include "PotatoData.h"
#include "MorphologicalData.h"
#include "CulinaryData.h"
#include "RequestData.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	// Инициализация общих элементов управления
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icc);

	// Инициализация базы данных
	InitializeDatabase();

	hInstance = hInst;

	WNDCLASS SoftwareMainClass = NewMainWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"MainWndClass", SoftwareMainProcedure);
	WNDCLASS SoftwareSearchClass = NewSearchWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"SearchWndClass", SoftwareSearchProcedure);
	
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };
	if (!RegisterClassW(&SoftwareSearchClass)) { return -1; }
	MSG SoftwareSearchMessage = { 0 };

	HWND hWnd = CreateWindow(
		L"MainWndClass",
		L"База данных",
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