#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Ru");
	int decimal = 0; // Десятичное число вводимое с клавиатуры
	//int n = 0;
	const int SIZE = 32; // Максимально возможная разрядность введенного числа
	bool bin[SIZE] = {}; // этот массив будет хранить разряды двоичного числа
	cout << "Введите десятичное число  :"; cin >> decimal;
	int i = 0;
	for ( ; decimal ; i++)
	{
		bin[i] = decimal % 2;
		decimal /= 2;
		//n++;
	}
	
	cout << "Двоичное число :";
	for (i--; i >= 0; i--)
	{
		cout << bin[i];
	}

}