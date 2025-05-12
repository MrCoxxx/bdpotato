void DestroyUIElements(HWND hWnd)
{
	if (hStaticText)
	{
		DestroyWindow(hStaticText);
		hStaticText = NULL;
	}

	if (hButton)
	{
		DestroyWindow(hButton);
		hButton = NULL;
	}

	if (hComboBox)
	{
		DestroyWindow(hComboBox);
		hComboBox = NULL;
	}

	DestroyTable(hWnd);

	//InvalidateRect(hWnd, NULL, TRUE);
	//UpdateWindow(hWnd);
}

void DestroyTable(HWND hWnd) 
{

	if (hListView)
	{
		DestroyWindow(hListView);
		hListView = NULL;
	}

}