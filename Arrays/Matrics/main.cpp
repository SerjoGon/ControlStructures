#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n-----------------------------\n"

//#define ADDITION
void main()
{
	setlocale(LC_ALL, "");
	const int m = 3;
	const int n = 3;
	int A[m][n] = {};
	int B[m][n] = {};
	// Заполняем матрицы случайными числами:
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	// выводим матрицу А на экран 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << tab;
		}
		cout << endl;
	}
	// выводим матрицу В на экран 
	cout << delimeter << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << tab;
		}
		cout << endl;
	}
#ifdef ADDITION
	// сложение матриц
	int C[m][n] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	cout << delimeter << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << C[i][j] << tab;
		}
		cout << endl;
	}
#endif
	int C[m][n] = {};
	for (int i = 0; i < m; i++)
	{
		// i - нумерует строки и выбирате строку 
		// j - нумерует столбцы
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				// k - перебирает элементы выбранной строки матрицы А и выбранного столбца матрицы В
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	cout << delimeter << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << C[i][j] << tab;
		}
		cout << endl;
	}
}