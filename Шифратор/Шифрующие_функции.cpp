#pragma once

#include "stdafx.h"
#include "Шифратор.h"

DOUBLE CШифраторApp::shifr_vigenera(vector<TCHAR> ish_text, vector<TCHAR> ish_kluch, TCHAR* alfavit, INT ID) {   //Функция шифрования шифром Виженера
	clock_t start = clock();
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel(); //Получаем какой шифр и для какого языка выбран
	
	//Определение размера ключевых контейнеров данных
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
	INT lenght_ish_text = size(ish_text)-1;
	INT lenght_ish_kluch = size(ish_kluch)-1;

	
	/*TCHAR Buff[25];
	swprintf_s(Buff, L"Длина alfavit_vector %d", size(alfavit_vector));
	theApp.pFrame->MessageBox(Buff, L"Служебное сообщение", NULL);*/

	//создание контейнеров для данных шифрования и резервирование простанства для нужного колличества элементов
	vector<TCHAR> kluch, zash_text, alfavit_vector;
	vector<INT> ID_ish_text, ID_kluch, ID_zash_text;
	kluch.reserve(lenght_ish_text);
	zash_text.reserve(lenght_ish_text);
	alfavit_vector.reserve(lenght_alfavit);
	ID_ish_text.reserve(lenght_ish_text);
	ID_kluch.reserve(lenght_ish_text);
	ID_zash_text.reserve(lenght_ish_text);
	
	//перобразование выбранного алфавита в вектор
	for (INT i = 0; i < lenght_alfavit; i++) {
		alfavit_vector.push_back(alfavit[i]);
	}

	//Создание длинного ключа для шифрования
	INT b;
	
	for (INT i = 0; i < lenght_ish_text; i++) {
		b = i;
		while (b >= lenght_ish_kluch) b = b - lenght_ish_kluch;
		TCHAR &elem_ish_kluch = ish_kluch.at(b);
		kluch.push_back(elem_ish_kluch);
	}

	//Вычисление ID символов исходного текста и ключа
	for (INT i = 0; i < lenght_ish_text; i++) {
		for (INT t = 0; t < lenght_alfavit; t++) {
			TCHAR &elem_alfavit_vector = alfavit_vector.at(t);
			TCHAR &elem_ish_text = ish_text.at(i);
			TCHAR &elem_kluch = kluch.at(i);

			if (elem_ish_text == elem_alfavit_vector) ID_ish_text.push_back(t);
			if (elem_kluch == elem_alfavit_vector) ID_kluch.push_back(t);
		}
	}


	//Вычисление номера каждого символа зашифрованного текста
	for (int i = 0; i < lenght_ish_text; i++) {
		INT &elem_ID_ish_text = ID_ish_text.at(i);
		INT &elem_ID_kluch = ID_kluch.at(i);

		INT elem_ID_zash_text;
		elem_ID_zash_text = elem_ID_ish_text + (ID*elem_ID_kluch);
		ID_zash_text.push_back((elem_ID_zash_text + lenght_alfavit) % lenght_alfavit);
	}

	for (int i = 0; i < lenght_ish_text; i++) {
		INT &elem_ID_zash_text = ID_zash_text.at(i);
		TCHAR &elem_zash_text = alfavit_vector.at(elem_ID_zash_text);
		zash_text.push_back(elem_zash_text);
	}
	zash_text.push_back(NULL);
	theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(&zash_text.at(0));
		
	clock_t end = clock();
	return (DOUBLE)((end - start) / CLOCKS_PER_SEC);
}

