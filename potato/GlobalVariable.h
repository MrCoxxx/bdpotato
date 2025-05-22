static HINSTANCE hInstance;
static BOOL isTableIntCreated = TRUE;
static BOOL isRequestIntCreated = FALSE;
static BOOL isTableCreated = FALSE;
static BOOL isSearchUI = FALSE;
static BOOL secondWnd = FALSE;
static BOOL allStatsChecked = FALSE;
static HWND hListView;
static HWND hComboBoxTable;
static HWND hStaticTextTable;
static HWND hButtonOpenTable;
static HWND hButtonCloseTable;
static HWND hComboBoxRequest;
static LRESULT idComboBox;
static sqlite3* db = NULL;

//EditZone
static HWND editSample;
static HWND editOrigin;
static HWND editVIGRR;
static HWND editProductivity;
static HWND editField;
static HWND editForm;
static HWND editPeel;
static HWND editPulp;
static HWND editEye;
static HWND editStolon;
static HWND editTaste;
static HWND editConsistency;
static HWND editDarkening;
static HWND editWeight;

//CheckBox
static HWND checkBoxSample;
static HWND checkBoxOrigin;
static HWND checkBoxVIGRR;
static HWND checkBoxProductivity;
static HWND checkBoxField;
static HWND checkBoxForm;
static HWND checkBoxPeel;
static HWND checkBoxPulp;
static HWND checkBoxEye;
static HWND checkBoxStolon;
static HWND checkBoxTaste;
static HWND checkBoxConsistency;
static HWND checkBoxDarkening;
static HWND checkBoxWeight;

//StatsCheckbox
static LRESULT statsCheckBoxSample;
static LRESULT statsCheckBoxOrigin;
static LRESULT statsCheckBoxVIGRR;
static LRESULT statsCheckBoxProductivity;
static LRESULT statsCheckBoxField;
static LRESULT statsCheckBoxForm;
static LRESULT statsCheckBoxPeel;
static LRESULT statsCheckBoxPulp;
static LRESULT statsCheckBoxEye;
static LRESULT statsCheckBoxStolon;
static LRESULT statsCheckBoxTaste;
static LRESULT statsCheckBoxConsistency;
static LRESULT statsCheckBoxDarkening;
static LRESULT statsCheckBoxWeight;

//Widgets
Widgets* textRequest;
Widgets* searchOpen;
Widgets* searchClose;
Widgets* complite;
Widgets* min;
Widgets* avg;
Widgets* max;

//RequestData
std::wstring sample;
std::string utf8_sample;
std::wstring origin;
std::string utf8_origin;
std::wstring VIGRR;
std::string utf8_VIGRR;
std::wstring productivity;
std::string utf8_productivity;
std::wstring field;
std::string utf8_field;
std::wstring form;
std::string utf8_form;
std::wstring peel;
std::string utf8_peel;
std::wstring pulp;
std::string utf8_pulp;
std::wstring eye;
std::string utf8_eye;
std::wstring stolon;
std::string utf8_stolon;
std::wstring taste;
std::string utf8_taste;
std::wstring consistency;
std::string utf8_consistency;
std::wstring darkening;
std::string utf8_darkening;
std::wstring weight;
std::string utf8_weight;