void Add(HWND hWnd)
{
	AddStatic(hWnd);
	AddButton(hWnd);
	AddEditzone(hWnd);
	//AddComboboxzone(hWnd);
	//AddDataComboboxzone(hWnd);

	CheckInt();
}

void ClearAddData() {
	SetWindowText(editSample, L"");
	SetWindowText(editVIGRR, L"");
	SetWindowText(editOrigin, L"");
	SetWindowText(editCommercial_tubers, L"");
	SetWindowText(editNon_marketable, L"");
	SetWindowText(editCommercial, L"");
	SetWindowText(editNon_commercial, L"");
	SetWindowText(editTubers, L"");
	SetWindowText(editMarketability, L"");
	SetWindowText(editProductivity, L"");
	SetWindowText(editForm, L"");
	SetWindowText(editPeel, L"");
	SetWindowText(editPulp, L"");
	SetWindowText(editEye, L"");
	SetWindowText(editStolon, L"");
	SetWindowText(editSkin, L"");
	SetWindowText(editBoilability, L"");
	SetWindowText(editConsistency, L"");
	SetWindowText(editFriability, L"");
	SetWindowText(editWateriness, L"");
	SetWindowText(editSmell, L"");
	SetWindowText(editTaste, L"");
	SetWindowText(editDarkening_raw, L"");
	SetWindowText(editDarkening_boiled, L"");
}

void AddStatic(HWND hWnd) 
{

	Interface("static", staticPotato, 15, 15, 220, 20, hWnd, hNULL, 0, 65, 10);

	Interface("static", staticMorh, 250, 15, 200, 20, hWnd, hNULL, 0, 65, 6);

	Interface("static", staticCul, 465, 15, 220, 20, hWnd, hNULL, 0, 65, 8);

	//Interface("static", staticStand, 680, 15, 220, 20, hWnd, hNULL, 0, 65, 5);
		
}

void AddButton(HWND hWnd)
{

	Interface("button", compliteBTN, 15, 665, 650, 30, hWnd, compliteAddBTNC, 0, 0, 1);

}

void AddEditzone(HWND hWnd)
{

	Interface("edit", editName, 15, 45, 200, 20, hWnd, hNULL, 0, 65, 10);

	Interface("edit", editName, 250, 45, 200, 20, hWnd, hNULL, 0, 65, 6);

	Interface("edit", editName, 465, 45, 220, 20, hWnd, hNULL, 0, 65, 8);

	//Interface("edit", editName, 680, 45, 220, 20, hWnd, hNULL, 0, 65, 5);

}











void AddComboboxzone(HWND hWnd)
{
	comboboxForm = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 110, 200, 200,
		hWnd,
		(HMENU)CheckBoxForm,
		NULL,
		NULL
	);
	comboboxPeel = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 175, 200, 200,
		hWnd,
		(HMENU)CheckBoxPeel,
		NULL,
		NULL
	);
	comboboxPulp = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 230, 200, 200,
		hWnd,
		(HMENU)CheckBoxPulp,
		NULL,
		NULL
	);
	comboboxEye = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 295, 200, 200,
		hWnd,
		(HMENU)CheckBoxEye,
		NULL,
		NULL
	);
	comboboxStolon = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		250, 370, 200, 200,
		hWnd,
		(HMENU)CheckBoxStolon,
		NULL,
		NULL
	);
	comboboxTaste = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 110, 185, 200,
		hWnd,
		(HMENU)CheckBoxTaste,
		NULL,
		NULL
	);
	comboboxConsistency = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 175, 185, 200,
		hWnd,
		(HMENU)CheckBoxConsistency,
		NULL,
		NULL
	);
	comboboxDarkening = CreateWindow(
		L"combobox",
		L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_VSCROLL,
		465, 230, 185, 200,
		hWnd,
		(HMENU)CheckBoxDarkening,
		NULL,
		NULL
	);
}

void AddDataComboboxzone(HWND hWnd) {
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxDarkening, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxConsistency, CB_ADDSTRING, 0, (LPARAM)nameC[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxTaste, CB_ADDSTRING, 0, (LPARAM)nameTa[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxStolon, CB_ADDSTRING, 0, (LPARAM)nameS[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxEye, CB_ADDSTRING, 0, (LPARAM)nameD[i]);
	}
	for (int i = 0; i < 5; i++) {
		SendMessageW(comboboxPulp, CB_ADDSTRING, 0, (LPARAM)nameE[i]);
	}
	for (int i = 0; i < 9; i++) {
		SendMessageW(comboboxPeel, CB_ADDSTRING, 0, (LPARAM)namePu[i]);
	}
	for (int i = 0; i < 9; i++) {
		SendMessageW(comboboxForm, CB_ADDSTRING, 0, (LPARAM)nameP[i]);
	}
}