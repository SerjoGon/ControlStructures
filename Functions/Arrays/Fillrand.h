#pragma once
#include<iostream>
#include"Constants.h"
template<typename T>
void Fillrand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)rand() /123;
	}
}
template<typename T1>
void Fillrand(T1 arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = (double)rand()/123;
		}
	}
}
