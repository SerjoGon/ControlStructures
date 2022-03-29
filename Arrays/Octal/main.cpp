#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int dec = 0;
	const int size = 11;
	int oct[size] = {};
	cout << "Введите десятичное число: "; cin >> dec;
	int i = 0;
	for (; dec;i++)
	{
		oct[i] = dec % 8;
		dec /= 8;
	}

	cout << "Восьмеричное число: ";
	for (i--; i >= 0;i--)
	{
		cout << oct[i];
	}

}