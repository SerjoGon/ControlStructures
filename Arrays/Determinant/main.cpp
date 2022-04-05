#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n-----------------------------\n"
void main()
{
	setlocale(LC_ALL, "");
	const int lin = 3;
	const int col = 3;
	int A[lin][col] = {};
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col; j++)
		{
			A[i][j] = rand() % 10;
		}
	}
	// вывод матрицы на экран
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col;j++)
		{
			cout << A[i][j] << tab;
		}
		cout << endl;
	}
	// клонирование матрицы для нахождения детерминанта по Саррюсу
	const int d = col + col;
	int B[lin][d] = {}; // пустая матрица для заополнения значениями матрицы А 
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	// заполнение второй части массива 
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d; j++)
		{
			B[i][j + col] = A[i][j]; // запись в элементы массива c третьего столбца 
		}
	}
	cout << delimeter << endl;

	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			cout << B[i][j] << "  ";
		}
		cout << endl;
	}

	cout << delimeter << endl;
	cout << "Главная диагональ 1:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j) cout << B[i][j] << tab;
		}
	}
	cout << "\nГлавная диагональ 2:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j - 1) cout << B[i][j] << tab;
		}
	}
	cout << "\nГлавная диагональ 3:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j - 2) cout << B[i][j] << tab;
		}
	}
	cout << "\nПобочная диагональ 1:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 2) cout << B[i][j] << tab;
		}
	}
	cout << "\nПобочная диагональ 2:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 3) cout << B[i][j] << tab;
		}
	}
	cout << "\nПобочная диагональ 3:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 4) cout << B[i][j] << tab;
		}
	}
}