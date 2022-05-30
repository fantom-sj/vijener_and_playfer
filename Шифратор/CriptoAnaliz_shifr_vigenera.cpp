#pragma once

#include "stdafx.h"
#include "Шифратор.h"

DOUBLE CШифраторApp::criptoAnaliz_dlini_klucha_shifr_vigenera(vector<TCHAR> text, TCHAR* alfavit) {
	clock_t start = clock();
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel(); //Получаем какой шифр и для какого языка выбран
	INT lenght_alfavit;
	DOUBLE std_index_sovpadeniy;
	switch (punkt_box) {
	case 0:
		lenght_alfavit = 70;
		std_index_sovpadeniy = 0.072947;
		break;
	case 1:
		lenght_alfavit = 84;
		std_index_sovpadeniy = 0.059579;
		break;
	case 2:
		lenght_alfavit = 66;
		std_index_sovpadeniy = 0.073203;
		break;
	default:
		break;
	}
	INT lenght_ish_text = size(text) - 1;

	DOUBLE tablica_index_sovpod[30];
	vector<TCHAR> textogramma;
	for (INT t = 1; t <= 30; t++) {
		for (INT i = 0; i < lenght_ish_text-30; i++) {
			if (i%t == 0) {
				TCHAR &elsem_text = text.at(i);
				textogramma.push_back(elsem_text);
			}
			
		}

		tablica_index_sovpod[t-1] = theApp.index_sovpodeniy_str(textogramma, alfavit);
		textogramma.clear();
	}

	TCHAR text_vivod[100000] = { NULL };
	swprintf_s(text_vivod, L"Возможные варианты длины ключа и индекса совпадений при ней:\n");
	swprintf_s(text_vivod, L"%sДлина ключа | индекс совпадений\n", text_vivod);
	for (INT t = 1; t <= 30; t++) {
		swprintf_s(text_vivod, L"%s%d\t=\t%lf\n", text_vivod, t, tablica_index_sovpod[t-1]);
	}
	
	for (INT t = 0; t < 30; t++)
		tablica_index_sovpod[t] = abs(tablica_index_sovpod[t] - std_index_sovpadeniy);

	DOUBLE min_index = 1.0;
	INT id_min_index;
	for (INT t = 0; t < 30; t++) {
		if (tablica_index_sovpod[t] < min_index) {
			min_index = tablica_index_sovpod[t];
			id_min_index = t+1;
		}
	}

	swprintf_s(text_vivod, L"%sНаиболее вероятная длина ключа: %d", text_vivod, id_min_index);

	theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(text_vivod);
	//theApp.pFrame->MessageBox(ΤΤΤΤΤ, L"Служебное сообщение", NULL);
	//theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(&zash_text.at(0));

	clock_t end = clock();
	return (DOUBLE)((end - start) / CLOCKS_PER_SEC);
}

DOUBLE CШифраторApp::index_sovpodeniy_str(vector<TCHAR> string_text, TCHAR* alfavit) {
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel();
	INT lenght_alfavit;
	switch (punkt_box) {
	case 0:
		lenght_alfavit = 70;
		break;
	case 1:
		lenght_alfavit = 84;
		break;
	case 2:
		lenght_alfavit = 66;
		break;
	default:
		break;
	}
	INT lenght_ish_text = size(string_text) - 1;
	DOUBLE *chastota_bukv = new DOUBLE[lenght_alfavit];

	for (INT i = 0; i < lenght_alfavit; i++)
		chastota_bukv[i] = 0;

	for (INT i = 0; i < lenght_alfavit; i++) {
		for (INT k = 0; k < lenght_ish_text; k++) {
			TCHAR &elsem_string_text = string_text.at(k);

			if (elsem_string_text == alfavit[i])
				chastota_bukv[i]++;
		}
	}

	DOUBLE absolut_chastota_bukv=0;
	for (INT i = 0; i < lenght_alfavit; i++)
		absolut_chastota_bukv = absolut_chastota_bukv + (chastota_bukv[i]*(chastota_bukv[i]-1));

	DOUBLE index_sovpodeniy = absolut_chastota_bukv / (lenght_ish_text*(lenght_ish_text - 1));

	delete[] chastota_bukv;
	return index_sovpodeniy;
}

