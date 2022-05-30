
// Шифратор 3.0.h : главный файл заголовка для приложения Шифратор 3.0
//
#pragma once
#pragma warning( disable : 4996 )

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы
#include "MainFrm.h"
#include <exception>
#include <vector>
using namespace std;
//#include "VERYLONG.H"



// CШифраторApp:
// О реализации данного класса см. Шифратор.cpp
//

class CШифраторApp : public CWinApp
{
public:
	CШифраторApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CMainFrame* pFrame = new CMainFrame;

	CRect NULL_RECT = CRect(NULL, NULL, NULL, NULL);
	LONG length_text(TEXT text);
	BOOL text_verification(vector<TCHAR> text, vector<TCHAR> key, TCHAR* alfavit);

	DOUBLE shifr_vigenera(vector<TCHAR> text, vector<TCHAR> key, TCHAR* alfavit, INT ID);
	DOUBLE shifr_pleyfera(vector<TCHAR> text, vector<TCHAR> key, TCHAR* alfavit, INT ID);
	
//-------------------------Функции криптоанализа текста-------------------------
	DOUBLE criptoAnaliz_dlini_klucha_shifr_vigenera(vector<TCHAR> text, TCHAR* alfavit);
	DOUBLE index_sovpodeniy_str(vector<TCHAR> string_text, TCHAR* alfavit);
	DOUBLE criptoAnaliz_poisk_klucha_shifr_vigenera(vector<TCHAR> string_text, TCHAR* alfavit, INT dlina_klucha);
	DOUBLE criptoAnaliz_shifr_pleyfera(vector<TCHAR> string_text, TCHAR* alfavit);

//-------------------------Функции изменения интерфейса-------------------------
	void create_interfeis_shifri();
	void destroy_interfeis_shifri();

	void create_interfeis_analiz();
	void destroy_interfeis_analiz();
//-------------------------Переменные изменения интерфейса-------------------------
	BOOL zapret_shifri = TRUE;
	BOOL zapret_analiz = FALSE;

//------------------------------Алфавиты для шифрования--------------------------------

	TCHAR alfavit_lat[70] = { //размер 70
		L'A', L'B', L'C', L'D', L'E', L'F', L'G', L'H', L'I', L'J',
		L'K', L'L', L'M', L'N', L'O', L'P', L'Q', L'R', L'S', L'T',
		L'U', L'V', L'W', L'X',	L'Y', L'Z', L'a', L'b', L'c', L'd',
		L'e', L'f', L'g', L'h', L'i', L'j', L'k', L'l', L'm', L'n',
		L'o', L'p', L'q', L'r', L's', L't', L'u', L'v',	L'w', L'x',
		L'y', L'z', L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7',
		L'8', L'9', L' ', L':', L';', L'_', L',', L'.', L'!', L'?' }; // массив латинских букв

	TCHAR alfavit_rus[84] = {  //размер 84
		L'А', L'Б', L'В', L'Г', L'Д', L'Е', L'Ё', L'Ж', L'З', L'И', L'Й', L'К',
		L'Л', L'М', L'Н', L'О', L'П', L'Р', L'С', L'Т', L'У', L'Ф', L'Х', L'Ц', 
		L'Ч', L'Ш', L'Щ', L'Ъ', L'Ы', L'Ь', L'Э', L'Ю', L'Я', L'а', L'б', L'в', 
		L'г', L'д', L'е', L'ё', L'ж', L'з', L'и', L'й', L'к', L'л', L'м', L'н', 
		L'о', L'п', L'р', L'с', L'т', L'у', L'ф', L'х', L'ц', L'ч', L'ш', L'щ', 
		L'ъ', L'ы', L'ь', L'э', L'ю', L'я', L'0', L'1', L'2', L'3', L'4', L'5', 
		L'6', L'7', L'8', L'9', L' ', L':', L';', L'_', L',', L'.', L'!', L'?' }; // массив русских букв

	TCHAR alfavit_grech[66] = {  //размер 66
		L'Α', L'Β', L'Γ', L'Δ', L'Ε', L'Ζ', L'Η', L'Θ', L'Ι', L'Κ', L'Λ',
		L'Μ', L'Ν', L'Ξ', L'Ο',	L'Π', L'Ρ', L'Σ', L'Τ', L'Υ', L'Φ', L'Χ', 
		L'Ψ', L'Ω', L'α', L'β', L'γ', L'δ', L'ε', L'ζ', L'η', L'θ', L'ι', 
		L'κ', L'λ', L'μ', L'ν', L'ξ', L'ο', L'π', L'ρ', L'σ', L'ς', L'τ', 
		L'υ', L'φ', L'χ', L'ψ', L'ω', L'0', L'1', L'2', L'3', L'4', L'5',
		L'6', L'7', L'8', L'9', L' ', L':', L';', L',', L'.', L'!', L'?' }; // массив греческих букв
public:
	afx_msg void OnAppAbout();
	afx_msg void On_Clik_Cripto();
	afx_msg void On_Clik_Analiz();
	DECLARE_MESSAGE_MAP();
};

extern CШифраторApp theApp;
