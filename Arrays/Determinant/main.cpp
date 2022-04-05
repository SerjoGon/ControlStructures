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
	// ����� ������� �� �����
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col;j++)
		{
			cout << A[i][j] << tab;
		}
		cout << endl;
	}
	// ������������ ������� ��� ���������� ������������ �� �������
	const int d = col + col;
	int B[lin][d] = {}; // ������ ������� ��� ����������� ���������� ������� � 
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	// ���������� ������ ����� ������� 
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d; j++)
		{
			B[i][j + col] = A[i][j]; // ������ � �������� ������� c �������� ������� 
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
	cout << "������� ��������� 1:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j) cout << B[i][j] << tab;
		}
	}
	cout << "\n������� ��������� 2:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j - 1) cout << B[i][j] << tab;
		}
	}
	cout << "\n������� ��������� 3:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i == j - 2) cout << B[i][j] << tab;
		}
	}
	cout << "\n�������� ��������� 1:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 2) cout << B[i][j] << tab;
		}
	}
	cout << "\n�������� ��������� 2:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 3) cout << B[i][j] << tab;
		}
	}
	cout << "\n�������� ��������� 3:" << endl;
	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < d;j++)
		{
			if (i + j == 4) cout << B[i][j] << tab;
		}
	}
}