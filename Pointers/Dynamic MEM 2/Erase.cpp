#include"Erase_all.h"
template<class T> T* Erase(T* arr, int& n, int& index)
{
	T* buffer = new int[--n]{};
	for (int i = 0; i < n;i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
template<class T> T** erase_row(T** arr, int& rows, int& cols, int& index)
{
	delete[] arr[index];
	T** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i < index) buffer[i][j] = arr[i][j];
			else buffer[i][j] = arr[i + 1][j];
		}
			delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}

template<class T> T** erase_cols(T** arr, const int rows, int& cols, int& index)
{
	T** buffer = arr;
	buffer = new int* [rows];
	cols--;
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < index)buffer[i][j] = arr[i][j];
			else if (j >= index)buffer[i][j] = arr[i][j + 1];
		}
			delete[] arr[i];
	}
	delete[] arr;
	return buffer;
}