
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "EditText.h"
#include "ComboBox.h"
#include "afxrich.h"
#include "Button_shifr.h"
#include "Button_unshifr.h"
#include "Button_criptoAnaliz.h"
#include "time.h"

// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:

// ��������
public:

//����������� �������
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_brush;
	
//---------����� �������� ����������--------------------------------------
	CStatic* Lable_vvod = new CStatic();
	CStatic* Lable_vivod = new CStatic();
	CRichEditView* Edit_vvod = new CRichEditView();
	CRichEditView* Edit_vivod = new CRichEditView();

	ClassButton_unshifr* But_unshifr = new ClassButton_unshifr;
	ClassButton_shifr* But_shifr = new ClassButton_shifr;

	ComboBox* Spisok_shifrov = new ComboBox();

	CStatic* Time_lable = new CStatic();
	CStatic* Time_lable_vivod = new CStatic();

//---------�������� ���������� ����� �������� � ��������-------------------
	CStatic* Lable_kluch = new CStatic();
	CRichEditView* Edit_kluch = new CRichEditView();

//-----------------�������� ���������� ��� �������������-------------------
	ClassButton_criptoAnaliz* But_criptoAnaliz = new ClassButton_criptoAnaliz;
	ComboBox* Spisok_analizov = new ComboBox();

//-----------------------------���������������-----------------------------
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

//-----------------------------����������----------------------------------
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

