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
	cout << "����� ��������� �������: " << Sum(arr, n) << endl;
	cout << "������� �������������� ��������� ������� :" << AVG(arr, n) << endl;
	cout << "����������� �������� �������: " << MIN(arr, n) << endl;
	cout << "������������ �������� �������: " << MAX(arr, n) << endl;
	int shiftsR;
	int shiftsL;
	cout << "������� ���������� ������� ������� ������:"; cin >> shiftsR;
	cout << "������� ���������� �������:"; cin >> shiftsL;
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
	cout << "����� ��������� �������: " << Sum(brr, m) << endl;
	cout << "������� �������������� ��������� ������� :" << AVG(brr, m) << endl;
	cout << "����������� �������� �������: " << MIN(brr, m) << endl;
	cout << "������������ �������� �������: " << MAX(brr, m) << endl;
	cout << delimetr << endl;

	int arr2[ROWS][COLS];
	double arr3[ROW][COL];
	char arr4[ROW][COL];
	Fillrand(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	Sort(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	cout << "����� ��������� �������:" << Sum(arr2, ROWS, COLS) << endl;
	cout << "������� �������������� ��������� �������:" << AVG(arr2, ROWS, COLS) << endl;
	cout << "����������� �������� �������:" << MIN(arr2, ROWS, COLS) << endl;
	cout << "������������ �������� �������:" << MAX(arr2, ROWS, COLS) << endl;
	cout << delimetr << endl;

	Fillrand(arr3, ROW, COL);
	Print(arr3, ROW, COL);
	Sort(arr3, ROW, COL);
	cout << delimetr << endl;
	Print(arr3, ROW, COL);
	cout << "����� ��������� �������:" << Sum(arr3, ROW, COL) << endl;
	cout << "������� �������������� ��������� �������:" << AVG(arr3, ROW, COL) << endl;
	cout << "����������� �������� �������:" << MIN(arr3, ROW, COL) << endl;
	cout << "������������ �������� �������:" << MAX(arr3, ROW, COL) << endl;
	cout << delimetr << endl;
	Fillrand(arr4, ROW, COL);
	Print(arr4, ROW, COL);
}
