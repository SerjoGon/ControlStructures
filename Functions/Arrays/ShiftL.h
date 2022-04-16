#pragma once
#include"Constants.h"
#include"Fillrand.h"

template<class T>
void ShiftL(T arr[], const int n, int shiftsl)
{
	for (int i = 0; i < shiftsl; i++)
	{
		T buffer = arr[n - 1];
		for (int j = n - 1; j > 0; j--) arr[i] = arr[i - 1];
		arr[0] = buffer;
	}
}
