#include<iostream>
using namespace std;
//#define SQUARE
//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define TRIANGLE_1
//#define TRIANGLE_2
//#define TRIANGLE_3
//#define TRIANGLE_4
//#define RHOMBUS_1
//#define HARDSQUARE
#define SUPER_HARDSQUARE
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef SQUARE
	int n;
	cout << "¬ведите число: ";cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			cout << "# ";
		}
		cout << endl;
	}
#endif
#ifdef TASK_1
	int n;
	cout << "¬ведите число: ";cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif
#ifdef TASK_2
	int n;
	cout << "¬ведите число: ";cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = n;j > i;j--)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif
#ifdef TASK_3
	int n;
	cout << "¬ведите число: ";cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = n;j > i;j--)
		{
			cout.width(5);
			cout << "*";
		}
		cout << endl;
	}
#endif
#ifdef TASK_4
	int n;
	cout << "¬ведите число: ";cin >> n;

	for (int i = 0;i < n;i++)
	{
		for (int j = n;j > i;j--)
		{
			//cout.width(6);
			cout << right;
			cout << "* ";
		}
		cout << endl;
	}
#endif
#ifdef TRIANGLE_1
	int n;
	cout << "¬ведите число: "; cin >> n;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif
#ifdef TRIANGLE_2
	int n;
	cout << "input number: "; cin >> n;
	for (int i = 0; i < n;i++)
	{
		for (int j = i; j < n;j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif
#ifdef TRIANGLE_3
	int n;
	cout << "input number: "; cin >> n;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < i; j++) cout << "  ";
		for (int j = i; j < n; j++) cout << "* ";
		cout << endl;
	}
#endif
#ifdef TRIANGLE_4
	int n;
	cout << "input number: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) cout << "  ";
		for (int j = 0; j <= i; j++) cout << "* ";
		cout << endl;
	}
#endif
#ifdef RHOMBUS_1
	int n;
	cout << "input number: ";cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int x = i + 1; x < n; x++)cout << " ";
		for (int x = i; x == i; x++)
		{
			cout << "/";
			for (int j = 1; j <= x; j++)cout << "  ";
			for (int j = x; j == x; j++)cout << " \\";
		}
		cout << endl;
	}

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < a;b++)cout << " ";
		for (int b = a; b <= a; b++)
		{
			cout << "\\";
			for (int j = a + 1; j < n; j++)cout << "  ";
			for (int j = a; j == a; j++)cout << " /";
		}
		cout << endl;
	}
#endif
#ifdef HARDSQUARE
	int n;
	cout << "Input number: "; cin >> n;
	for (int i = 0; i < n;i++)
	{
		if ((double)i / 2 != i / 2)
		{
			for (int j = 0; j < n;j++)
			{
				if ((double)j / 2 != j / 2)cout << " + ";
				else cout << " - ";
			}
		}
		else
		{
			for (int j = 0; j < n;j++)
			{
				if ((double)j / 2 != j / 2)cout << " - ";
				else cout << " + ";
			}
		}
		cout << endl;
	}
#endif
#ifdef SUPER_HARDSQUARE
	int n;
	cout << "Input number: "; cin >> n;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			for (int f = 0; f < n;f++)
			{
				if (i % 2 == f % 2)
				{
					for (int k = 0; k < n; k++)cout << " -";
				}
				else
				{
					for (int g = 0; g < n; g++)cout << " *";
				}
			}
			cout << endl;
		}
	}

#endif
}
