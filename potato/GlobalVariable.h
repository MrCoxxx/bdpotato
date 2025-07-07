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
static HWND hStaticTextTable2;
static HWND hStaticTextTable3;
static HWND hStaticTextTable4;
static HWND hStaticTextTable5;
static HWND hStaticTextTable6;
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
static HWND editWeightN;
static HWND editWeightK;
static HWND hButtonAuthorization;
static HWND editLogin;
static HWND editPassword;
static HWND hStaticLogin;
static HWND hStaticPassword;
static HWND editIDPotatoC;
static HWND editIDPotatoM;
static HWND editID;
static HWND editYieldN;
static HWND editYieldK;
static HWND editStarchN;
static HWND editStarchK;
static HWND editDryN;
static HWND editDryK;
static HWND editContentN;
static HWND editContentK;
static HWND editRip;
static HWND editAbility;
static HWND editDurationN;
static HWND editDurationK;
static HWND editCommercial;
static HWND editNon_marketable;
static HWND editNon_commercial;
static HWND editTubers;
static HWND editMarketability;
static HWND editSkin;
static HWND editBoilability;
static HWND editWateriness;
static HWND editSmell;
static HWND editDarkening_raw;
static HWND editDarkening_boiled;
static HWND editFlowering;
static HWND editRipeness;
static HWND editYield;
static HWND editCommercial_tubers;

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
static LRESULT statsCheckBoxTuber;
static LRESULT statsCheckBoxDarkening;
static LRESULT statsCheckBoxBoil;
static LRESULT statsCheckBoxWater;
static LRESULT statsCheckBoxBoiled;
static LRESULT statsCheckBoxWeight;
static LRESULT statsCheckBoxStarch;
static LRESULT statsCheckBoxDry;
static LRESULT statsCheckBoxContent;
static LRESULT statsCheckBoxRip;
static LRESULT statsCheckBoxDuration;


//NewStats
static LRESULT statsCheckBoxCommercial;
static LRESULT statsCheckBoxNon_marketable;
static LRESULT statsCheckBoxCommercial_tuber;
static LRESULT statsCheckBoxNon_commercial_tuber;
static LRESULT statsCheckBoxTubers;
static LRESULT statsCheckBoxMarketability;
static LRESULT statsCheckBoxProductivity;

static LRESULT statsCheckBoxForm;
static LRESULT statsCheckBoxPeel;
static LRESULT statsCheckBoxPulp;
static LRESULT statsCheckBoxEye;
static LRESULT statsCheckBoxStolon;
static LRESULT statsCheckBoxSkin;

static LRESULT statsCheckBoxBoilability;
static LRESULT statsCheckBoxConsistency;
static LRESULT statsCheckBoxFriability;
static LRESULT statsCheckBoxWateriness;
static LRESULT statsCheckBoxSmell;
static LRESULT statsCheckBoxTaste;
static LRESULT statsCheckBoxDarkening_raw;
static LRESULT statsCheckBoxDarkening_boiled;
static LRESULT statsCheckBoxField;
static LRESULT statsCheckBoxAbility;
static LRESULT statsCheckBoxFlowering;
static LRESULT statsCheckBoxRipeness;
static LRESULT statsCheckBoxYield;



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
static HWND staticCommercial;
static HWND staticNon_marketable;
static HWND staticNon_commercial;
static HWND staticTubers;
static HWND staticMarketability;
static HWND staticSkin;
static HWND staticBoilability;
static HWND staticWateriness;
static HWND staticSmell;
static HWND staticDarkening_raw;
static HWND staticDarkening_boiled;
static HWND staticFlowering;
static HWND staticRipeness;
static HWND staticYield;
static HWND staticCommercial_tubers;
static HWND staticFriability;
static HWND staticAbility;

