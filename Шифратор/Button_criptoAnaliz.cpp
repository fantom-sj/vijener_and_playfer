#include "stdafx.h"
#include "Ўифратор.h"
#include "Button_criptoAnaliz.h"
#include <errno.h>

IMPLEMENT_DYNAMIC(ClassButton_criptoAnaliz, CButton)

ClassButton_criptoAnaliz::ClassButton_criptoAnaliz()
{
}


ClassButton_criptoAnaliz::~ClassButton_criptoAnaliz()
{
}

BEGIN_MESSAGE_MAP(ClassButton_criptoAnaliz, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &ClassButton_criptoAnaliz::OnBnClicked)
END_MESSAGE_MAP()

void ClassButton_criptoAnaliz::OnBnClicked() {
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel();
	INT analiz = theApp.pFrame->m_wndView.Spisok_analizov->GetCurSel();
	DOUBLE Time = 0;

	vector<TCHAR> ish_text_vector;  //массивы дл€ исходного текста и ключа
	TEXT ish_text;

	ish_text.lenght_text = theApp.pFrame->m_wndView.Edit_vvod->GetTextLength() + 1;
	ish_text.text = new TCHAR[ish_text.lenght_text];
	theApp.pFrame->m_wndView.Edit_vvod->GetWindowTextW(ish_text.text, ish_text.lenght_text);

	ish_text_vector.reserve(ish_text.lenght_text);
	for (INT i = 0; i < ish_text.lenght_text; i++) {
		ish_text_vector.push_back(ish_text.text[i]);
	}

	TEXT t_dlina_klucha;
	t_dlina_klucha.lenght_text = theApp.pFrame->m_wndView.Edit_kluch->GetTextLength() + 1;
	t_dlina_klucha.text = new TCHAR[t_dlina_klucha.lenght_text];
	theApp.pFrame->m_wndView.Edit_kluch->GetWindowTextW(t_dlina_klucha.text, t_dlina_klucha.lenght_text);
	INT dlina_klucha;
	if(t_dlina_klucha.lenght_text != 0)
		dlina_klucha = _wtoi(t_dlina_klucha.text);

	if (analiz == 0) {
		switch (punkt_box) {
		case 0:
			Time = theApp.criptoAnaliz_dlini_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_lat);
			break;
		case 1:
			Time = theApp.criptoAnaliz_dlini_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_rus);
			break;
		case 2:
			Time = theApp.criptoAnaliz_dlini_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_grech);
			break;
		}
	}
	else if (analiz == 1) {
		switch (punkt_box) {
		case 0:
			Time = theApp.criptoAnaliz_poisk_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_lat, dlina_klucha);
			break;
		case 1:
			Time = theApp.criptoAnaliz_poisk_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_rus, dlina_klucha);
			break;
		case 2:
			Time = theApp.criptoAnaliz_poisk_klucha_shifr_vigenera(ish_text_vector, theApp.alfavit_grech, dlina_klucha);
			break;
		}
	}
	else if (analiz == 2) {
		switch (punkt_box) {
		case 3:
			Time = theApp.criptoAnaliz_shifr_pleyfera(ish_text_vector, theApp.alfavit_lat);
			break;
		case 4:
			Time = theApp.criptoAnaliz_shifr_pleyfera(ish_text_vector, theApp.alfavit_rus);
			break;
		case 5:
			Time = theApp.criptoAnaliz_shifr_pleyfera(ish_text_vector, theApp.alfavit_grech);
			break;
		}
	}
	
	TCHAR Time_t[12] = { NULL };
	swprintf_s(Time_t, L"%lf", Time);
	for (INT i = 0; i < 12; i++) {
		if (Time_t[i] == '.') Time_t[i] = ':';
		else continue;
	}
	theApp.pFrame->m_wndView.Time_lable_vivod->SetWindowTextW(Time_t);

	delete[] ish_text.text;
	return void();
}