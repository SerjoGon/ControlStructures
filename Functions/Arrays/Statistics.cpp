#include"Statistics.h"
#include"stdafx.h"

int Sum(int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Sum(double arr[], const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)sum += arr[i];
	return sum;
}
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)sum += arr[i][j];
	}
	return sum;
}
double Sum(double arr[ROW][COL], const int ROW, const int COL)
{
	double sum = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)sum += arr[i][j];
	}
	return sum;
}

double AVG(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

double AVG(double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double AVG(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}
double AVG(double arr[ROW][COL], const int ROW, const int COL)
{
	return Sum(arr, ROW, COL) / (ROW * COL);
}

int MIN(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
double MIN(double arr[], const int n)
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
double MIN(double arr[ROW][COL], const int ROW, const int COL)
{
	double min = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL;j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
		}
	}
	return min;
}
int MIN(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS;j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
		}
	}
	return min;
}

int MAX(int arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
double MAX(double arr[], const int n)
{
	double max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int MAX(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	return max;
}
double MAX(double arr[ROW][COL], const int ROW, const int COL)
{
	double max = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	return max;
}

