
//#include <tchar.h>
#include "stdafx.h"
#include "Шифратор.h"


LONG CШифраторApp::length_text(TEXT text) {
	LONG my_length = 0;
	LONG lenght = text.lenght_text;
	for (INT i = 0; i < lenght; i++) {
		for (INT j = 0; j < 70; j++) {
			if (text.text[i] == theApp.alfavit_lat[j]) {
				my_length++;
				continue;
			}
		}
		for (INT j = 0; j < 84; j++) {
			if (text.text[i] == theApp.alfavit_rus[j]) {
				my_length++;
				continue;
			}
		}
		for (INT j = 0; j < 66; j++) {
			if (text.text[i] == theApp.alfavit_grech[j]) {
				my_length++;
				continue;
			}
		}
	}
	return my_length;
}

//INT CШифраторApp::correction_text(TCHAR* text, LONG lenght) {
//	TEXT cor_text;
//	cor_text.lenght_text = lenght;
//	cor_text.text = new TCHAR[lenght];
//	complete_cleaning_text(cor_text.text, cor_text.lenght_text);
//
//	for (INT i = 0; i < cor_text.lenght_text; i++) {
//		BOOL end_for = FALSE;
//		for (int j = 0; j < 70; j++) {
//			if (text[i] == theApp.alfavit_lat[j]) {
//				cor_text.text[i] = theApp.alfavit_lat[j];
//				end_for = TRUE;
//				continue;
//			}
//		}
//		for (int j = 0; j < 84; j++) {
//			if (text[i] == theApp.alfavit_rus[j]) {
//				cor_text.text[i] = theApp.alfavit_rus[j];
//				end_for = TRUE;
//				continue;
//			}
//		}
//		for (int j = 0; j < 64; j++) {
//			if (text[i] == theApp.alfavit_grech[j]) {
//				cor_text.text[i] = theApp.alfavit_grech[j];
//				end_for = TRUE;
//				continue;
//			}
//		}
//		if (end_for == TRUE)continue;
//		else cor_text.text[i] = NULL;
//	}
//
//	for (int i = 0; i < cor_text.lenght_text; i++) {
//		text[i] = cor_text.text[i];
//	}
//	return 0;
//}

BOOL CШифраторApp::text_verification(vector<TCHAR> text, vector<TCHAR> key, TCHAR* alfavit) {
	//INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel(); //Получаем какой шифр и для какого языка выбран
	////Создаём и определяем длину алфавита
	//INT lenght_alfavit;
	//switch (punkt_box) {
	//	case 0:
	//		lenght_alfavit = 70;
	//		break;
	//	case 1:
	//		lenght_alfavit = 84;
	//		break;
	//	case 2:
	//		lenght_alfavit = 66;
	//		break;
	//	case 3:
	//		lenght_alfavit = 70;
	//		break;
	//	case 4:
	//		lenght_alfavit = 84;
	//		break;
	//	case 5:
	//		lenght_alfavit = 66;
	//		break;
	//	default:
	//		break;
	//}

	//INT *verification_text = new INT[text.lenght_text];
	//INT *verification_kluch = new INT[key.lenght_text];
	//INT verification_all_text = 0, verification_all_kluch = 0;
	//
	//INT i = 0;
	//while (i < text.lenght_text) {
	//	for (INT j = 0; j < lenght_alfavit; j++) {
	//		if ((text.text[i] == alfavit[j]) || (text.text[i] == NULL)) {
	//			verification_text[i] = 1;
	//			break;
	//		}
	//		else verification_text[i] = 0;
	//	}
	//	i++;
	//}

	//i = 0;
	//while (i < key.lenght_text) {
	//	for (INT j = 0; j < lenght_alfavit; j++) {
	//		if ((key.text[i] == alfavit[j]) || (key.text[i] == NULL)) {
	//			verification_kluch[i] = 1;
	//			break;
	//		}
	//		else verification_kluch[i] = 0;
	//	}
	//	i++;
	//}

	//for (INT k = 0; k < text.lenght_text; k++)
	//	verification_all_text += verification_text[k];

	//for (INT k = 0; k < key.lenght_text; k++)
	//	verification_all_kluch += verification_kluch[k];

	///*if ((verification_all_text == text.lenght_text) && (verification_all_kluch == key.lenght_text))
	//	return TRUE;
	//else
	//	return FALSE;*/

	return TRUE;
}