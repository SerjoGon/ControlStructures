#include<iostream>
using namespace std;
#define tab "\t"
#define line "\n________________________\n"

void main()
{
	setlocale(LC_ALL, "RUS");
	const int ROWS = 8;
	const int COLS = 5;
	int arr[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	// вывод исходного массива на экран
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
	// сортировка массива
	int iter = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = (k == i? j+1 : 0); l < COLS; l++)
				{
					if (arr[k][l] < arr[i][j])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
					}
					iter++;
				}
			}
		}
	}

	// вывод отсортированного массива
		cout << " ќтсортирован за "<< iter<<" итераций " << endl;
		cout << " ќтсортированный массив :" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}