#pragma once
#include"Constants.h"
#include"Fillrand.h"

template<class T>
T MAX(T arr[], const int n)
{
	T max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
template<class T>
T MAX(T arr[ROW][COL], const int ROW, const int COL)
{
	T max = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	return max;
}