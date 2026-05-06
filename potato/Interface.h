std::vector<HWND> ValueInt;

void Interface(LPCSTR form, std::vector<LPCSTR> name, int x, int y, int width, int height, HWND hWnd, std::vector <HMENU> hMenu, int stepX, int stepY, int quantity)
{
	int n = 0;
	int m = 0;
	int sX = 0;
	int sY = 0;
	for (int i = 0; i < quantity; i++){
		ValueInt.push_back(CreateWindowA(
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

		if (hMenu[0]!=NULL) {
			m++;
		}

		if (sX == 0 && sY == 0) {
			sX += stepX;
			sY += stepY;
		}
		if (name[0] != "") {
			n++;
		}
		
	}

}

void ClearInterface(HWND hWnd) 
{
	for (int i = 0; i < ValueInt.size(); i++) {
		DestroyWindow(ValueInt[i]);
	}

	ValueInt.clear();

}


void CheckInt()
{
	for (size_t i = 0; i < ValueInt.size(); ++i) {
		HWND h = ValueInt[i];

		// Получаем заголовок окна
		wchar_t title[256];
		GetWindowTextW(h, title, 256);

		// Получаем имя класса
		wchar_t className[256];
		GetClassNameW(h, className, 256);

		// Формируем сообщение
		std::wstring msg = L"Title:" + std::wstring(title) + L"           ";
		msg += L"Class:" + std::wstring(className) + L"\n";

		OutputDebugStringW(msg.c_str());
	}
}