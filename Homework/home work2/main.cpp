#include<iostream>
using namespace std;

#define CALC_1
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CALC_1
	double a, b;
	char s;
	cout << "¬ведите выражение: ";
	cin >> a >> s >> b;
	switch (s)
	{
	case '+': cout << a + b << endl;break;
	case '-': cout << a - b << endl;break;
	case '*': cout << a * b << endl;break;
	case '/': cout << a / b << endl;break;
	}
#endif
}
