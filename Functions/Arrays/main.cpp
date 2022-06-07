#include<iostream>
using namespace std;
#include"Conctants.h"
#include"Fillrand.h"
#include"Print.h"
#include"Statistics.h"
#include"Sort.h"
#include"Shifts.h"

void main()
{
	setlocale(LC_ALL, "RU");
	const int n = 5;
	int arr[n];
	Fillrand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(arr, n) << endl;
	cout << "Минимальное значение массива: " << MIN(arr, n) << endl;
	cout << "Максимальное значение массива: " << MAX(arr, n) << endl;
	int shiftsR;
	int shiftsL;
	cout << "Введите количесвто сдвигов массива вправо:"; cin >> shiftsR;
	cout << "Введите количество сдвигов:"; cin >> shiftsL;
	ShiftR(arr, n, shiftsR);
	Print(arr, n);
	ShiftL(arr, n, shiftsL);
	ShiftL(arr, n, shiftsL);
	Print(arr, n);
	cout << delimetr << endl;

	const int m = 5;
	double brr[m];
	Fillrand(brr, m, 0, 30);
	Print(brr, m);
	Sort(brr, m);
	Print(brr, m);
	cout << "Сумма элементов массива: " << Sum(brr, m) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(brr, m) << endl;
	cout << "Минимальное значение массива: " << MIN(brr, m) << endl;
	cout << "Максимальное значение массива: " << MAX(brr, m) << endl;
	cout << delimetr << endl;

	int arr2[ROWS][COLS];
	double arr3[ROW][COL];
	char arr4[ROW][COL];
	Fillrand(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	Sort(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	cout << "Сумма элементов массива:" << Sum(arr2, ROWS, COLS) << endl;
	cout << "Среднее арифметическое элементов массива:" << AVG(arr2, ROWS, COLS) << endl;
	cout << "Минимальное значение массива:" << MIN(arr2, ROWS, COLS) << endl;
	cout << "Максимальное значение массива:" << MAX(arr2, ROWS, COLS) << endl;
	cout << delimetr << endl;

	Fillrand(arr3, ROW, COL);
	Print(arr3, ROW, COL);
	Sort(arr3, ROW, COL);
	cout << delimetr << endl;
	Print(arr3, ROW, COL);
	cout << "Сумма элементов массива:" << Sum(arr3, ROW, COL) << endl;
	cout << "Среднее арифметическое элементов массива:" << AVG(arr3, ROW, COL) << endl;
	cout << "Минимальное значение массива:" << MIN(arr3, ROW, COL) << endl;
	cout << "Максимальное значение массива:" << MAX(arr3, ROW, COL) << endl;
	cout << delimetr << endl;
	Fillrand(arr4, ROW, COL);
	Print(arr4, ROW, COL);
}
