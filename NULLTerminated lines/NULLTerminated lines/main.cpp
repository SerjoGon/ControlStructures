#include<iostream>
#include<Windows.h>
using namespace std;
int StringLength(const char str[]);
void to_upper(const char str[]);
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "RU");
	////char str[] = {'H','e','l','l','o','!', 0};
	//char str[] = "Hello!";
	//cout << str << endl;
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "¬ведите строку: ";
	//SetConsoleCP(1251);
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "¬ведена€ строка имеет длину: " << StringLength(str);
}
int StringLength(const char str[])
{
	int count = 0;
	for (;str[count];count++);
	////for(int i = 0; i < 256; i++)
	//{
	//	count++;
	//	if (str[i] == 0) break;
	//}
	return count;
}
void to_upper(const char str[])
{
	int i = 0;
	for (; str[i];i++)
	{
		if (str[i] >= 97 || str[i] <= 122)str[i] - 32;
		else if (str[i] >= 160 || str[i] <= 175)str[i] - 32;
		else if (str[i] >= 224 || str[i] <= 239)str[i] - 80;
		else if (str[i] == 241) str[i] - 1;
	}
}