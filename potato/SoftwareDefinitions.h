#pragma once

#define MenuAdd					1
#define MenuRedact				2
#define MenuInfo				3
#define MenuExit				4
#define MenuTableShow			5
#define MenuTableClose			6
#define MenuRequestShow			7
#define MenuRequestClose		8
#define OpenTableButton			9
#define CloseTableButton		10

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewMainWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void MainWndAddMenus(HWND hWnd);
void TableWndAdd(HWND hWnd, LPARAM lp);
void TableCombobox(HWND hWnd, LPARAM lp);
void TableWnd(HWND hWnd);
void RequestWndAdd(HWND hWnd, LPARAM lp);
void RequestWnd(HWND hWnd);
void RequestCombobox(HWND hWnd, LPARAM lp);
void DestroyUIElements(HWND hWnd);
void InitializeDatabase();
void LoadPotatoDataIntoListView(HWND hListView);
void AddPotatoColumnsToListView(HWND hListView);
std::vector<std::vector<std::wstring>> GetPotatoDataFromDatabase();
void LoadTableData(HWND hWnd);
void DestroyDataTable(HWND hWnd);
void DestroyIntTable(HWND hWnd);
void DestroyIntRequest(HWND hWnd);
std::string utf16_to_utf8(const std::wstring& utf16);
std::wstring utf8_to_utf16(const std::string& utf8);
void AddMorphologicalColumnsToListView(HWND hListView);
std::vector<std::vector<std::wstring>> GetMorphologicalDataFromDatabase();
void LoadMorphologicalDataIntoListView(HWND hListView);
void AddMorphologicalSample(const std::wstring& sample, const std::wstring& origin);