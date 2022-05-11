#include"Allocate.h"

template<class T> void Allocate(T**& arr, int& rows, int& cols)
{
arr = new int* [rows];
for (int i = 0; i < rows; i++)
{
	arr[i] = new int[cols] {};
}
}