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
static LRESULT statsCheckBoxYield;
static LRESULT statsCheckBoxStarch;
static LRESULT statsCheckBoxDry;
static LRESULT statsCheckBoxContent;
static LRESULT statsCheckBoxRip;
static LRESULT statsCheckBoxAbility;
static LRESULT statsCheckBoxDuration;


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

std::string potato;


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
//LPCWSTR nameW[8] = { L"�����", L"������� ������", L"������� ������", L"������� �������", L"������� ���������� �����", L"����", L"������������", L"���������� ����� �����" };

LPCWSTR nameF[7] = { L"1 - ����� �������", L"2 - �������", L"3 - ��������������" , L"4 - ��������", L"5 - �������-��������", L"6 - ��������", L"7 - ��������"};

LPCWSTR nameP[9] = { L"1 - �����", L"2 - ������-�����", L"3 - Ƹ����" , L"5 - Ƹ���-����������", L"6 - �������", L"7 - �������", L"8 - ������-����������", L"9 - ����-����������", L"10 - Ҹ���-����������" };

LPCWSTR namePu[9] = { L"1 - �����", L"2 - ��������", L"3 - ������ - �����", L"4 - Ƹ����", L"5 - Ҹ��� - �����", L"6 - ������������ �� �������� ������", L"7 - ������������ �� �������� ����������", L"8 - ������������ �������� ������������", L"9 - ������������ �������� ����������" };

LPCWSTR nameE[5] = { L"����� ��������(2 � ����� ��)", L"��������(1,7�1,9 ��)", L"�������(1,4�1,6 ��)", L"������(1,1�1,3 ��)", L"����� ������(����� 1 ��)" };

LPCWSTR nameS[5] = { L"1 - �������", L"3 - ������", L"5 - ������� �������", L"7 - ��������", L"8 - ����� ��������" };

LPCWSTR nameTu[3] = { L"3 - �������", L"5 - �������������", L"7 - ��������������" };

LPCWSTR nameTa[5] = { L"1 - ����������, �����������", L"3 - �������", L"5 - ������������������", L"7 - �������", L"9 - ��������" };

LPCWSTR nameC[5] = { L"1 - �����������", L"3 - �������", L"5 - �������� �������", L"7 - �����", L"9 - ������" };

LPCWSTR nameD[5] = { L"1 - ����� �������", L"3 - �������", L"5 - �������", L"7 - ������", L"9 - �� �������" };

LPCWSTR nameBo[5] = { L"1 - �� �������������", L"3 - �������������", L"5 - ������ �������������", L"7 - ������ �������������", L"9 - ����� ������ �������������" };

LPCWSTR nameFr[5] = { L"1 - �������������", L"3 - ����� �����������", L"5 - �������� �����������", L"7 - ��������������", L"9 - ����� ����������� � �������, ���������������" };

LPCWSTR nameW[5] = { L"1 - ����� ����������", L"3 - ����������", L"5 - �������� ����������", L"7 - ����� ����������", L"9 - �� ����������" };

LPCWSTR nameBoi[5] = { L"1 - ����� ����������, ������", L"3 - ����������, � �������� ������������ ������", L"5 - ������������������", L"7 - ��������", L"9 - ����� ��������" };

LPCWSTR nameRip[9] = { L"01 � ����� ������", L"02 � �� ����� ������� �� �������", L"03 � ������", L"04 � ������������", L"05 � ������������", L"06 � �������������", L"07 � �������", L"09 � ����� �������" };

LPCWSTR nameAb[5] = { L"1 � ����� �����������", L"3 � ��������� ����������������", L"5 � ����", L"7 � �����", L"9 � ����� �����" };