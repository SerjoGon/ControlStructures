#pragma once
#include"Constants.h"

template<typename T>
void Sort(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				T buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
template<typename T>
void Sort(T arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < (ROW * COL);i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL-1;k++)
			{
				if (arr[j][k] > arr[j][k + 1])
				{
					T buffer = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = buffer;
				}
			}
		}
		for (int j = 0; j < COL; j++)
		{
			for (int k = 0; k < ROW - 1;k++)
			{
				if (arr[k][j] > arr[k][j + 1])
				{
					T buffer = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = buffer;
				}
			}
		}
	}
}