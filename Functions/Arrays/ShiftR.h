#pragma once
#include "Constants.h"
#include"Fillrand.h"

template<class T>
void ShiftR(T arr[], const int n, int shiftsR)
{
	for (int i = 0; i < shiftsR; i++)
	{
		T buffer = arr[0];
		for (int j = 0; j < n; j++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}