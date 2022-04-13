#include"Shifts.h"
#include"stdafx.h"
void ShiftR(int arr[], const int n, int shiftsR)
{
	for (int j = 0; j < shiftsR;j++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}

void ShiftL(int arr[], const int n, int shiftsL)
{
	for (int i = 0; i < shiftsL; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}