std::vector<HWND> ValueInt;
std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<int, HWND>>> DataInterface;

std::vector<int> IDInterfaceC(int quantity, std::unordered_map<int, HWND> IDInterface)
{
	int i = 0;

	std::vector<int> IDInt;

	if (!IDInterface.empty()) {
		while (IDInt.size() < quantity) {
			for (auto const& item : IDInterface) {
				const int id = item.first;
				if (i != id) {
					IDInt.push_back(i);
				}
				i++;
			}
			
		}
	}
	else
	{
		while(IDInt.size() < quantity) {
			IDInt.push_back(i);
			i++;
		}
	}

	return IDInt;

}

void Interface(LPCSTR form, std::vector<LPCSTR> name, int x, int y, int width, int height, HWND hWnd, std::vector <HMENU> hMenu, int stepX, int stepY, int quantity, std::string nameWnd)
{
	int n = 0;
	int m = 0;
	int sX = 0;
	int sY = 0;

	std::unordered_map<std::string, std::unordered_map<int, HWND>> FormInterface = DataInterface[nameWnd];

	std::unordered_map<int, HWND> IDInterface = DataInterface[nameWnd][form];

	std::vector<int> IDIntT = IDInterfaceC(quantity, IDInterface);

	for (int i = 0; i < quantity; i++) {

		IDInterface.insert_or_assign(IDIntT[i], CreateWindowA(
			form,
			name[n],
			WS_VISIBLE | WS_CHILD | ES_CENTER,
			x += sX, y += sY, width, height,
			hWnd,
			hMenu[m],
			NULL,
			NULL
			)
		);

		if (hMenu[0] != NULL) {
			m++;
		}

		if (sX == 0 && sY == 0) {
			sX += stepX;
			sY += stepY;
		}
		if (name[0] != "") {
			n++;
		}

		ValueInt.push_back(IDInterface[IDIntT[i]]);

	}

	FormInterface.insert_or_assign(form, IDInterface);

	DataInterface.insert_or_assign(nameWnd, FormInterface);

}

void ClearInterface(HWND hWnd, std::string nameWnd)
{

	auto firstLvl = DataInterface.find(nameWnd);

	auto& secondLvl = firstLvl->second;

	for (auto& thirdLvl : secondLvl) {
		for (auto& hwndLvl : thirdLvl.second) {
			DestroyWindow(hwndLvl.second);
		}
	}
	secondLvl.clear();

}

void CheckInt()
{
	for (size_t i = 0; i < ValueInt.size(); ++i) {

		HWND h = ValueInt[i];

		// Получаем заголовок окна
		char title[256];
		GetWindowTextA(h, title, 256);

		// Получаем имя класса
		char className[256];
		GetClassNameA(h, className, 256);

		// Формируем сообщение
		std::string msg = "Title:" + std::string(title) + "           ";
		msg += "Class:" + std::string(className) + "\n";

		OutputDebugStringA(msg.c_str());

		
	}

	ValueInt.clear();

}