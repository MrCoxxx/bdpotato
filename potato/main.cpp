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

static HINSTANCE hInstance;
static BOOL isTableIntCreated = TRUE;
static BOOL isRequestIntCreated = FALSE;
static BOOL isTableCreated = FALSE;
static BOOL isSearchUI = FALSE;
static HWND hListView;
static HWND hComboBoxTable;
static HWND hStaticTextTable;
static HWND hButtonOpenTable;
static HWND hButtonCloseTable;
static HWND hComboBoxRequest;
static LRESULT idComboBox;
static sqlite3* db = nullptr;


#include "CreateWidgets.h"
#include "Menu.h"
#include "DataBaseInit.h"
#include "TableInterface.h"
#include "RequestInterface.h"
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
	
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(
		L"MainWndClass",
		L"База данных",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		460, 240, 1000, 650,
		NULL,
		NULL,
		NULL,
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
			if (!isSearchUI)
			{
				DestroyIntRequest(hWnd);
				Search(hWnd);
				isSearchUI = TRUE;
			}
			break;
		case SearchClickButtonClose:
			if (isSearchUI)
			{
				RequestWnd(hWnd);
				DestroySearchUI(hWnd);
				isSearchUI = FALSE;
			}
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