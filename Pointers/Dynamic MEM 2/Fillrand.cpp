#include"Fillrand.h"
#include<iostream>
 template<class T> void Fillrand(T* arr, int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() / (n * n);
	}
}
template<class T> void Fillrand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() / (rows*cols);
		}
	}
}