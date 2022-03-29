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
		/*switch (dec % 16)
		{
		case 10: hex[i] = 'A';break;
		case 11: hex[i] = 'B';break;
		case 12: hex[i] = 'C';break;
		case 13: hex[i] = 'D';break;
		case 14: hex[i] = 'E';break;
		case 15: hex[i] = 'F';break;
		}*/
		dec /= 16;
	}
	cout << "Шестнадцатеричное число: ";
	for (i--;i >= 0;i--)
	{
			switch (hex[i])
			{
			case 10: cout << "A";break;
			case 11: cout << "B";break;
			case 12: cout << "C";break;
			case 13: cout << "D";break;
			case 14: cout << "E";break;
			case 15: cout << "F";break;
			default:cout << hex[i];
			}
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