#include"Insert_all.h"
#include<iostream>
template<class T> T* Insert(T* arr, int& n, int num, int& index)
{
	T* buffer = arr;
	buffer = new int[++n]{};
	for (int i = n - 1; i >= index - 1;i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i <= index - 1;i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	buffer[index] = num;
	arr = buffer;
	return arr;
}
template<class T> T** InsertRow(T** arr, int& rows, int& cols, int& index)
{
	T** buffer = arr;
	buffer = new int* [++rows];
	/*for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
	}*/
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i < index) buffer[i][j] = arr[i][j];
			else if (i == index) buffer[i][j] = rand() % 22;
			else buffer[i][j] = arr[i - 1][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}
template<class T> T** insert_cols(T** arr, const int rows, int& cols, int& index)
{
	cols++;
	T** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < index)buffer[i][j] = arr[i][j];
			else if (j == index)buffer[i][j] = rand() / 100;
			else if (j > index)buffer[i][j] = arr[i][j - 1];
		}
			delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}