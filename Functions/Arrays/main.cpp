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
	cout << "����� ��������� �������: " << Sum(arr, n) << endl;
	cout << "������� �������������� ��������� ������� :" << AVG(arr, n) << endl;
	cout << "����������� �������� �������: " << MIN(arr, n) << endl;
	cout << "������������ �������� �������: " << MAX(arr, n) << endl;
	cout << "������� ���������� ������� ������� ������:"; cin >> shiftsR;
	cout << "������� ���������� �������:"; cin >> shiftsL;
	ShiftR(arr, n, shiftsR);	Print(arr, n);
	ShiftL(arr, n, shiftsL);	Print(arr, n);
	cout << delimetr << endl;
	double arr1[n];
	Fillrand(arr1, n);	Print(arr1, n);
	Sort(arr1, n);	Print(arr1, n);
	cout << "����� ��������� �������: " << Sum(arr1, n) << endl;
	cout << "������� �������������� ��������� �������: " << AVG(arr1, n) << endl;
	cout << "����������� �������� �������: " << MIN(arr1, n) << endl;
	cout << "������������ �������� �������: " << MAX(arr1, n) << endl;
	cout << "������� ���������� ������� ������� ������: ";cin >> shiftsR;
	cout << "������� ���������� ������� ������� �����: ";cin >> shiftsL;
	ShiftR(arr1, n, shiftsR);	Print(arr1, n);
	ShiftL(arr1, n, shiftsL); Print(arr1, n);
}
