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

	if (editSample)
	{
		DestroyWindow(editSample);
		editSample = NULL;
		statsCheckBoxSample = NULL;
	}
	if (editOrigin)
	{
		DestroyWindow(editOrigin);
		editOrigin = NULL;
		statsCheckBoxOrigin = NULL;
	}
	if (editVIGRR)
	{
		DestroyWindow(editVIGRR);
		editVIGRR = NULL;
		statsCheckBoxVIGRR = NULL;
	}
	if (editProductivity)
	{
		DestroyWindow(editProductivity);
		editProductivity = NULL;
		statsCheckBoxProductivity = NULL;
	}
	if (editField)
	{
		DestroyWindow(editField);
		editField = NULL;
		statsCheckBoxField = NULL;
	}
	if (editForm)
	{
		DestroyWindow(editForm);
		editForm = NULL;
		statsCheckBoxForm = NULL;
	}
	if (editPeel)
	{
		DestroyWindow(editPeel);
		editPeel = NULL;
		statsCheckBoxPeel = NULL;
	}
	if (editPulp)
	{
		DestroyWindow(editPulp);
		editPulp = NULL;
		statsCheckBoxPulp = NULL;
	}
	if (editEye)
	{
		DestroyWindow(editEye);
		editEye = NULL;
		statsCheckBoxEye = NULL;
	}
	if (editStolon)
	{
		DestroyWindow(editStolon);
		editStolon = NULL;
		statsCheckBoxStolon = NULL;
	}
	if (editTaste)
	{
		DestroyWindow(editTaste);
		editTaste = NULL;
		statsCheckBoxTaste = NULL;
	}
	if (editConsistency)
	{
		DestroyWindow(editConsistency);
		editConsistency = NULL;
		statsCheckBoxConsistency = NULL;
	}
	if (editDarkening)
	{
		DestroyWindow(editDarkening);
		editDarkening = NULL;
		statsCheckBoxDarkening = NULL;
	}
	if (editWeight)
	{
		DestroyWindow(editWeight);
		editWeight = NULL;
		statsCheckBoxWeight = NULL;
	}

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