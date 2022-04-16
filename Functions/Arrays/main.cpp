#include<iostream>
using namespace std;
#define tab "\t"
#define delimetr "\n___________________________\n"
#include"Constants.h"
#include "Fillrand.h"
#include"Print.h"
#include "Sort.h"
#include "AVG.h"
#include "MIN.h"
#include"MAX.h"
#include"ShiftR.h"
#include"ShiftL.h"

void main()
{
	setlocale(LC_ALL, "RU");
	int shiftsR;
	int shiftsL;
	int arr[n];
	Fillrand(arr, n);	Print(arr, n);
	Sort(arr, n);	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(arr, n) << endl;
	cout << "Минимальное значение массива: " << MIN(arr, n) << endl;
	cout << "Максимальное значение массива: " << MAX(arr, n) << endl;
	cout << "Введите количесвто сдвигов массива вправо:"; cin >> shiftsR;
	cout << "Введите количество сдвигов:"; cin >> shiftsL;
	ShiftR(arr, n, shiftsR);	Print(arr, n);
	ShiftL(arr, n, shiftsL);	Print(arr, n);
	cout << delimetr << endl;
	double arr1[n];
	Fillrand(arr1, n);	Print(arr1, n);
	Sort(arr1, n);	Print(arr1, n);
	cout << "Сумма элементов массива: " << Sum(arr1, n) << endl;
	cout << "Среднее арифметическое элементов массива: " << AVG(arr1, n) << endl;
	cout << "Минимальное значение массива: " << MIN(arr1, n) << endl;
	cout << "Максимальное значение массива: " << MAX(arr1, n) << endl;
	cout << "Введите количество сдвигов массива вправо: ";cin >> shiftsR;
	cout << "Введите количество сдвигов массива влево: ";cin >> shiftsL;
	ShiftR(arr1, n, shiftsR);	Print(arr1, n);
	ShiftL(arr1, n, shiftsL); Print(arr1, n);
}