static HWND comboboxSample;
static HWND comboboxOrigin;
static HWND comboboxVIGRR;
static HWND comboboxProductivity;
static HWND comboboxField;
static HWND comboboxForm;
static HWND comboboxPeel;
static HWND comboboxPulp;
static HWND comboboxEye;
static HWND comboboxStolon;
static HWND comboboxTuber;
static HWND comboboxTaste;
static HWND comboboxConsistency;
static HWND comboboxDarkening;
static HWND comboboxBoil;
static HWND comboboxFriability;
static HWND comboboxWater;
static HWND comboboxBoiled;
static HWND comboboxWeightN;
static HWND comboboxWeightK;
static HWND comboboxtonAuthorization;
static HWND comboboxLogin;
static HWND comboboxPassword;
static HWND comboboxticLogin;
static HWND comboboxticPassword;
static HWND comboboxIDPotatoC;
static HWND comboboxIDPotatoM;
static HWND comboboxID;
static HWND comboboxYieldN;
static HWND comboboxYieldK;
static HWND comboboxStarchN;
static HWND comboboxStarchK;
static HWND comboboxDryN;
static HWND comboboxDryK;
static HWND comboboxContentN;
static HWND comboboxContentK;
static HWND comboboxRip;
static HWND comboboxAbility;
static HWND comboboxDurationN;
static HWND comboboxDurationK;

//

static TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT) };

HWND hSearchWnd;

HWND hToolTip[10];

static HWND testPeel1;

HWND hTestWnd;

HWND hEditFilters[9];

HWND nameT[9];


HMENU CheckBox[4][10]{ {(HMENU)CheckBoxSample, (HMENU)CheckBoxVIGRR, (HMENU)CheckBoxOrigin, (HMENU)CheckBoxCommercial, (HMENU)CheckBoxNon_marketable,
						(HMENU)CheckBoxCommercial_tuber, (HMENU)CheckBoxNon_commercial_tuber, (HMENU)CheckBoxTubers, (HMENU)CheckBoxMarketability, (HMENU)CheckBoxProductivity },

					   {(HMENU)CheckBoxForm, (HMENU)CheckBoxPeel, (HMENU)CheckBoxPulp,
						(HMENU)CheckBoxEye, (HMENU)CheckBoxStolon, (HMENU)CheckBoxSkin},

					   {(HMENU)CheckBoxBoilability, (HMENU)CheckBoxConsistency, (HMENU)CheckBoxFriability, (HMENU)CheckBoxWateriness,
						(HMENU)CheckBoxSmell, (HMENU)CheckBoxTaste, (HMENU)CheckBoxDarkening_raw, (HMENU)CheckBoxDarkening_boiled},

					   {(HMENU)CheckBoxField, (HMENU)CheckBoxAbility, (HMENU)CheckBoxFlowering,
						(HMENU)CheckBoxRipeness, (HMENU)CheckBoxYield}
};

HWND EditZonePS[3];

HWND EditZonePL[7];

HWND EditZonePR[7];

HWND EditZoneM[6];

HWND EditZoneCL[8];

HWND EditZoneCR[8];

HWND EditZoneSL[5];

HWND EditZoneSR[5];



HWND checkBoxP[10];

HWND checkBoxM[6];

HWND checkBoxC[8];

HWND checkBoxS[5];



LPCWSTR checkBoxNameP[10]{ L"Образец", L"№ по каталогу ВИГРР", L"Происхождение", L"Товарных клубней в клоне, шт.", L"Нетоварных клубней в клоне, шт.", L"Масса товарного клубня, г", L"Масса нетоварного клубня, г", L"Клубней в клоне, шт", L"Товарность, %", L"Урожайность, кг/м2" };

LPCWSTR helpText[10]{
	L"Пример ввода данных: Арамис,Королева Анна,10y041 (без пробела с большой буквы, в названиях с числами раскладка на кирилице для набора букв)",
	L"Пример ввода данных: бн,Без номера (без пробела с большой буквы, в названиях с числами раскладка на кирилице для набора букв)",
	L"Пример ввода данных: Германия,Беларусь (без пробела с большой буквы, в названиях с числами раскладка на кирилице для набора букв)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)",
	L"Пример ввода данных: В левое поле вводим минимальное число(ОТ), в правое окно вводим максимальное число(ДО)"
};

//Раскоментить когда будут данные
//LPCWSTR checkBoxNameM[6]{ L"Форма",  L"Окраска кожуры",  L"Окраска мякоти",  L"Глубина глазков",  L"Глубина столонного следа",  L"Поверхность кожуры клубня" };
//
//LPCWSTR checkBoxNameC[8]{ L"Разваримость клубней",  L"Консистенция мякоти",  L"Рассыпчатость",  L"Водянистость клубней",  L"Запах варёного картофеля",  L"Вкус варёного картофеля",  L"Потемнение мякоти сырого картофеля",  L"Потемнение мякоти варёного картофеля" };
//
//LPCWSTR checkBoxNameS[5]{ L"Полевая устойчивость к фитофторозу, балл",  L"Способность к ягодообразованию от самоопыления (балл)",  L"Продолжительность цветения,дни",  L"Группа спелости",  L"Урожайность, %" };

