#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
	srand(time(NULL));
    // задание 1
	int nums[3][2], nmb = 0, sum = 0, prdct = 1; // sum - сложение || prdct - умножение
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			nums[i][j] = 0 + rand() % 30;
			cout << nums[i][j] << " ";// условие А
			nmb += nums[i][j];
			if (nums[i][j] >= 2 && nums[i][j] <= 9) { // условие В
				sum += nums[i][j]; prdct *= nums[i][j];
			}
		}
		cout << endl;
	}
	if (nmb % 2 == 0) // условие Б
		cout << "Сумма всех элементов чётное число: " << nmb;
	else
		cout << "Сумма всех элементов нечётное число " << nmb;
	
	// задание 2
	short nmb = 32767, str = 0, col = 0, a = 0; //32767 - макс число в short || nmb = min_el
	int nums[3][4], nums2[3][4], numsx[4]{ 0, 0, 0, 0 }, nums4[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> nums[i][j];
			if (nums[i][j] < nmb) { // находит мин эл массива
				nmb = nums[i][j]; str = i; col = j;
			}
		}
	}
	cout << "Наименьший элемент: " << nmb << endl;
	cout << "Его строка: " << str + 1 << "  Его столбец: " << col + 1 << endl << endl;// условие А1 и А2
	cout << "Начальная матрица: " << endl;
	for (int i = 0; i < 3; i++) { // выоводит начальную матрицу
		for (int j = 0; j < 4; j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Матрица после замены столбцов: " << endl; // условие Б (массив nums2)
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == col) {
				nums2[i][j] = nums[i][3];
				cout << nums2[i][j] << " ";
			}
			else if (j == 3) {
				nums2[i][j] = nums[i][col];
				cout << nums2[i][j] << " ";
			}
			else
				cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; // a - индекс элемента в массиве numsx (условие В)
	for (int i = 0; i < 3; i++) { // условие В (массив numsx)
		for (int j = 0; j < 4; j++) {
			if (nums[i][j] > 0) {
				numsx[a] += nums[i][j];
				a++;
			}
		}
		a = 0;
	}
	cout << "Массив условия В: ";
	while (a < 4) { // вывод условия В
		cout << numsx[a] << " ";
		a++;
	}
	cout << endl << "Массив условия Г: " << endl;
	for (int i = 0; i < 3; i++) { // условие Г (массив nums4)
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
				nums4[i][j] = nmb;
				cout << nums4[i][j] << " ";
			}
			else {
				nums4[i][j] = nums[i][j];
				cout << nums4[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	// задание 3

	short nmb = 0, n = 5;
	int nums[5][5], nums2[6][6], nums3[5][5], nums4[8][8], nums5[10][10];
	cout << "Условие А: " << endl;
	for (int i = 0; i < 5; i++) { // условие А 
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				nums[i][j] = 1;
				cout << nums[i][j] << " ";
			}
			else {
				nums[i][j] = 0;
				cout << nums[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << "Условие Б: " << endl;
	for (int i = 0; i < 6; i++) { // Условие Б
		for (int j = 0; j < 6; j++) {
			if (i == j) {
				nums2[i][j] = 6;
				cout << nums2[i][j] << " ";
			}
			else if (j > i) {
				nums2[i][j] = n;
				cout << nums2[i][j] << " ";
				n -= 1;
			}
			else if (i > j) {
				nums2[i][j] = 0;
				cout << nums2[i][j] << " ";
			}
		}
		n = 5;
		cout << endl;
	}
	cout << endl << "Условие В: " << endl;
	n = 4;// Условие В
	for (int i = 0; i < 5; i++) { // заполняет матрицу единицами по диагонали
		for (int j = 0; j < 5; j++) {
			if (j == n)
				nums3[i][j] = 1;
			else
				nums3[i][j] = 0;
		}
		n--;
	}
	n = 2; // число в матрице
	int k = 1; // шаг отступа
	for (int i = 0; i < 5; i++) { // заполняет матрицу числами, исходя изединиц
		for (int j = 0; j < 5; j++) {
			if (nums3[i][j] >= 1 && j != 4) {
				nums3[i][j + k] = n;
				n++;
			}
		}
		n = 2;
	}
	for (int i = 0; i < 5; i++) { // выводит матрицу
		for (int j = 0; j < 5; j++) {
			cout << nums3[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Условие Г: " << endl;// условие Г
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				nums4[i][j] = 1;
				cout << nums4[i][j] << " ";
			}
			else if (i % 2 == 0 && j % 2 != 0) {
				nums4[i][j] = 0;
				cout << nums4[i][j] << " ";
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				nums4[i][j] = 0;
				cout << nums4[i][j] << " ";
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				nums4[i][j] = 1;
				cout << nums4[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl << "Условие Д: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || j == 0 || i == 9 || j == 9) {
				nums5[i][j] = 4;
				cout << nums5[i][j] << " ";
			}
			else if (i == 1 || j == 1 || i == 8 || j == 8) {
				nums5[i][j] = 3;
				cout << nums5[i][j] << " ";
			}
			else if (i == 2 || j == 2 || i == 7 || j == 7) {
				nums5[i][j] = 2;
				cout << nums5[i][j] << " ";
			}
			else if (i == 3 || j == 3 || i == 6 || j == 6) {
				nums5[i][j] = 1;
				cout << nums5[i][j] << " ";
			}
			else if (i == 4 || j == 4 || i == 5 || j == 5) {
				nums5[i][j] = 0;
				cout << nums5[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	// задание 4
	int nums[2][4][3];
	short str = 0, col = 0, layer = 0, nmb = 0; // str = ось x||col = ось y|| layer = ось z
	for (int i = 0; i < 2; i++) { // ввод трёхмерной матрицы
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> nums[i][j][k];
			}
		}
	}
	for (int i = 0; i < 4; i++) { // проверка на образование плоскости в строках
		for (int j = 0; j < 3; j++) {
			if (nums[0][i][j] == nums[1][i][j] && nums[0][i][j] == nums[0][i][0])
				str++; // счётчик одинаковых чисел в строке
		}
		if (str == 3)
			cout << "Найдена плоскоть в " << i + 1 << " строке" << endl;
		str = 0;
	}
	for (int i = 0; i < 3; i++) { // проверка на образование плоскоти в колоннах
		for (int j = 0; j < 4; j++) {
			if (nums[0][j][i] == nums[1][j][i] && nums[0][j][i] == nums[0][0][i])
				col++; // счётчик одинаковых чисел в колоннах
		}
		nmb++; // nmb - номер колонны
		if (col == 4)
			cout << "Найдена плоскость в " << nmb << " колонне" << endl;
		col = 0;
	}
	nmb = nums[0][0][0];// numb - номер первого элемента в слое
	for (int k = 0; k < 2; k++) { // проверка на образование плоскости в слоях
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (nums[k][i][j] == nmb)
					layer++; // layer - счётчик одинаковых чисел в слое 
			}
		}
		if (layer == 12)
			cout << "Найдена плоскоть в " << k + 1 << " слое" << endl;
		layer = 0;
		nmb = nums[1][0][0];
	}
	cout << "Слой 1: " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				cout << nums[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl << "Слой 2: " << endl;
	}

	return 0;
}


