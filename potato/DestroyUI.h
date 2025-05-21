void DestroyUIElements(HWND hWnd)
{
	DestroyIntTable(hWnd);
	DestroyIntRequest(hWnd);
	DestroyDataTable(hWnd);

	//InvalidateRect(hWnd, NULL, TRUE);
	//UpdateWindow(hWnd);
}

void DestroyDataTable(HWND hWnd) 
{

	if (hListView)
	{
		DestroyWindow(hListView);
		hListView = NULL;
	}

}

void DestroyIntTable(HWND hWnd) 
{
	if (isTableIntCreated) 
	{

		if (hStaticTextTable)
		{
			DestroyWindow(hStaticTextTable);
			hStaticTextTable = NULL;
		}

		if (hButtonOpenTable)
		{
			DestroyWindow(hButtonOpenTable);
			hButtonOpenTable = NULL;
		}

		if (hButtonCloseTable)
		{
			DestroyWindow(hButtonCloseTable);
			hButtonCloseTable = NULL;
		}

		if (hComboBoxTable)
		{
			DestroyWindow(hComboBoxTable);
			hComboBoxTable = NULL;
		}

	}
}

void DestroyIntRequest(HWND hWnd)
{
	if (textRequest)
	{
		textRequest->Destroy();
		textRequest = nullptr;
	}

	if (searchOpen)
	{
		searchOpen->Destroy();
		searchOpen = nullptr;
	}


	
}

void DestroySearchUI(HWND hWnd) 
{
	DestroyCheckBox(hWnd);
	DestroySearchButton(hWnd);
}

void DestroyCheckBox(HWND hWnd) 
{

	if (CheckBox1)
	{
		CheckBox1->Destroy();
		CheckBox1 = nullptr;
	}

	if (CheckBox2)
	{
		CheckBox2->Destroy();
		CheckBox2 = nullptr;
	}

	if (CheckBox3)
	{
		CheckBox3->Destroy();
		CheckBox3 = nullptr;
	}

	if (CheckBox4)
	{
		CheckBox4->Destroy();
		CheckBox4 = nullptr;
	}

}

void DestroySearchButton(HWND hWnd) 
{

	if (complite)
	{
		complite->Destroy();
		complite = nullptr;
	}

	if (searchClose)
	{
		searchClose->Destroy();
		searchClose = nullptr;
	}

	if (min)
	{
		min->Destroy();
		min = nullptr;
	}

	if (avg)
	{
		avg->Destroy();
		avg = nullptr;
	}

	if (max)
	{
		max->Destroy();
		max = nullptr;
	}

	if (edit)
	{
		edit->Destroy();
		edit = nullptr;
	}
}