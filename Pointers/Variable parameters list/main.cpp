#include<iostream>
#include<stdarg.h>
using namespace std;
//#define VALIST
//template<typename T> T sum(T a, T b);
int sum2(int count, int number, ...);
int product(int number...);
//void print(int value...);

void main()
{
	setlocale(LC_ALL, "RU");
	//cout << sum(2, 3);
	cout<< "Сумма:" << sum2(5, 3, 5, 8, 13, 21);
	cout << endl;
	cout<< "Произведение:" << product(3, 5, 8, 13, 21,0);
	cout << endl;
	//print(3, 5, 8, 13, 21);
	//cout << endl;
}
//template<typename T> T sum(T a, T b)
//{
//	return a + b;
//}

int sum2(int count, int number, ...)
{
	int sum = 0;
	int* p_number = &number; // получаем адресс первого слагаемого
	for (int i = 0; i < count; i++)
	{
		sum += *p_number++;
		p_number++;
	}
	return sum;
}
int product(int number...)
{
	int product = 1;
	for (int* p_number = &number;*p_number != 0; p_number++)
	{
		product *= *p_number++;
	}
	return product;
}
#ifdef VALIST
void print(int value...)
{
	va_list list;
	va_start(list, value);
	for (int i = value;i !=0 ; i = va_arg(list, int))
	{
		cout << i << "\t";
	}
	va_end(list);
}
#endif