//ХЗ зачем
//HWND* nameT = new HWND[al];
//HWND* hEditFilters = new HWND[al];
//LPCWSTR nameW[8] = { L"Форма", L"Окраска кожуры", L"Окраска мякоти", L"Глубина глазков", L"Глубина столонного следа", L"Вкус", L"Консистенция", L"Потемнение после варки" };


//Раскоментить когда будут данные
//LPCWSTR nameTa[5] = { L"1 - Неприятный, горьковатый", L"3 - Пресный", L"5 - Удовлетворительный", L"7 - Хороший", L"9 - Отличный" };
//
//LPCWSTR nameC[5] = { L"1 - Волокнистая", L"3 - Плотная", L"5 - Умеренно плотная", L"7 - ягкая", L"9 - Нежная" };
//
//LPCWSTR nameD[5] = { L"1 - Очень сильное", L"3 - Сильное", L"5 - Среднее", L"7 - Слабое", L"9 - Не темнеет" };
//
//LPCWSTR nameBo[5] = { L"1 - Не развариваются", L"3 - Развариваются", L"5 - Средне развариваются", L"7 - Сильно развариваются", L"9 - Очень сильно развариваются" };
//
//LPCWSTR nameFr[5] = { L"1 - Нерассыпчатая", L"3 - Слабо рассыпчатая", L"5 - Умеренно рассыпчатая", L"7 - Мелкозернистая", L"9 - Очень рассыпчатая с блеском, крупнозернистая" };
//
//LPCWSTR nameW[5] = { L"1 - Очень водянистые", L"3 - Водянистые", L"5 - Умеренно водянистые", L"7 - Слабо водянистые", L"9 - Не водянистые" };
//
//LPCWSTR nameBoi[5] = { L"1 - Очень неприятный, резкий", L"3 - Неприятный, с примесью постороннего запаха", L"5 - Удовлетворительный", L"7 - Приятный", L"9 - Очень приятный" };
//
//LPCWSTR nameRip[8] = { L"01 — очень ранний", L"02 — от очень раннего до раннего", L"03 — ранний", L"04 — среднеранний", L"05 — среднеспелый", L"06 — среднепоздние", L"07 — поздние", L"09 — очень поздние" };
//
//LPCWSTR nameAb[5] = { L"1 — ягоды отсутствуют", L"3 — единичное ягодообразование", L"5 — мало", L"7 — много", L"9 — очень много" };
//
//
//
//LPCWSTR nameF[7] = { L"1 - Очень длинная", L"2 - Длинная", L"3 - Длинноовальная" , L"4 - Овальная", L"5 - Округло-овальная", L"6 - Округлая", L"7 - Короткая" };
//
//LPCWSTR nameP[9] = { L"1 - Белая", L"2 - Светло-желтая", L"3 - Желтая" , L"5 - Желто-коричневая", L"6 - Розовая", L"7 - Красная", L"8 - Красно-фиолетовая", L"9 - Сине-фиолетовая", L"10 - Тёмно-фиолетовая" };
//
//LPCWSTR namePu[9] = { L"1 - Белая", L"2 - Кремовая", L"3 - Светло - желтая", L"4 - Желтая", L"5 - Темно - желтая", L"6 - Антоциановая не сплошная слабая", L"7 - Антоциановая не сплошная насыщенная", L"8 - Антоциановая сплошная ненасыщенная", L"9 - Антоциановая сплошная насыщенная" };
//
//LPCWSTR nameE[5] = { L"Очень глубокие(2 и более мм)", L"глубокие(1,7–1,9 мм)", L"средние(1,4–1,6 мм)", L"мелкие(1,1–1,3 мм)", L"очень мелкие(менее 1 мм)" };
//
//LPCWSTR nameS[5] = { L"1 - Плоский", L"3 - Мелкий", L"5 - Средней глубины", L"7 - Глубокий", L"8 - Очень глубокий" };
//
//LPCWSTR nameTu[3] = { L"3 - Гладкая", L"5 - Слабосетчатая", L"7 - Сильносетчатая" };