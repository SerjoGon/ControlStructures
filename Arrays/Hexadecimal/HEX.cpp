#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int dec = 0;
	const int size = 8;
	int hex[size] = {};
	cout << "Введите десятичное число: "; cin >> dec;
	int i = 0;
	for (; dec; i++)
	{
		hex[i] = dec % 16;
		dec /= 16;
	}
	cout << "Шестнадцатеричное число: ";
	for (i--;i >= 0;i--)
	{
		cout << (hex[i] = 10 ? char(65) : hex[i] = 11 ? char(66) : hex[i] = 12 ? char(67) : hex[i] = 13 ? char(68) : hex[i] = 14 ? char(69) : hex[i] = 15 ? char(70):hex[i]);
			/*switch (hex[i])
			{
			case 10: cout << "A";break;
			case 11: cout << "B";break;
			case 12: cout << "C";break;
			case 13: cout << "D";break;
			case 14: cout << "E";break;
			case 15: cout << "F";break;
			default:cout << hex[i];
			}*/
		/*if (hex[i] >= 10)
		{
			switch (hex[i])
			{
			case 10: cout << "A";break;
			case 11: cout << "B";break;
			case 12: cout << "C";break;
			case 13: cout << "D";break;
			case 14: cout << "E";break;
			case 15: cout << "F";break;
			}
		}
		else cout << " " << hex[i] << " ";*/

	}

}