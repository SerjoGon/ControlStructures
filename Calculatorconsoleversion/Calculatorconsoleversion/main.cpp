#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "���������� �����������!!!" << endl;
	cout << "����������� ������� �������� ��� ����������! � �������: a + b | a - b | a * b | a / b " << endl;
	double x, y,d;
	char n;
	cin >> x >> n >> y;
	if (n == '+')
	{
		d = x + y;
		cout << "���������:" << d << endl;
	}
	else if (n == '-')
	{
		d = x - y;
		cout << "���������:" << d << endl;
	}
	else if (n == '*')
	{
		d = x * y;
		cout << "���������:" << d << endl;
	}
	else if (n == '/')
	{
		d = x / y;
		cout << "���������:" << d << endl;
	}
	
	
}