#include <windows.h>
#include <sqlite3.h> 

#include "SoftwareDefinitions.h"

static BOOL isTableCreated = TRUE;
static BOOL isRequestCreated = FALSE;

static HWND hComboBox;
static HINSTANCE hInstance;
static HWND hStaticText;
static HWND hButton;

#include "Menu.h"
#include "TableInterface.h"
#include "RequestInterface.h"
#include "DestroyUI.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{

	sqlite3* db;    // указатель на базу данных
	// открываем подключение к базе данных
	int result = sqlite3_open("kart.db", &db);

	// закрываем подключение
	sqlite3_close(db);

	hInstance = hInst;

	WNDCLASS SoftwareMainClass = NewMainWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION), L"MainWndClass", SoftwareMainProcedure);
	
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(
		L"MainWndClass",
		L"Potato",
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
		case MenuExit:
			PostQuitMessage(0);
			break;
		case MenuTableShow:
			if (!isTableCreated)
			{
				DestroyUIElements(hWnd);
				TableWndAdd(hWnd, (LPARAM)hInstance);
				isTableCreated = TRUE;
				isRequestCreated = FALSE;

			}
			break;
		case MenuTableClose:
			DestroyUIElements(hWnd);
			isTableCreated = FALSE;
			break;
		case MenuRequestShow:
			if (!isRequestCreated)
			{
				DestroyUIElements(hWnd);
				RequestWndAdd(hWnd, (LPARAM)hInstance);
				isTableCreated = FALSE;
				isRequestCreated = TRUE;

			}
			break;
		case MenuRequestClose:
			DestroyUIElements(hWnd);
			isRequestCreated = FALSE;
			break;
		}
		
		break;

	case WM_CREATE:
		TableWndAdd(hWnd, (LPARAM)hInstance);
		MainWndAddMenus(hWnd);
		
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}