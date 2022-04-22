#include <iostream>
using namespace std;

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������!!!" << endl;
		return;
	}
	cout << "�� �� " << floor << "����� \n";
	elevator(floor - 1);
	cout << "�� �� " << floor << "����� \n";

}
int Factorial(int n)
{
	/*if (n < 0)return 0;
	if (n == 0)return 1;
	return n* Factorial(n - 1);*/
	return n < 0 ? 0 : n == 0 ? 1 : n * Factorial(n - 1);
}
double Power(double num, double pow);
int fib(int n);
//#define ELEVATOR
//#define SUPERPOWER
void main()
{
	setlocale(LC_ALL, "rus");
//
//#ifdef SUPERPOWER
//	double num, pow, res;
//	cout << "������� �����:"; cin >> num;
//	cout << "������� ������� �����:"; cin >> pow;
//	res = Power(num, pow);
//	cout << num << "^" << pow << "=" << res;
//	//cout << Factorial(num);
//#endif

#ifdef ELEVATOR
	//cout << "Hello World!!!" << endl;
	int n;
	cout << "������� ����� �����: "; cin >> n;
	elevator(n);
#endif 
	int n, i = 0;
	cout << "������� ����� �� ���� ��������� �������?";cin >> n;
	cout << n << "  ����� �� ���� ���������:  ";
	while (i < n)
	{
		cout << " " << fib(i);
		i++;
	}

}

//double Power(double num, double pow)
//{
//	/*if (pow == 0)return 1;
//	else if (pow > 0)return num* Power(num, pow - 1);
//	else if (pow < 0) return 1 / num * Power(num, pow + 1);*/
//	//return pow == 0 ? 1 : pow > 0 ? num * Power(num, pow - 1) : 1 / num * Power(num, pow + 1);
//	//return pow == 0 ? 1 : pow > 0 ? num * Power(num, pow - 1) : 1 / Power(num, -pow);
//}

int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
		return fib(n - 1) + fib(n - 2);
}