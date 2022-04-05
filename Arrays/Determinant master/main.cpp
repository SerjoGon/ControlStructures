#include<iostream>
using namespace std;
#define tab "\t"
#define line "\n________________________\n"
//#define DETERMIN
void main()
{
	setlocale(LC_ALL, "RU");

	const int n = 3;
	int A[n][n] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10;
			cout << A[i][j] << tab;
		}
		cout << endl;
	}
	cout << line << endl;
	// расширяем матрицу
#ifdef DETERMIN
	int B[n][n * 2] = {};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = B[i][j + n] = A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			cout << B[i][j] << tab;
		}
		cout << endl;
	}
	int main_diag = 0;
	for (int i = 0; i < n;i++)
	{
		int product = 1;
		for (int j = 0; j < n; j++)
		{
			product *= B[j][i + j];
		}
		main_diag += product;
	}
	cout << endl;
	cout << "Главная диагональ: " << main_diag << endl;
	// вычисляем побочную диагональ
	int aux_diag = 0; // aux = Auxilliary - вспомогательный
	for (int i = 0; i < n; i++)
	{
		int product = 1;
		for (int j = 0; j < n;j++)
		{
			product *= B[n - 1 - j][i + j];
		}
		aux_diag += product;
	}
	cout << "Вспомогательная диагональ: " << aux_diag << endl;
	cout << "Определитель матрицы: " << main_diag - aux_diag << endl;
#endif
}