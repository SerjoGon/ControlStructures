#include"Conctants.h"
#include"Fillrand.h"
#include"stdafx.h"
void Fillrand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void Fillrand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)rand() / maxRand;
	}
}
void Fillrand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void Fillrand(double arr[ROW][COL], const int ROW, const int COL, int minRand, int maxRand)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = (double)rand() / maxRand;
		}
	}
}
void Fillrand(char arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % (120 - 50) + 50;
		}
	}
}
