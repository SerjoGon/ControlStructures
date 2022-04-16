#pragma once
#include<iostream>
#include"Constants.h"
template<typename T>
void Fillrand(T arr[], const int n, int min = 0, int max = 100)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}
template<typename T1>
void Fillrand(T1 arr[ROW][COL], const int n, int min = 0, int max = 100)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % (max - min) + min;
		}
	}
}
