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


//Main
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewMainWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);


//Menu
void MainWndAddMenus(HWND hWnd);


//Table UI
void TableWndAdd(HWND hWnd, LPARAM lp);
void TableCombobox(HWND hWnd, LPARAM lp);
void TableWnd(HWND hWnd);


//Request UI
void RequestWndAdd(HWND hWnd, LPARAM lp);
void RequestWnd(HWND hWnd);
void RequestCombobox(HWND hWnd, LPARAM lp);


//Init DataBase
void InitializeDatabase();
void LoadTableData(HWND hWnd);


//Delete UI
void DestroyUIElements(HWND hWnd);
void DestroyDataTable(HWND hWnd);
void DestroyIntTable(HWND hWnd);
void DestroyIntRequest(HWND hWnd);


//Coding UTF
std::string utf16_to_utf8(const std::wstring& utf16);
std::wstring utf8_to_utf16(const std::string& utf8);


//Potato Data
std::vector<std::vector<std::wstring>> GetPotatoDataFromDatabase();
void LoadPotatoDataIntoListView(HWND hListView);
void AddPotatoColumnsToListView(HWND hListView);


//Morphological Data
std::vector<std::vector<std::wstring>> GetMorphologicalDataFromDatabase();
void AddMorphologicalColumnsToListView(HWND hListView);
void LoadMorphologicalDataIntoListView(HWND hListView);


//Culinary Data
std::vector<std::vector<std::wstring>> GetCulinaryDataFromDatabase();
void AddCulinaryColumnsToListView(HWND hListView);
void LoadCulinaryDataIntoListView(HWND hListView);