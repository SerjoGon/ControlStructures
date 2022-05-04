#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RU");
	int a = 2;
	int& ra = a;
	ra += a;
	cout << a  << endl;
	cout << &a << endl;
	cout << &ra<< endl;
}