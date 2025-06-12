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
#define SearchClickButtonOpen	11
#define SearchClickButtonClose	12
#define CheckBoxSample			13
#define CheckBoxOrigin			14
#define CheckBoxVIGRR			15
#define CheckBoxProductivity	16
#define CheckBoxField			17
#define CheckBoxForm			18	
#define CheckBoxPeel			19
#define CheckBoxPulp			20
#define CheckBoxEye				21
#define CheckBoxStolon			22
#define CheckBoxTaste			23
#define CheckBoxConsistency		24
#define CheckBoxDarkening		25
#define CheckBoxWeight			26
#define AuthorizationButton		27
#define AddClickButton			28
#define EditClickButton			29
#define MenuExport				30
#define CheckBoxPeel1 31
#define CheckBoxPeel2 32

#define TextBufferSize			256

wchar_t Buffer1[TextBufferSize];
wchar_t Buffer2[TextBufferSize];
wchar_t Buffer3[TextBufferSize];
wchar_t Buffer4[TextBufferSize];
wchar_t Buffer5[TextBufferSize];
wchar_t Buffer6[TextBufferSize];
wchar_t Buffer7[TextBufferSize];
wchar_t Buffer8[TextBufferSize];
wchar_t Buffer9[TextBufferSize];
wchar_t Buffer10[TextBufferSize];
wchar_t Buffer11[TextBufferSize];
wchar_t Buffer12[TextBufferSize];
wchar_t Buffer13[TextBufferSize];
wchar_t Buffer14[TextBufferSize];


//Main
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewMainWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);


//Search
LRESULT CALLBACK SoftwareSearchProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
WNDCLASS NewSearchWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void WndSearch(HWND hWnd);
void SearchCheckbox(HWND hWnd);
void SearchEditzone(HWND hWnd);
//QueryData BuildQuery();

//
void AuthrorizathionInt(HWND hWnd);

//Menu
void MainWndAddMenus(HWND hWnd);

//Add
LRESULT CALLBACK SoftwareAddProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewAddWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void WndAdd(HWND hWnd);
void AddEditzone(HWND hWnd);
void Add(HWND hWnd);
void AddStatic(HWND hWnd);
void AddButton(HWND hWnd);
void AddPotatoSample();
void AddMorphologicalSample();
void AddCulinarySample();

//Edit
LRESULT CALLBACK SoftwareEditProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewEditWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void WndEdit(HWND hWnd);
void Edit(HWND hWnd);
void EditStatic(HWND hWnd);
void EditButton(HWND hWnd);
void EditEditzone(HWND hWnd);
void EditPotatoSample();
void EditMorphologicalSample();
void EditCulinarySample();

//Test
LRESULT CALLBACK SoftwareTestProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewTestWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
void WndTest(HWND hWnd);
void Test(HWND hWnd);

//Table UI
void TableWndAdd(HWND hWnd, LPARAM lp);
void TableCombobox(HWND hWnd, LPARAM lp);
void TableWnd(HWND hWnd);


//Request UI
void RequestWndAdd(HWND hWnd, LPARAM lp);
void RequestWnd(HWND hWnd);
void RequestCombobox(HWND hWnd, LPARAM lp);
void Search(HWND hWnd);
void SearchCheckBox(HWND hWnd);
void SearchButton(HWND hWnd);
void WndSearch(HWND hWnd);


//Init DataBase
void InitializeDatabase();
void LoadTableData(HWND hWnd);
void LoadRequestData(HWND hWnd);


//Delete UI
void DestroyUIElements(HWND hWnd);
void DestroyDataTable(HWND hWnd);
void DestroyIntTable(HWND hWnd);
void DestroyIntRequest(HWND hWnd);
void DestroySearchUI(HWND hWnd); 
void DestroyCheckBox(HWND hWnd);
void DestroySearchButton(HWND hWnd);
void DestroyAuthorization(HWND hWnd);


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


//All Data
std::vector<std::vector<std::wstring>> GetAllDataFromDatabase(sqlite3* db);
void AddAllToListView(HWND hListView);
void LoadAllDataIntoListView(HWND hListView);

bool ExportToExcel(sqlite3* db, const std::string& filename);


//
void CreateImage(HWND hWnd);
void InitializeGDIplus();
void CreatePaint(HWND hWnd);
void Cleanup();