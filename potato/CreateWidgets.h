class Widgets 
{
public:

	const char *type;
	const char *name;
	DWORD style;
	int x, y, wight, height;
	HWND wnd;
	HMENU command;
	HINSTANCE hinst;
	LPVOID param;
	HWND hwnd;

	Widgets(const char *type_, const char *name_, DWORD style_, int x_, int y_, int wight_, int height_, HWND wnd_, HMENU command_, HINSTANCE hinst_, LPVOID param_)
		: type(type_), name(name_), style(style_), x(x_), y(y_), wight(wight_), height(height_), wnd(wnd_), command(command_), hinst(hinst_), param(param_)
	{
		hwnd = CreateWindowA(type, name, style, x, y, wight, height, wnd, command, hinst, param);
	}

	void Destroy() 
	{

		if (hwnd)
		{
			DestroyWindow(hwnd);
			hwnd = NULL;
		}

	}
};

