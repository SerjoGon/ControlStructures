#include<iostream>
using namespace std;

int fib(int a);

void main()
{
	setlocale(LC_ALL, "RU");
	int a, i = 0;
	cout << "������� ����� �� ���� ��������� ��������?"; cin >> a;
	cout << a   << " ����� �� ���� ���������: ";
	while (i < a)
	{
		cout << " " << fib(i);
		i++;
	}
}
int fib(int a)
{
	if (a <= 1)
	{
		return a;
	}
	else
		return fib(a - 1) + fib(a - 2);
}