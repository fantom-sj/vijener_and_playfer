
// Шифратор 3.0.cpp : Определяет поведение классов для приложения.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Шифратор.h"
#include <math.h>
#include <complex>
#include <valarray>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CШифратор30App

BEGIN_MESSAGE_MAP(CШифраторApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CШифраторApp::OnAppAbout)
	ON_COMMAND(ID_CRIPTO, &CШифраторApp::On_Clik_Cripto)
	ON_COMMAND(ID_ANALIZ, &CШифраторApp::On_Clik_Analiz)
END_MESSAGE_MAP()


// создание CШифратор30App

CШифраторApp::CШифраторApp()
{
	// TODO: замените ниже строку идентификатора приложения строкой уникального идентификатора; рекомендуемый
	// формат для строки: ИмяКомпании.ИмяПродукта.СубПродукт.СведенияОВерсии
	SetAppID(_T("Шифратор"));
//	Status_open = FALSE;
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}

// Единственный объект CШифратор30App

CШифраторApp theApp;

// инициализация CШифратор30App

BOOL CШифраторApp::InitInstance()
{
	// InitCommonControlsEx() требуются для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Инициализация библиотек OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// Для использования элемента управления RichEdit требуется метод AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующего
	// конкретные процедуры инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));


	// Чтобы создать главное окно, этот код создает новый объект окна
	// рамки, а затем задает его как объект основного окна приложения
	
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// создайте и загрузите рамку с его ресурсами
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	// Разрешить использование расширенных символов в горячих клавишах меню
	CMFCToolBar::m_bExtCharTranslation = TRUE;



	// Одно и только одно окно было инициализировано, поэтому отобразите и обновите его
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CШифраторApp::ExitInstance()
{
	//TODO: обработайте дополнительные ресурсы, которые могли быть добавлены
	AfxOleTerm(FALSE);
	
	return CWinApp::ExitInstance();
}

// обработчики сообщений CШифратор30App


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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

// Команда приложения для запуска диалога
void CШифраторApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// обработчики сообщений CШифратор30App



void CШифраторApp::On_Clik_Cripto() {
	if (zapret_shifri==FALSE) {
		destroy_interfeis_analiz();
		create_interfeis_shifri();
		zapret_shifri = TRUE;
		zapret_analiz = FALSE;
	}
}

void CШифраторApp::On_Clik_Analiz() {
	if (zapret_analiz == FALSE) {
		destroy_interfeis_shifri();
		create_interfeis_analiz();
		zapret_shifri = FALSE;
		zapret_analiz = TRUE;
	}
}

/*-------------------------------------------------------------------------------------------------------
----------------------------Функции создания и уничтожения интерфейса шифрования-------------------------
-------------------------------------------------------------------------------------------------------*/
void CШифраторApp::create_interfeis_shifri() {
	theApp.pFrame->m_wndView.Lable_vvod->SetWindowTextW(L"Введите текст, который требуется зашифровать или расшифровать:");
	theApp.pFrame->m_wndView.Lable_vivod->SetWindowTextW(L"Зашифрованный/Расшифрованный текст:");
	theApp.pFrame->m_wndView.Lable_kluch->SetWindowTextW(L"Введите ключ:");
	theApp.pFrame->m_wndView.But_shifr->MoveWindow(10, 580, 350, 50);
	theApp.pFrame->m_wndView.But_unshifr->MoveWindow(620, 600, 350, 30);
	theApp.pFrame->m_wndView.Lable_vivod->RedrawWindow();
}
void CШифраторApp::destroy_interfeis_shifri() {
	theApp.pFrame->m_wndView.But_shifr->MoveWindow(0, 0, 0, 0);
	theApp.pFrame->m_wndView.But_unshifr->MoveWindow(0, 0, 0, 0);
}


/*---------------------------------------------------------------------------------------------------------
----------------------------Функции создания и уничтожения интерфейса Криптоанализа------------------------
---------------------------------------------------------------------------------------------------------*/
void CШифраторApp::create_interfeis_analiz() {
	theApp.pFrame->m_wndView.Lable_vvod->SetWindowTextW(L"Зашифрованное сообщение:");
	theApp.pFrame->m_wndView.Lable_vivod->SetWindowTextW(L"Результат проведённого анализа:");
	theApp.pFrame->m_wndView.Lable_kluch->SetWindowTextW(L"Длина ключа:");
	theApp.pFrame->m_wndView.But_criptoAnaliz->MoveWindow(10, 580, 350, 25);
	theApp.pFrame->m_wndView.Spisok_analizov->MoveWindow(10, 610, 350, 25);
	theApp.pFrame->m_wndView.Lable_vivod->RedrawWindow();
}
void CШифраторApp::destroy_interfeis_analiz() {
	theApp.pFrame->m_wndView.But_criptoAnaliz->MoveWindow(0, 0, 0, 0);
	theApp.pFrame->m_wndView.Spisok_analizov->MoveWindow(0, 0, 0, 0);
}
