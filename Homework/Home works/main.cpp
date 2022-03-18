#include<iostream>
using namespace std;
#define TASK_1
//#define TASK_2
//#define TASK_3
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TASK_1
	double a = 0, b = 1, n, c = a + b;
	cout << "Введите количество чисел из ряда Фибоначчи:";cin >> n;
	for (int i = 0; i < n;i++)
	{
		cout << a << " | "; a = b, b = c, c = a + b;
	}
#endif
#ifdef TASK_2
	int c = 0, b = 1, i;
	for (i = 2;b < 11; i++)
	{
		c = b * i;

		if (i > 10)
		{
			i = 1, b++;
			cout << endl;
		}
		else if (b <= 10) cout << b << "*" << i << "=" << c/* << endl*/ << "\n";
	}
#endif
#ifdef TASK_3
	int c = 0, b = 1, i, d, j = 2;
	for (i = 1, d = 0;b <= 10; i++, d++)
	{
		if (d >= 10 && j < 11)
		{
			cout << endl;
			cout << " " << j << "\t";
			d = 0, j++;
		}
		c = b * i;
		if (i > 10)
		{
			i = 1, b++;
		}
		else if (b <= 10) cout /*<< b << "*" << i << "="*/ << " " << c << "\t"/* << endl*/;
	}
#endif
}