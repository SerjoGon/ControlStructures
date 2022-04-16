#pragma once
#include"Constants.h"

template<typename T>
T Sum(T arr[], const int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++) sum += arr[i];
	return sum;
}
template<typename T>
T Sum(T arr[ROW][COL], const int ROW, const int COL)
{
	T sum = 0;
	for (int i = 0; i < ROW;i++)
	{
		for (int j = 0; j < COL; j++) sum += arr[i][j];
	}
	return sum;
}