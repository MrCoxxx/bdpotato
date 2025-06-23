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
static HWND editTuber;
static HWND editTaste;
static HWND editConsistency;
static HWND editDarkening;
static HWND editBoil;
static HWND editFriability;
static HWND editWater;
static HWND editBoiled;
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
static HWND editYield;
static HWND editStarch;
static HWND editDry;
static HWND editContent;
static HWND editRip;
static HWND editAbility;
static HWND editDuration;

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
static HWND checkBoxTuber;
static HWND checkBoxTaste;
static HWND checkBoxConsistency;
static HWND checkBoxDarkening;
static HWND checkBoxBoil;
static HWND checkBoxFriability;
static HWND checkBoxWater;
static HWND checkBoxBoiled;
static HWND checkBoxYield;
static HWND checkBoxStarch;
static HWND checkBoxDry;
static HWND checkBoxContent;
static HWND checkBoxRip;
static HWND checkBoxAbility;
static HWND checkBoxDuration;
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
static LRESULT statsCheckBoxTuber;
static LRESULT statsCheckBoxTaste;
static LRESULT statsCheckBoxConsistency;
static LRESULT statsCheckBoxDarkening;
static LRESULT statsCheckBoxBoil;
static LRESULT statsCheckBoxFriability;
static LRESULT statsCheckBoxWater;
static LRESULT statsCheckBoxBoiled;
static LRESULT statsCheckBoxWeight;


//Widgets
Widgets* textRequest;
Widgets* searchOpen;
Widgets* searchClose;
static HWND complite1;
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

LPCWSTR nameF[7] = { L"Очень длинная", L"Длинная", L"Длинноовальная" , L"Овальная", L"Округло-овальная", L"Округлая", L"Короткая"};

LPCWSTR nameP[9] = { L"Белая", L"Светло-жёлтая", L"Жёлтая" , L"Жёлто-коричневая", L"Розовая", L"Красная", L"Красно-фиолетовая", L"Сине-фиолетовая", L"Тёмно-фиолетовая" };

LPCWSTR namePu[9] = { L"Белая", L"Кремовая", L"Светло - жёлтая", L"Жёлтая", L"Тёмно - жёлтая", L"Антоциановая не сплошная слабая", L"Антоциановая не сплошная насыщенная", L"Антоциановая сплошная ненасыщенная", L"Антоциановая сплошная насыщенная" };

LPCWSTR nameE[5] = { L"Очень глубокие(2 и более мм)", L"глубокие(1,7–1,9 мм)", L"средние(1,4–1,6 мм)", L"мелкие(1,1–1,3 мм)", L"очень мелкие(менее 1 мм)" };

LPCWSTR nameS[5] = { L"Плоский", L"Мелкий", L"Средней глубины", L"Глубокий", L"Очень глубокий" };

LPCWSTR nameTu[3] = { L"Гладкая", L"Слабосетчатая", L"Сильносетчатая" };

LPCWSTR nameTa[5] = { L"Неприятный, горьковатый", L"Пресный", L"Удовлетворительный", L"Хороший", L"Отличный" };

LPCWSTR nameC[5] = { L"Волокнистая", L"Плотная", L"Умеренно плотная", L"Мягкая", L"Нежная" };

LPCWSTR nameD[5] = { L"Очень сильное", L"Сильное", L"Среднее", L"Слабое", L"Не темнеет" };

LPCWSTR nameBo[5] = { L"Не развариваются", L"Развариваются", L"Средне развариваются", L"Сильно развариваются", L"Очень сильно развариваются" };

LPCWSTR nameFr[5] = { L"Нерассыпчатая", L"Слабо рассыпчатая", L"Умеренно рассыпчатая", L"Мелкозернистая", L"Очень рассыпчатая с блеском, крупнозернистая" };

LPCWSTR nameW[5] = { L"Очень водянистые", L"Водянистые", L"Умеренно водянистые", L"Слабо водянистые", L"Не водянистые" };

LPCWSTR nameBoi[5] = { L"Очень неприятный, резкий", L"Неприятный, с примесью постороннего запаха", L"Удовлетворительный", L"Приятный", L"Очень приятный" };