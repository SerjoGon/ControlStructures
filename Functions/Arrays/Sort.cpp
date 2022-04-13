#include"Sort.h"
#include"stdafx.h"

void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i <= (ROWS * COLS); i++)// общий цикл для строк и столбцов
	{
		for (int j = 0; j < ROWS; j++)
		{
			for (int k = 0;k < COLS - 1; k++)
			{
				if (arr[j][k] > arr[j][k + 1]) // сортировка строк
				{
					int buffer = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = buffer;
				}
			}
		}
		for (int j = 0; j < COLS;j++)
		{
			for (int k = 0;k < ROWS - 1; k++)
			{
				if (arr[k][j] > arr[k][j + 1])// сортировка столбцов
				{
					int buffer = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = buffer;
				}
			}
		}
	}
}
void Sort(double arr[ROW][COL], const int ROW, const int COL) // сортировка массива double
{
	for (int i = 0; i < (ROW * COL);i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL - 1; k++)
			{
				if (arr[j][k] > arr[j][k + 1])
				{
					double buff = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = buff;
				}
			}
		}
		for (int j = 0; j < COL;j++)
		{
			for (int k = 0;k < ROW - 1; k++)
			{
				if (arr[k][j] > arr[k][j + 1])
				{
					double buff = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = buff;
				}
			}
		}
	}
}
