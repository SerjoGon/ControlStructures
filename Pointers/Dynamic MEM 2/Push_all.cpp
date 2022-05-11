#include<iostream>
#include"Push_all.h"
template<class T> T* push_front(T* arr, int& n, int num)
{
	T* buffer = arr;
	buffer = new int[++n]{};
	for (int i = 1; i <= n;i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	buffer[0] = num;
	arr = buffer;
	return arr;
}
template<class T> T* push_back(T* arr, int& n, int num)
{
	T* buffer = arr;
	buffer = new int[n + 1]{};
	for (int i = 0; i < n;i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[n++] = num;
	arr = buffer;
	return arr;
}
template<class T> T** push_row_back(T** arr, int& rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [++rows];
	for (int i = 0; i < rows; i++)
	{
		//buffer[i] = arr[i];
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			if (i < rows - 1)buffer[i][j] = arr[i][j];
			else buffer[i][j] = rand() % 50;
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	return buffer;
}
template<class T> T** push_row_front(T** arr, int& rows, int& cols)
{
	T** buffer = arr;
	buffer = new int* [++rows];

	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i != 0) buffer[i][j] = arr[i - 1][j];
			else buffer[i][j] = rand() % 22;
		}
	delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}

template<class T> T** push_col_back(T** arr, const int rows, int& cols)
{
	cols++;
	T** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = cols - 1; j < cols; j++)
		{
			buffer[i][j] = rand() / 100;
		}
	}
	delete[] arr;
	return buffer;
}
template<class T> T** push_col_front(T** arr, const int rows, int& cols)
{
	cols++;
	T** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	delete[] arr[i];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			buffer[i][j] = rand() / 100;
		}
	}
	delete[] arr;
	return buffer;
}