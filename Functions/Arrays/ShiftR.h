#pragma once
#include "Constants.h"
#include"Fillrand.h"

template<class T>
void ShiftR(T arr[], const int n, int shiftsR)
{
	for (int j = 0; j < shiftsR;j++)
	{
		T buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}