#include<iostream>
using namespace std;
//#define STEPEN
//#define ASCII
#define FIBONACHHI
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef STEPEN
	double a;
	int n;
	double N = 1;
	cout << "¬ведите основание степени:";cin >> a;
	cout << "¬ведите показатель степени:";cin >> n;
	cout << a << "^" << n << "=";
	if (n < 0)
	{
		n = -n;
		a = 1 / a;
	}
	for (int i = 0; i < n;i++)
	{
		N *= a;
	}
	cout << N << endl;
#endif
#ifdef ASCII
	for (int i = 0; i < 256; i++)
	{
		if (i % 16 == 0)cout << endl;
		cout << (char)i << " | ";
	}
#endif
#ifdef FIBONACHHI
	int a = 0;
	int b = 1;
	int c = a+b;
	int n;
	cout << " ¬ведите количество чисел из р€да ‘ибоначчи: "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << a << "\t";
		a = b;
		b = c;
		c = a + b;
		//cout << c << endl;
	}
#endif
}