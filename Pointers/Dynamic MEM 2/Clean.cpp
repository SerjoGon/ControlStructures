#include"Clean.h"
template<class T> void Clear(T**& arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}