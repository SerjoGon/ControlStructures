//ControlStructures
#include<iostream>
using namespace std;
//#define TEMPERATURE
//#define AND
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TEMPERATURE
	int t; // temperature
	cout << "������� ����������� �������: ";
	cin >> t;
	if (t > 0)
	{
		cout << "�� ����� �����!" << endl;	
	}
	else
	{
		cout << "�� ����� �������!!! " << endl;
	}
	if else (t < -100)
	{
		cout << "���������!!!" << endl;
	}
#endif
#ifdef AND
	int a;
	cout << "������� �����: ";
	cin >> a;
	if (a > 0 && a < 10)
	{
		cout << "�� ������!!! " << endl;
	}
	else
	{
		cout << "������!!!" << endl;
	}
#endif
	double x = 0.0;
	double y = 0.0;
	double result = 0.0;
	char oper = '+,-,*,/';
	cout << "���������� �����������!!!" << endl << endl;
	cout << "����������� ������� �������� ��� ����������! � �������: a + b | a - b | a * b | a / b " << endl;
	cin >> x >> oper >> y;
	double Calculate(double x, char oper, double y);
	switch (oper)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	default:
		return 0.0;
	}
	while (true)
	{
		cin >> x >> oper >> y;
		result = Calculate(x, oper, y);
		cout << "���������: " << result << endl;
	}


}