DOUBLE CШифраторApp::criptoAnaliz_poisk_klucha_shifr_vigenera(vector<TCHAR> string_text, TCHAR* alfavit, INT dlina_klucha) {
	clock_t start = clock();
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel(); //Получаем какой шифр и для какого языка выбран
	INT lenght_alfavit;
	switch (punkt_box) {
	case 0:
		lenght_alfavit = 70;
		break;
	case 1:
		lenght_alfavit = 84;
		break;
	case 2:
		lenght_alfavit = 66;
		break;
	default:
		break;
	}
	INT lenght_ish_text = size(string_text) - 1;


	clock_t end = clock();
	return (DOUBLE)((end - start) / CLOCKS_PER_SEC);
}

DOUBLE CШифраторApp::criptoAnaliz_shifr_pleyfera(vector<TCHAR> string_text, TCHAR* alfavit) {
	clock_t start = clock();
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel();
	INT lenght_alfavit;
	switch (punkt_box) {
	case 3:
		lenght_alfavit = 70;
		break;
	case 4:
		lenght_alfavit = 84;
		break;
	case 5:
		lenght_alfavit = 66;
		break;
	default:
		break;
	}
	INT lenght_ish_text = size(string_text) - 1;
	vector<TCHAR> trigramma, text_gramm;
	vector< vector <TCHAR> > trigramm;

	
	for (INT i = 0; i < lenght_alfavit; i++) {
		for (INT j = 0; j < lenght_alfavit; j++) {
			for (INT k = 0; k < lenght_alfavit; k++) {
				trigramma.push_back(alfavit[i]);
				trigramma.push_back(alfavit[j]);
				trigramma.push_back(alfavit[k]);
				for (INT l = 1; l < (lenght_ish_text-1); l++) {
					TCHAR &elsem1 = string_text.at(l - 1);
					TCHAR &elsem2 = string_text.at(l);
					TCHAR &elsem3 = string_text.at(l + 1);

					text_gramm.push_back(elsem1);
					text_gramm.push_back(elsem2);
					text_gramm.push_back(elsem3);

					if (trigramma == text_gramm)
						trigramm.push_back(trigramma);

					text_gramm.clear();
				}
				trigramma.clear();
			}
		}
	}

	LONG trigramm_size = size(trigramm);
	vector< vector <TCHAR> > trigramm_itog;
	vector<DOUBLE>  trigtamm_itog_castota;
	for (INT i = 0; i < lenght_alfavit; i++) {
		for (INT j = 0; j < lenght_alfavit; j++) {
			for (INT k = 0; k < lenght_alfavit; k++) {
				trigramma.push_back(alfavit[i]);
				trigramma.push_back(alfavit[j]);
				trigramma.push_back(alfavit[k]);

				INT chastota = 0;
				for (LONG l = 0; i < trigramm_size; l++) {
					if (trigramma == trigramm.at(l)) {
						chastota++;
					}
				}

				if (chastota>0) {
					trigramm_itog.push_back(trigramma);
					trigtamm_itog_castota.push_back(chastota / (lenght_alfavit*lenght_alfavit*lenght_alfavit));
				}
				trigramma.clear();
			}
		}
	}

	/*trigramma.push_back(alfavit[5]);
	trigramma.push_back(alfavit[9]);
	trigramma.push_back(alfavit[10]);
	trigramm_itog.push_back(trigramma);
	trigtamm_itog_castota.push_back(0.12356);
	trigramm_itog.push_back(trigramma);
	trigtamm_itog_castota.push_back(0.8568);*/

	TCHAR global_text_vivod[100000] = { NULL };
	LONG lenght_trigramm_itog = size(trigramm_itog);
	for (LONG i = 0; i < lenght_trigramm_itog; i++) {
		trigramma = trigramm_itog.at(i);
		TCHAR c1 = trigramma.at(0);
		TCHAR c2 = trigramma.at(1);
		TCHAR c3 = trigramma.at(2);
		swprintf_s(global_text_vivod, L"%s\n%lf  --  %c%c%c", global_text_vivod, trigtamm_itog_castota.at(i), c1, c2, c3);
	}
	
	theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(global_text_vivod);
	//theApp.pFrame->MessageBox(ΤΤΤΤΤ, L"Служебное сообщение", NULL);
	//theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(&zash_text.at(0));

	clock_t end = clock();
	return (DOUBLE)((end - start) / CLOCKS_PER_SEC);
}