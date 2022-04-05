#include <iostream>
using namespace std;
#define tab "\t"
#define LINE "\n_______________________\n"
void main()
{
	setlocale(LC_ALL, "RU");
	const int ROWS = 4;
	const int COLS = 5;
	int arr[ROWS][COLS] = {};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS;j++)
		{
			bool unique = true; // предпологаем что случ число будеот уникальным
			do
			{
				unique = true;
			arr[i][j] = rand() % (ROWS * COLS);
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (k == i ? j : COLS); l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						unique = false;
						break;
					}
				}
				if (!unique) break;
			}
			} while (!unique);
			// но это нужно проверить
		}
	}
	for (int i = 0; i < ROWS;i++)
	{
		for (int j = 0; j < COLS;j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}
