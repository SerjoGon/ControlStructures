#include"Print.h"
#include<iostream>
template<class T> void Print(T* arr, int& n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}
template<class T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template<class T> void PRINTING_WITH_THE_MAGIC_OF_PONTERS(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << *(*(arr + i) + j) << '\t';
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}