// ���������� ����������
ULONG_PTR gdiplusToken;
Image* pImage = NULL;  // ������ ����������� ���������

void InitializeGDIplus()
{
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

void CreateImage(HWND hWnd)
{
    // �������� ������������� �����
    const wchar_t* imagePath = L"background_image.png";

    if (!PathFileExists(imagePath))
    {
        MessageBox(hWnd, L"���� ����������� �� ������!", L"������", MB_ICONERROR);
        return;
    }

    // �������� �����������
    pImage = new Image(imagePath);

    if (!pImage || pImage->GetLastStatus() != Ok)
    {
        MessageBox(hWnd, L"�� ������� ��������� �����������!", L"������", MB_ICONERROR);
        if (pImage) delete pImage;
        pImage = NULL;
        return;
    }

    // ��������� ����
    InvalidateRect(hWnd, NULL, TRUE);
}

void CreatePaint(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    if (pImage != NULL)
    {
        Graphics graphics(hdc);
        graphics.DrawImage(pImage, 400, 100, pImage->GetWidth(), pImage->GetHeight());
    }

    EndPaint(hWnd, &ps);
}

void Cleanup()
{
    if (pImage) delete pImage;
    GdiplusShutdown(gdiplusToken);
}