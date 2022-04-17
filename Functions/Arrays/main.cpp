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
	cout << "Введите количество сдвигов влево:"; cin >> shiftsL;
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
	ShiftR(arr1, n, shiftsR);	Print(arr1, n);
	ShiftL(arr1, n, shiftsL); Print(arr1, n);
	cout << delimetr << endl;
	int arr2[ROW][COL];
	Fillrand(arr2,ROW,COL);	Print(arr2, ROW, COL);
	Sort(arr2, ROW,COL);	Print(arr2, ROW,COL);
	cout << "Сумма элементов массива: " << Sum(arr2, ROW,COL) << endl;
	cout << "Среднее арифметическое элементов массива: " << AVG(arr2, ROW,COL) << endl;
	cout << "Минимальное значение массива: " << MIN(arr2, ROW,COL) << endl;
	cout << "Максимальное значение массива: " << MAX(arr2, ROW,COL) << endl;
	cout << delimetr << endl;
	double arr3[ROW][COL];
	Fillrand(arr3,ROW,COL);	Print(arr3, ROW, COL);
	Sort(arr3, ROW,COL);	Print(arr3, ROW,COL);
	cout << "Сумма элементов массива: " << Sum(arr3, ROW,COL) << endl;
	cout << "Среднее арифметическое элементов массива: " << AVG(arr3, ROW,COL) << endl;
	cout << "Минимальное значение массива: " << MIN(arr3, ROW,COL) << endl;
	cout << "Максимальное значение массива: " << MAX(arr3, ROW,COL) << endl;
	cout << delimetr << endl;
	char arr4[n];
	Fillrand(arr4, n);	Print(arr4, n);
	Sort(arr4, n);	Print(arr4, n);
	cout << "Минимальное значение массива: " << MIN(arr4, n) << endl;
	cout << "Максимальное значение массива: " << MAX(arr4, n) << endl;
	ShiftR(arr4, n, shiftsR);	Print(arr4, n);
	ShiftL(arr4, n, shiftsL); Print(arr4, n);
	cout << delimetr << endl;
	char arr5[ROW][COL];
	Fillrand(arr5, ROW, COL);	Print(arr5, ROW, COL);
	Sort(arr5, ROW, COL);	Print(arr5, ROW, COL);
	cout << "Минимальное значение массива: " << MIN(arr5, ROW, COL) << endl;
	cout << "Максимальное значение массива: " << MAX(arr5, ROW, COL) << endl;
	cout << delimetr << endl;
}
