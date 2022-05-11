#include<iostream>
#include"pop_all.h"
template<class T> T* PoP_back(T* arr, int& n)
{
	T* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<class T> T* PoP_front(T* arr, int& n)
{
	T* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<class T>T** pop_row_back(T** arr, int& rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}
template<class T> T** pop_row_front(T** arr, int& rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}

template<class T> T** pop_cols_back(T** arr, const int rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	cols--;
	delete[] arr;
	return buffer;
}
template<class T> T** pop_cols_front(T** arr, const int rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}
	cols--;
	delete[] arr;
	return buffer;
}