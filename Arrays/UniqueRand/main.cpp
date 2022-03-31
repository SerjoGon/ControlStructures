#include<iostream>
using namespace std;
#define tab "\t"
//#define UNIQUE
void main()
{
	setlocale(LC_ALL, "");

	/*const int n = 10;
	int arr[n] = {};
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i;j++)
		{
			if (arr[i] == arr[j])
			{
				arr[i] = rand() % n;
				j = -1;
			}
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/

	const int n = 10;
	int arr[n] = {};
	bool unique;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}

#ifdef UNIQUE
	for (int i = 0; i < n; i++)
	{
		do
		{
			arr[i] = rand() % n;
			unique = true;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
	}
} while (!unique);
	}
#endif
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}