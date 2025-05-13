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
	if (isRequestIntCreated)
	{

		if (hStaticTextRequest)
		{
			DestroyWindow(hStaticTextRequest);
			hStaticTextRequest = NULL;
		}

		if (hButtonOpenRequest)
		{
			DestroyWindow(hButtonOpenRequest);
			hButtonOpenRequest = NULL;
		}

		if (hButtonCloseRequest)
		{
			DestroyWindow(hButtonCloseRequest);
			hButtonCloseRequest = NULL;
		}

		if (hComboBoxRequest)
		{
			DestroyWindow(hComboBoxRequest);
			hComboBoxRequest = NULL;
		}

	}
}