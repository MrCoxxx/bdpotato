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
		textRequest = NULL;
	}

	if (searchOpen)
	{
		searchOpen->Destroy();
		searchOpen = NULL;
	}


	
}

void DestroySearchUI(HWND hWnd) 
{
	DestroyCheckBox(hWnd);
	DestroySearchButton(hWnd);
}

void DestroyCheckBox(HWND hWnd) 
{

	/*if (CheckBox1)
	{
		CheckBox1->Destroy();
		CheckBox1 = NULL;
	}

	if (CheckBox2)
	{
		CheckBox2->Destroy();
		CheckBox2 = NULL;
	}

	if (CheckBox3)
	{
		CheckBox3->Destroy();
		CheckBox3 = NULL;
	}

	if (CheckBox4)
	{
		CheckBox4->Destroy();
		CheckBox4 = NULL;
	}*/

}

void DestroySearchButton(HWND hWnd) 
{

	if (complite)
	{
		complite->Destroy();
		complite = NULL;
	}

	if (searchClose)
	{
		searchClose->Destroy();
		searchClose = NULL;
	}

	if (min)
	{
		min->Destroy();
		min = NULL;
	}

	if (avg)
	{
		avg->Destroy();
		avg = NULL;
	}

	if (max)
	{
		max->Destroy();
		max = NULL;
	}

	/*if (edit)
	{
		edit->Destroy();
		edit = NULL;
	}*/
}