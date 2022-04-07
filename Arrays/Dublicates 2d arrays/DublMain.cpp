#include<iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "RU");
	const int ROWS = 6;
	const int COLS = 6;
	int arr[ROWS][COLS] = {};
	// Заполнение массива случайными числами
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (ROWS + COLS);
		}
	}
	// Вывод массива
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	// Поиск дублей в массиве
	for (int i = 0;i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool alrdthr = false;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < j; l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						alrdthr = true;
						break;
					}
				}
				if (alrdthr)break;
			}
			if (alrdthr)continue;
			int count = 1;
			for (int k = i +1; k < ROWS; k++)
			{
				for (int l = j + 1; l < ROWS;l++)
				{
					if (arr[i][j] == arr[k][l]) count++;
				}
				if (count > 1) printf("Значение %d встречается %d  раз \n", arr[i][j], count);
			}
		}
	}
}