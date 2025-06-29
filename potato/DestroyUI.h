void DestroyUIElements(HWND hWnd)
{
	DestroyIntTable(hWnd);
	DestroyIntRequest(hWnd);
	DestroyDataTable(hWnd);
}

void DestroyDataTable(HWND hWnd) 
{

	if (hListView)
	{
		DestroyWindow(hListView);
		hListView = NULL;
	}

}

void DestroyAuthorization(HWND hWnd) {

	if (hButtonAuthorization)
	{
		DestroyWindow(hButtonAuthorization);
		hButtonAuthorization = NULL;
	}

	if (editLogin)
	{
		DestroyWindow(editLogin);
		editLogin = NULL;
	}

	if (editPassword)
	{
		DestroyWindow(editPassword);
		editPassword = NULL;
	}

	if (hStaticLogin)
	{
		DestroyWindow(hStaticLogin);
		hStaticLogin = NULL;
	}

	if (hStaticPassword)
	{
		DestroyWindow(hStaticPassword);
		hStaticPassword = NULL;
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
	statsCheckBoxSample = NULL;
	statsCheckBoxVIGRR = NULL;
	statsCheckBoxOrigin = NULL;
	statsCheckBoxCommercial = NULL;
	statsCheckBoxNon_marketable = NULL;
	statsCheckBoxCommercial_tuber = NULL;
	statsCheckBoxNon_commercial_tuber = NULL;
	statsCheckBoxTubers = NULL;
	statsCheckBoxMarketability = NULL;
	statsCheckBoxProductivity = NULL;

	for (int i = 0; i < 10; i++) {
		if (i < 3) {
			DestroyWindow(EditZonePS[i]);
			EditZonePS[i] = NULL;
		}
		if (i < 7) {
			DestroyWindow(EditZonePL[i]);
			DestroyWindow(EditZonePR[i]);
			EditZonePL[i] = NULL;
			EditZonePR[i] = NULL;
		}
		if (i < 6) {
			DestroyWindow(EditZoneM[i]);
			EditZoneM[i] = NULL;
		}
		if (i < 8) {
			DestroyWindow(EditZoneCL[i]);
			DestroyWindow(EditZoneCR[i]);
			EditZoneCL[i] = NULL;
			EditZoneCR[i] = NULL;
		}
		if (i < 5) {
			DestroyWindow(EditZoneSL[i]);
			DestroyWindow(EditZoneSR[i]);
			EditZoneSL[i] = NULL;
			EditZoneSR[i] = NULL;
		}
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