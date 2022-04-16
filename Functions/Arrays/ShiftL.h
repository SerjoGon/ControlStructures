#pragma once
#include"Constants.h"
#include"Fillrand.h"

template<class T>
void ShiftL(T arr[], const int n, int shiftsL)
{
	for (int i = 0; i < shiftsL; i++)
	{
		T buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}