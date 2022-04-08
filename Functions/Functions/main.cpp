#include<iostream>
using namespace std;

int Add(int a, int b); // прототип функции или же обьявление функции (function declaration)
int Sub(int a, int b);// он нужен для того что бы имя функции и ее список принимаемых параметров были иъвестны на момент вызова
int Mul(int a, int b); // прототип состоит только из заголовка функции 
double Div(int a, int b /*Принимаемые параметры */);
double Power(int a, int b);

void main()
{
	setlocale(LC_ALL, "Ru");
	int a, b;
	cout << "Введите два числа, второе число будет стенью первого : "; cin >> a >> b;
	int c = Add(a, b); // function call - вызов функции
	cout << a << "+" << b << " = " << c << endl;
	cout << a << "-" << b << " = " << Sub(a,b) << endl;
	cout << a << "*" << b << " = " << Mul(a,b /* Принимаемые параметры*/) << endl;
	cout << a << "/" << b << " = " << Div(a,b) << endl;
	cout << a << "^" << b << " = " << Power(a,b) << endl;
}
int Add(int a, int b) // Реализация функции - определение функции - Function definition
{ // Реализует тот алгоритм за который ответсвенна функция реализует то что делает функция 
	int c = a + b;
	return c;
}
int Sub(int a, int b) // а реализация состоит из заголовка и тела функции
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
double Div(int a, int b)
{
	return (double)a / b;
}
double Power(int a, int b)
{
	int c = 1;
	//if (b < 1)return 1;
	for (int i = 0; i < b; i++) c *= a;	
	return c;
}