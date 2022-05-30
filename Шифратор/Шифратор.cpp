
// �������� 3.0.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "��������.h"
#include <math.h>
#include <complex>
#include <valarray>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��������30App

BEGIN_MESSAGE_MAP(C��������App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &C��������App::OnAppAbout)
	ON_COMMAND(ID_CRIPTO, &C��������App::On_Clik_Cripto)
	ON_COMMAND(ID_ANALIZ, &C��������App::On_Clik_Analiz)
END_MESSAGE_MAP()


// �������� C��������30App

C��������App::C��������App()
{
	// TODO: �������� ���� ������ �������������� ���������� ������� ����������� ��������������; �������������
	// ������ ��� ������: �����������.�����������.����������.���������������
	SetAppID(_T("��������"));
//	Status_open = FALSE;
	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ C��������30App

C��������App theApp;

// ������������� C��������30App

BOOL C��������App::InitInstance()
{
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������.  � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ������������� ��������� OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ��� ������������� �������� ���������� RichEdit ��������� ����� AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));


	// ����� ������� ������� ����, ���� ��� ������� ����� ������ ����
	// �����, � ����� ������ ��� ��� ������ ��������� ���� ����������
	
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// �������� � ��������� ����� � ��� ���������
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	// ��������� ������������� ����������� �������� � ������� �������� ����
	CMFCToolBar::m_bExtCharTranslation = TRUE;



	// ���� � ������ ���� ���� ���� ����������������, ������� ���������� � �������� ���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int C��������App::ExitInstance()
{
	//TODO: ����������� �������������� �������, ������� ����� ���� ���������
	AfxOleTerm(FALSE);
	
	return CWinApp::ExitInstance();
}

// ����������� ��������� C��������30App


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ������� ���������� ��� ������� �������
void C��������App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// ����������� ��������� C��������30App



void C��������App::On_Clik_Cripto() {
	if (zapret_shifri==FALSE) {
		destroy_interfeis_analiz();
		create_interfeis_shifri();
		zapret_shifri = TRUE;
		zapret_analiz = FALSE;
	}
}

void C��������App::On_Clik_Analiz() {
	if (zapret_analiz == FALSE) {
		destroy_interfeis_shifri();
		create_interfeis_analiz();
		zapret_shifri = FALSE;
		zapret_analiz = TRUE;
	}
}

/*-------------------------------------------------------------------------------------------------------
----------------------------������� �������� � ����������� ���������� ����������-------------------------
-------------------------------------------------------------------------------------------------------*/
void C��������App::create_interfeis_shifri() {
	theApp.pFrame->m_wndView.Lable_vvod->SetWindowTextW(L"������� �����, ������� ��������� ����������� ��� ������������:");
	theApp.pFrame->m_wndView.Lable_vivod->SetWindowTextW(L"�������������/�������������� �����:");
	theApp.pFrame->m_wndView.Lable_kluch->SetWindowTextW(L"������� ����:");
	theApp.pFrame->m_wndView.But_shifr->MoveWindow(10, 580, 350, 50);
	theApp.pFrame->m_wndView.But_unshifr->MoveWindow(620, 600, 350, 30);
	theApp.pFrame->m_wndView.Lable_vivod->RedrawWindow();
}
void C��������App::destroy_interfeis_shifri() {
	theApp.pFrame->m_wndView.But_shifr->MoveWindow(0, 0, 0, 0);
	theApp.pFrame->m_wndView.But_unshifr->MoveWindow(0, 0, 0, 0);
}


/*---------------------------------------------------------------------------------------------------------
----------------------------������� �������� � ����������� ���������� �������������------------------------
---------------------------------------------------------------------------------------------------------*/
void C��������App::create_interfeis_analiz() {
	theApp.pFrame->m_wndView.Lable_vvod->SetWindowTextW(L"������������� ���������:");
	theApp.pFrame->m_wndView.Lable_vivod->SetWindowTextW(L"��������� ����������� �������:");
	theApp.pFrame->m_wndView.Lable_kluch->SetWindowTextW(L"����� �����:");
	theApp.pFrame->m_wndView.But_criptoAnaliz->MoveWindow(10, 580, 350, 25);
	theApp.pFrame->m_wndView.Spisok_analizov->MoveWindow(10, 610, 350, 25);
	theApp.pFrame->m_wndView.Lable_vivod->RedrawWindow();
}
void C��������App::destroy_interfeis_analiz() {
	theApp.pFrame->m_wndView.But_criptoAnaliz->MoveWindow(0, 0, 0, 0);
	theApp.pFrame->m_wndView.Spisok_analizov->MoveWindow(0, 0, 0, 0);
}
