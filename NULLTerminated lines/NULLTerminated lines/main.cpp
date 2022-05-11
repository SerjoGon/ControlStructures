#include<iostream>
#include<Windows.h>
using namespace std;
int StringLength(const char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
int to_int_number(char str[]);
void main()
{
	setlocale(LC_ALL, "");

	for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
	cout << 'A' - 'a' << endl;
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Введеная строка имеет длину: " << StringLength(str) << endl;;
	shrink(str);
	cout << str << endl;
	to_upper(str);
	cout << str << endl;
	
	/*to_lower(str);
	cout << str << endl;*/
	cout << "Проверка на полиндром!"/*, введите значение:"; cin.getline(str, SIZE)*/;
	if (is_palindrome(str))cout << '\n' << "Это палиндром!!!" << '\n';
	else cout << '\n' << "Это не палиндром!!!" << '\n';
	if (is_int_number(str))cout << '\n' << "Это целое десятичное число!!!" << '\n';
	else cout << '\n' << "Это не целое десятичное число!!!" << '\n';

}
int StringLength(const char str[])
{
	int count = 0;
	for (;str[count];count++);
	return count;
}
void to_upper(char str[])
{
	for (int i = 0; str[i];i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32;//En
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;//Ru
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i];i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;//En
		if (str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;//Ru
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])
{
	bool palindrome = true;
	for (int i = 1; str[i]; i++)
	{
		if(str[i] == ' ')
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	int length = StringLength(str);
	for (int i = 0; i < (length / 2);i++)
	{
		if (str[i] != str[length - i - 1])
		{
			palindrome = false;
			break;
		}
	}
	return palindrome;
}
bool is_int_number(char str[])
{
	bool number_is_int = true;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			number_is_int = false;
			return number_is_int;
		}
	}
	return number_is_int;
}
int to_int_number(char str[])
{
	int number;
}