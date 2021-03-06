// Button_unshifr.cpp: ???? ??????????
//

#include "stdafx.h"
#include "????????.h"
#include "Button_unshifr.h"

// ClassButton_unshifr

IMPLEMENT_DYNAMIC(ClassButton_unshifr, CButton)

ClassButton_unshifr::ClassButton_unshifr()
{
}

ClassButton_unshifr::~ClassButton_unshifr()
{
}


BEGIN_MESSAGE_MAP(ClassButton_unshifr, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &ClassButton_unshifr::OnBnClicked)
END_MESSAGE_MAP()



// ??????????? ????????? ClassButton_unshifr

void ClassButton_unshifr::OnBnClicked() {
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel();
	DOUBLE Time = 0;

	vector<TCHAR> ish_text_vector, t_kluch_vector;  //??????? ??? ????????? ?????? ? ?????
	TEXT ish_text, t_kluch;

	ish_text.lenght_text = theApp.pFrame->m_wndView.Edit_vvod->GetTextLength() + 1;
	ish_text.text = new TCHAR[ish_text.lenght_text];
	theApp.pFrame->m_wndView.Edit_vvod->GetWindowTextW(ish_text.text, ish_text.lenght_text);

	ish_text_vector.reserve(ish_text.lenght_text);
	for (INT i = 0; i < ish_text.lenght_text; i++) {
		ish_text_vector.push_back(ish_text.text[i]);
	}

	t_kluch.lenght_text = theApp.pFrame->m_wndView.Edit_kluch->GetTextLength() + 1;
	t_kluch.text = new TCHAR[t_kluch.lenght_text];
	theApp.pFrame->m_wndView.Edit_kluch->GetWindowTextW(t_kluch.text, t_kluch.lenght_text);
	t_kluch_vector.reserve(t_kluch.lenght_text);
	for (INT i = 0; i < t_kluch.lenght_text; i++) {
		t_kluch_vector.push_back(t_kluch.text[i]);
	}

	try {
		if (ish_text.lenght_text == 1) throw 1;
		else if (t_kluch.lenght_text == 1) throw 2;
		else {
			switch (punkt_box) {
			case 0:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_lat) == TRUE)
					Time = theApp.shifr_vigenera(ish_text_vector, t_kluch_vector, theApp.alfavit_lat, -1);
				else throw 6;
				break;
			case 1:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_rus) == TRUE)
					Time = theApp.shifr_vigenera(ish_text_vector, t_kluch_vector, theApp.alfavit_rus, -1);
				else throw 6;
				break;
			case 2:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_grech) == TRUE)
					Time = theApp.shifr_vigenera(ish_text_vector, t_kluch_vector, theApp.alfavit_grech, -1);
				else throw 6;
				break;
			case 3:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_lat) == TRUE)
					Time = theApp.shifr_pleyfera(ish_text_vector, t_kluch_vector, theApp.alfavit_lat, -1);
				else throw 6;
				break;
			case 4:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_rus) == TRUE)
					Time = theApp.shifr_pleyfera(ish_text_vector, t_kluch_vector, theApp.alfavit_rus, -1);
				else throw 6;
				break;
			case 5:
				if (theApp.text_verification(ish_text_vector, t_kluch_vector, theApp.alfavit_grech) == TRUE)
					Time = theApp.shifr_pleyfera(ish_text_vector, t_kluch_vector, theApp.alfavit_grech, -1);
				else throw 6;
				break;
			default:
				break;
			}
		}
	}
	catch (INT ERROR_CODE) {
		if (ERROR_CODE == 1)
			theApp.pFrame->MessageBox(L"?????????? ????? ??? ??????????",
				L"?????? ? ??????????? ??????? ??????? '???????????'", NULL);
		else if (ERROR_CODE == 2)
			theApp.pFrame->MessageBox(L"?????????? ???? ??? ??????????",
				L"?????? ? ??????????? ??????? ??????? '???????????'", NULL);
		else if (ERROR_CODE == 6)
			theApp.pFrame->MessageBox(L"????????? ????? ??? ????, ?? ????????????? ?????????? ?????!",
				L"?????? ? ??????????? ??????? ??????? '???????????'", NULL);
		/*else if (ERROR_CODE == )
		theApp.pFrame->MessageBox(,
		L"?????? ? ??????????? ??????? ??????? '???????????'", NULL);*/
		return void();
	}

	TCHAR Time_t[12] = { NULL };
	swprintf_s(Time_t, L"%lf", Time);
	for (INT i = 0; i < 12; i++) {
		if (Time_t[i] == '.') Time_t[i] = ':';
		else continue;
	}
	theApp.pFrame->m_wndView.Time_lable_vivod->SetWindowTextW(Time_t);

	delete[] ish_text.text;
	delete[] t_kluch.text;
	return void();
}
