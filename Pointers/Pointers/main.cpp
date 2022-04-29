#include<iostream>
using namespace std;
//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	// p - pointer(венгерская нотация)
	cout << a << endl;// вывод значения "а" на экран 
	cout << &a << endl;// взятие адреса переменной "а" прямо при выводе
	cout << pa << endl;// вывод на экран адреса переменной "а" хранящегося в указателе "ра"
	cout << *pa << endl;//разименование указателя "ра" и вывод на экран значения по адрессу
	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
	//int - int 
	// int* - указатель на int
	// double - double
	//double* - указатель на double
//char - char
	//char* - указатель на char
#endif
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i<< "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i)<< "\t";
	}
	cout << endl;
	for (int* p_arr = arr;*p_arr != 0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;
}