DOUBLE CШифраторApp::shifr_pleyfera(vector<TCHAR> ish_text, vector<TCHAR> ish_kluch, TCHAR* alfavit, INT ID) {   //Функция шифрования шифром Плейфера
	clock_t start = clock();
	INT punkt_box = theApp.pFrame->m_wndView.Spisok_shifrov->GetCurSel(); //Получаем какой шифр и для какого языка выбран

	//Создаём и определяем длину ключа, количество строк и столбцов в матрице ключа
	INT lenght_kluch, qty_str, qty_stb; 
	switch (punkt_box) {
		case 3:
			lenght_kluch = 70;
			qty_str = 7;
			qty_stb = 10;
			break;
		case 4:
			lenght_kluch = 84;
			qty_str = 7;
			qty_stb = 12;
			break;
		case 5:
			lenght_kluch = 66;
			qty_str = 6;
			qty_stb = 11;
			break;
		default:
			break;
	}

	INT lenght_ish_text = size(ish_text) - 1;
	INT lenght_ish_kluch = size(ish_kluch) - 1;

	//создание контейнеров для данных шифрования и резервирование простанства для нужного колличества элементов
	vector<TCHAR> kluch, text_for_shifr, zash_text;
	vector<INT> ID_ish_kluch, ID_kluch, ID_zash_text;
	kluch.reserve(lenght_ish_text);
	ID_ish_kluch.reserve(lenght_ish_text);

	TCHAR **matrix_kluch = new TCHAR*[qty_str]; //Создаём массив для матрицы ключа
	for (INT i = 0; i<qty_str; i++)
		matrix_kluch[i] = new TCHAR[qty_stb];

	/*-------------------------------------------------------------------------
	----------Получение массива ключа для состовления из него матрицы----------
	-------------------------------------------------------------------------*/
	INT b = 0;
	for (INT i = 0; i < lenght_ish_kluch; i++) {   //Вставляем ключевое слово в начало и создаём масив ID ключевго слова
		TCHAR &elem_ish_kluch = ish_kluch.at(i);
		kluch.push_back(elem_ish_kluch);

		for (INT j = 0; j < lenght_kluch; j++) {
			if (alfavit[j] == elem_ish_kluch) {
				ID_ish_kluch.push_back(j);
				break;
			}
		}
	}
	
	for (INT i = 0; i < lenght_kluch; i++) {   //После ключа добавляем все буквы из алфовита, за исключением тех, что есть в ключе
		BOOL propusk_iter = FALSE;
		for (INT j = 0; j < lenght_ish_kluch; j++) {
			INT &elem_ID_ish_kluch = ID_ish_kluch.at(j);
			if (i == elem_ID_ish_kluch) propusk_iter = TRUE;
		}

		if (propusk_iter == TRUE) continue;
		else
			kluch.push_back(alfavit[i]);
	}

	/*Делаем из масиива ключа - ключ матрицу ---старая версия
	vector<TCHAR> matrix_temp;
	INT position = 0;
	for (INT i = 0; i < qty_str; i++) {   
		for (INT j = 0; j < qty_stb; j++) {
			TCHAR &elsem_kluch = kluch.at(position);
			matrix_kluch_str.push_back(elsem_kluch);
			position++;

			TCHAR &temp = matrix_kluch[i][j];
			matrix_temp.push_back(temp);
			
		}
		matrix_kluch.push_back(matrix_kluch_str);
	}*/

	INT position = 0;
	for (INT i = 0; i < qty_str; i++)   //Делаем из масиива ключа - ключ матрицу
		for (INT j = 0; j < qty_stb; j++) {
			matrix_kluch[i][j] = kluch[position];
			position++;
		}

	



	//theApp.pFrame->MessageBox(&matrix_temp.at(0), L"Служебное сообщение", NULL);

	//Блок необходимых для шифровки и дешифровки переменных
	INT ind_x1 = 0;
	INT ind_y1 = 0;
	INT ind_x2 = 0;
	INT ind_y2 = 0;
	INT k = 0;
	INT id = 0, jd=0;

	/*-------------------------------------------------------------------------
	----------------------------Шифрование текста------------------------------
	-------------------------------------------------------------------------*/
	if (ID == 1) {
		while (id < lenght_ish_text) {		//Приведение исходного текста для шифрования к требуемуму виду

			text_for_shifr.push_back(ish_text[id]);
			id++;
			if (id == lenght_ish_text) {
				text_for_shifr.push_back(';');		//Добовление наименее повторяющегося знака Х в конец, в случае не чётного размера
				break;
			}
			if (ish_text[id] == text_for_shifr[jd]) { //Добовление Х в случае повторяющихся букв
				text_for_shifr.push_back(';');
				jd++;
			}
			else if (ish_text[id] != text_for_shifr[jd]) {	//перенос исходного текста в новый контейнер
				jd++;
				text_for_shifr.push_back(ish_text[id]);
				id += 1;
			}
			jd++;

		}

		text_for_shifr.push_back(NULL);
		INT lenght_text_for_shifr = size(text_for_shifr) - 1; //размер нового контейнера с текстом

		while (k<lenght_text_for_shifr) {	//Вычисляем координаты букв биграмм в матрице ключа
			
			for (INT l = 0; l<qty_str; l++)
				for (INT m = 0; m<qty_stb; m++) {

					TCHAR &elsem_ish_text1 = text_for_shifr.at(k);
					if (elsem_ish_text1 == matrix_kluch[l][m]) {		//координаты первой буквы биграммы
						ind_x1 = l;
						ind_y1 = m;
					}

					TCHAR &elsem_ish_text2 = text_for_shifr.at(k+1);
					if (elsem_ish_text2 == matrix_kluch[l][m]) {		//координаты второй буквы биграммы
						ind_x2 = l;
						ind_y2 = m;
					}
				}


			//Если буквы биграммы находятся в одной строке
			if (ind_x1 == ind_x2) {
				zash_text.push_back(matrix_kluch[ind_x1][(ind_y1 + 1) % qty_stb]);
				zash_text.push_back(matrix_kluch[ind_x2][(ind_y2 + 1) % qty_stb]);
			}

			//Если буквы биграммы находятся в одном столбце
			else if (ind_y1 == ind_y2) {
				zash_text.push_back(matrix_kluch[(ind_x1 + 1) % qty_str][ind_y1]);
				zash_text.push_back(matrix_kluch[(ind_x2 + 1) % qty_str][ind_y2]);
			}

			//Если буквы биграммы находятся в разных строках и разных столбцах
			else if ((ind_x1 != ind_x2) && (ind_y1 != ind_y2)) {
				zash_text.push_back(matrix_kluch[ind_x1][ind_y2]);
				zash_text.push_back(matrix_kluch[ind_x2][ind_y1]);
			}
			k += 2;
		}
	}

	/*-------------------------------------------------------------------------
	----------------------------Дешифрование текста----------------------------
	-------------------------------------------------------------------------*/
	else if (ID == -1) {
		while (k<lenght_ish_text) {	//Вычисляем координаты букв биграмм в матрице ключа

			for (INT l = 0; l<qty_str; l++)
				for (INT m = 0; m<qty_stb; m++) {

					TCHAR &elsem_ish_text1 = ish_text.at(k);
					if (elsem_ish_text1 == matrix_kluch[l][m]) {		//координаты первой буквы биграммы
						ind_x1 = l;
						ind_y1 = m;
					}

					TCHAR &elsem_ish_text2 = ish_text.at(k + 1);
					if (elsem_ish_text2 == matrix_kluch[l][m]) {		//координаты второй буквы биграммы
						ind_x2 = l;
						ind_y2 = m;
					}
				}


			//Если буквы биграммы находятся в одной строке
			if (ind_x1 == ind_x2) {
				text_for_shifr.push_back(matrix_kluch[ind_x1][(ind_y1 + qty_stb - 1) % qty_stb]);
				text_for_shifr.push_back(matrix_kluch[ind_x2][(ind_y2 + qty_stb - 1) % qty_stb]);
			}

			//Если буквы биграммы находятся в одном столбце
			else if (ind_y1 == ind_y2) {
				text_for_shifr.push_back(matrix_kluch[(ind_x1 + qty_str - 1) % qty_str][ind_y1]);
				text_for_shifr.push_back(matrix_kluch[(ind_x2 + qty_str - 1) % qty_str][ind_y2]);
			}

			//Если буквы биграммы находятся в разных строках и разных столбцах
			else if ((ind_x1 != ind_x2) && (ind_y1 != ind_y2)) {
				text_for_shifr.push_back(matrix_kluch[ind_x1][ind_y2]);
				text_for_shifr.push_back(matrix_kluch[ind_x2][ind_y1]);
			}
			k += 2;
		}
		INT lenght_text_for_shifr = size(text_for_shifr) - 1;
		for (INT i = 0; i < lenght_text_for_shifr; i++) {		//Приведение исходного текста для шифрования к требуемуму виду
			TCHAR &elsem_text_for_shifr = text_for_shifr.at(i);
			if (elsem_text_for_shifr == ';') {
				if (i == 0)
					zash_text.push_back(text_for_shifr[i]);
				else if (i == lenght_text_for_shifr)
					break;
				else if (text_for_shifr[i - 1] == text_for_shifr[i + 1]) 
					continue;
				else
					zash_text.push_back(text_for_shifr[i]);
			}
			else
				zash_text.push_back(text_for_shifr[i]);
		}
	}

	for (INT i = 0; i < qty_str; i++)   //Удаляем ключ матрицу
		delete[] matrix_kluch[i];
	delete[] matrix_kluch;


	zash_text.push_back(NULL);
	theApp.pFrame->m_wndView.Edit_vivod->SetWindowTextW(&zash_text.at(0));
	
	clock_t end = clock();
	return (DOUBLE)(end - start) / CLOCKS_PER_SEC;
}