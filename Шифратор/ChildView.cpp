
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "Шифратор.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

HBRUSH CChildView::OnCtlColor(CDC* pDC, CWnd *pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(80, 80, 80));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CDC *cDC = GetDC();
	HDC hDC = cDC->m_hDC;
	INT Horres = GetDeviceCaps(hDC, HORZRES);
	INT Vertres = GetDeviceCaps(hDC, VERTRES);
	ReleaseDC(cDC);

	theApp.pFrame->SetWindowPos(&wndTop, Horres / 2 - 500, Vertres / 2 - 375, 1000, 700, SWP_SHOWWINDOW);


	/*----------------------------------------------------------------------------------------------------------------
	--------------------------Следующие строки создают интерфейс для шифров Виженера и Плейфера-----------------------
	------------------------------------------------------------------------------------------------------------------*/
	if (Lable_vvod != NULL) Lable_vvod->Create(L"Введите текст, который требуется зашифровать или расшифровать:",
		WS_CHILD | WS_VISIBLE, CRect(10, 5, 480, 20), this, NULL);

	if (Edit_vvod != NULL) {
		Edit_vvod->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL,
			theApp.NULL_RECT, this, NULL);
		Edit_vvod->SetWindowPos(&wndTop, 10, 30, 470, 540, SWP_SHOWWINDOW);
		//Edit_vvod->ModifyStyleEx(NULL, WS_EX_RIGHTSCROLLBAR | WS_EX_STATICEDGE | WS_EX_CLIENTEDGE, NULL);
	}
	if (Lable_kluch != NULL) {
		Lable_kluch->Create(L"Введите ключ:", WS_CHILD | WS_VISIBLE,
			theApp.NULL_RECT, this, NULL);
		Lable_kluch->SetWindowPos(&wndTop, 370, 580, 100, 20, SWP_SHOWWINDOW);
	}
	if (Edit_kluch != NULL) {
		Edit_kluch->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
			theApp.NULL_RECT, this, NULL);
		Edit_kluch->SetWindowPos(&wndTop, 480, 580, 130, 20, SWP_SHOWWINDOW);
	}
	if (Spisok_shifrov != NULL) {
		Spisok_shifrov->Create(WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
			theApp.NULL_RECT, this, NULL);
		Spisok_shifrov->SetWindowPos(&wndTop, 370, 605, 240, 20, SWP_SHOWWINDOW);
		Spisok_shifrov->AddString(L"Шифр Виженера для английского");
		Spisok_shifrov->AddString(L"Шифр Виженера для русского");
		Spisok_shifrov->AddString(L"Шифр Виженера для греческого");
		Spisok_shifrov->AddString(L"Шифр Плейфера для английского");
		Spisok_shifrov->AddString(L"Шифр Плейфера для русского");
		Spisok_shifrov->AddString(L"Шифр Плейфера для греческого");
		Spisok_shifrov->SetCurSel(0);
	}

	if (But_shifr != NULL) {
		But_shifr->Create(L"Зашифровать", WS_CHILD | WS_VISIBLE | SS_CENTER,
			theApp.NULL_RECT, this, NULL);
		But_shifr->SetWindowPos(&wndTop, 10, 580, 350, 50, SWP_SHOWWINDOW);
	}
	if (But_unshifr != NULL) {
		But_unshifr->Create(L"Расшифровать", WS_CHILD | WS_VISIBLE | SS_CENTER,
			theApp.NULL_RECT, this, NULL);
		But_unshifr->SetWindowPos(&wndTop, 620, 600, 350, 30, SWP_SHOWWINDOW);
	}
	if (Lable_vivod != NULL) Lable_vivod->Create(L"Зашифрованный/Расшифрованный текст:", WS_CHILD | WS_VISIBLE,
		CRect(500, 5, 970, 20), this, NULL);
	if (Edit_vivod != NULL) {
		Edit_vivod->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL,
			theApp.NULL_RECT, this, NULL);
		Edit_vivod->SetWindowPos(&wndTop, 500, 30, 470, 540, SWP_SHOWWINDOW);
	}


	if (Time_lable != NULL) {
		Time_lable->Create(L"Время затраченное обработку текста:", WS_CHILD | WS_VISIBLE,
			theApp.NULL_RECT, this, NULL);
		Time_lable->SetWindowPos(&wndTop, 620, 580, 280, 20, SWP_SHOWWINDOW);
	}
	if (Time_lable_vivod != NULL) {
		Time_lable_vivod->Create(L"0000:0000000", WS_CHILD | WS_VISIBLE | SS_CENTER,
			theApp.NULL_RECT, this, NULL);
		Time_lable_vivod->SetWindowPos(&wndTop, 870, 580, 105, 20, SWP_SHOWWINDOW);
	}

	/*----------------------------------------------------------------------------------------------------------------
	--------------------------Следующие строки создают элементы интерфейса для Криптоанализа--------------------------
	------------------------------------------------------------------------------------------------------------------*/
	if (But_criptoAnaliz != NULL) {
		But_criptoAnaliz->Create(L"Запустить выбранный анализ", WS_CHILD | WS_VISIBLE | SS_CENTER,
			theApp.NULL_RECT, this, NULL);
	}
	if (Spisok_analizov != NULL) {
		Spisok_analizov->Create(WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
			theApp.NULL_RECT, this, NULL);
		Spisok_analizov->AddString(L"Анализ длины ключа Виженера");
		Spisok_analizov->AddString(L"Анализ возможных вариантов ключа Виженера");
		Spisok_analizov->AddString(L"Криптоанализ Плейфера");
		Spisok_analizov->SetCurSel(0);
	}

	return 0;
}