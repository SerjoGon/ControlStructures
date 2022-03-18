#include<iostream>
using namespace std;
//#define MULTIPLICATION_TABLE
#define PIFFAGOR
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef MULTIPLICATION_TABLE
	int n = 10;
	for (int i = 1; i <= n;i++)
	{
		cout << "" << i << endl;
		for (int j = 1; j <= n;j++)
		{
			if (i < 10) cout << " ";
			cout << i << " * ";
			if (j < 10) cout << " ";
			cout << j << " = ";
			if (i * j < 10) cout << " ";
			if (i * j < 100) cout << " ";
			cout << i * j << endl;
		}
		cout << endl;
	}
#endif
#ifdef PIFFAGOR
	int n = 10;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout.width(5);
			cout << i * j /*<< "\t"*/;
		}
		cout << endl;
	}
#endif
}