#pragma once

#define MenuAdd		1
#define MenuRedact		2
#define MenuInfo		3
#define MenuExit		4
#define MenuTableShow		5
#define MenuTableClose		6
#define MenuRequestShow		7
#define MenuRequestClose		8

#define ID_COMBOBOX_TABLE	1001
#define ID_COMBOBOX_REQUEST	1002
#define ID_BUTTON_TABLE 1003
#define ID_BUTTON_REQUEST 1004

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewMainWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void MainWndAddMenus(HWND hWnd);
void TableWndAdd(HWND hWnd, LPARAM lp);
void TableCombobox(HWND hWnd, LPARAM lp);
void TableWnd(HWND hWnd);
void RequestWnd(HWND hWnd);
void RequestCombobox(HWND hWnd, LPARAM lp);
void DestroyUIElements(HWND hWnd);