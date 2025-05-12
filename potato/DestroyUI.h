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
	//InvalidateRect(hWnd, NULL, TRUE);
	//UpdateWindow(hWnd);
}