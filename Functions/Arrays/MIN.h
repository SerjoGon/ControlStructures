#pragma once
#include"Constants.h"
#include"Fillrand.h"

template<class T>
T MIN(T arr[], const int n)
{
	T min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
template<class T>
T MIN(T arr[ROW][COL], const int ROW, const int COL)
{
	T min = arr[0][0];
	for (int i = 0; i < ROW;i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
		}
	}
	return min;
}