static HINSTANCE hInstance;
static BOOL isTableIntCreated = TRUE;
static BOOL isRequestIntCreated = FALSE;
static BOOL isTableCreated = FALSE;
static BOOL isSearchUI = FALSE;
static BOOL secondWnd = FALSE;
static BOOL addWnd = FALSE;
static BOOL editWnd = FALSE;
static BOOL testWnd = FALSE;
static BOOL allStatsChecked = FALSE;
static HWND hListView;
static HWND hComboBoxTable;
static HWND hStaticTextTable;
static HWND hStaticTextTable1;
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
static HWND editWeight1;
static HWND hButtonAuthorization;
static HWND editLogin;
static HWND editPassword;
static HWND hStaticLogin;
static HWND hStaticPassword;
static HWND editIDPotatoC;
static HWND editIDPotatoM;
static HWND editID;

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
static LRESULT statsCheckBoxPeel1;
static LRESULT statsCheckBoxPeel2;
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

//Save Variable
std::wstring Sample;
std::wstring Origin;
std::wstring VIGRR;
std::wstring Productivity;
std::wstring Field;
std::wstring Form;
std::wstring Peel;
std::wstring Pulp;
std::wstring Eye;
std::wstring Stolon;
std::wstring Taste;
std::wstring Consistency;
std::wstring Darkening;
std::wstring Weight;
std::wstring IDPotatoC;
std::wstring IDPotatoM;
std::wstring ID;

std::string utf8_Sample;
std::string utf8_Origin;
std::string utf8_VIGRR;
std::string utf8_Productivity;
std::string utf8_Field;
std::string utf8_Form;
std::string utf8_Peel;
std::string utf8_Pulp;
std::string utf8_Eye;
std::string utf8_Stolon;
std::string utf8_Taste;
std::string utf8_Consistency;
std::string utf8_Darkening;
std::string utf8_Weight;
std::string utf8_IDPotatoC;
std::string utf8_IDPotatoM;
std::string utf8_ID;

//Static
static HWND staticSample;
static HWND staticOrigin;
static HWND staticVIGRR;
static HWND staticProductivity;
static HWND staticField;
static HWND staticForm;
static HWND staticPeel;
static HWND staticPulp;
static HWND staticEye;
static HWND staticStolon;
static HWND staticTaste;
static HWND staticConsistency;
static HWND staticDarkening;
static HWND staticWeight;
static HWND statictonAuthorization;
static HWND staticLogin;
static HWND staticPassword;
static HWND staticticLogin;
static HWND staticticPassword;
static HWND staticIDPotatoC;
static HWND staticIDPotatoM;
static HWND staticID;

std::string potato;


//

static HWND testPeel1;
static HWND testPeel2;
static HWND testPeel3;
static HWND testPeel4;
static HWND testPeel5;
static HWND testPeel6;
static HWND testPeel7;
static HWND testPeel8;
static HWND testPeel9;

HWND hTestWnd;


HWND hEditFilters[9];

HWND nameT[9];

//HWND* nameT = new HWND[al];
//HWND* hEditFilters = new HWND[al];
//LPCWSTR nameW[8] = { L"Форма", L"Окраска кожуры", L"Окраска мякоти", L"Глубина глазков", L"Глубина столонного следа", L"Вкус", L"Консистенция", L"Потемнение после варки" };

LPCWSTR nameF[7] = { L"очень длинная", L"длинная", L"длинноовальная" , L"овальная", L"округло-овальная", L"округлая", L"короткая"};

LPCWSTR nameP[9] = { L"белая", L"Светло-жёлтая", L"жёлтая" , L"Жёлто-коричневая", L"Розовая", L"Красная", L"Красно-фиолетовая", L"Сине-фиолетовая", L"Тёмно-фиолетовая" };

LPCWSTR namePu[9] = { L"белая", L"кремовая", L"светло - жёлтая", L"жёлтая", L"тёмно - жёлтая", L"антоциановая не сплошная слабая", L"антоциановая не сплошная насыщенная", L"антоциановая сплошная ненасыщенная", L"антоциановая сплошная насыщенная" };

LPCWSTR nameE[5] = { L"очень глубокие(2 и более мм)", L"глубокие(1,7–1,9 мм)", L"средние(1,4–1,6 мм)", L"мелкие(1,1–1,3 мм)", L"очень мелкие(менее 1 мм)" };

LPCWSTR nameS[5] = { L"плоский", L"мелкий", L"средней глубины", L"глубокий", L"очень глубокий" };

LPCWSTR nameTa[5] = { L"неприятный, горьковатый", L"пресный", L"удовлетворительный", L"хороший", L"отличный" };

LPCWSTR nameC[5] = { L"волокнистая", L"плотная", L"умеренно плотная", L"мягкая", L"нежная" };

LPCWSTR nameD[5] = { L"очень сильное", L"сильное", L"среднее", L"слабое", L"не темнеет" };