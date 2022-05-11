#include<iostream>
#include"Allocate.h"
#include"Clean.h"
#include"Fillrand.h"
#include"Print.h"
#include"Push_all.h"
#include"pop_all.h"
#include"Insert_all.h"
#include"Erase_all.h"
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define DYNAMIC_MEMORY_INT
#define DYNAMIC_MEMORY_DOUBLE
//#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef DYNAMIC_MEMORY_INT
	int n;
	int num;
	cout << "������� ���������� ��������� �������: "; cin >> n;
	int* arr;
	arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "������� �������������� ������� �������. "; cin >> num;
	arr = push_back(arr, n, num);
	Print(arr, n);
	cout << "������� �������������� ������� �������. "; cin >> num;
	arr = push_front(arr, n, num);
	Print(arr, n);
	int index;
	cout << "������� �������������� ������� �������. "; cin >> num;
	cout << "������� ������ ������� � ������� ���������� ���. ������� ����� �� ( 0 �� " << n << ")";cin >> index;
	arr = Insert(arr, n, num, index);
	Print(arr, n);
	cout << "������ ��������� ������� �������:";
	arr = PoP_back(arr, n);
	Print(arr, n);
	cout << "������ ������ ������� �������:";
	arr = PoP_front(arr, n);
	Print(arr, n);
	cout << "������� ������ ������� ������� ������ ������� ����� �� ( 0 �� " << n << " ) ";cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif
#ifdef DYNAMIC_MEMORY_DOUBLE
	int n;
	double num;
	cout << "������� ���������� ��������� �������: "; cin >> n;
	double* arr;
	arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "������� �������������� ������� �������. "; cin >> num;
	arr = push_back(arr, n, num);
	Print(arr, n);
	cout << "������� �������������� ������� �������. "; cin >> num;
	arr = push_front(arr, n, num);
	Print(arr, n);
	int index;
	cout << "������� �������������� ������� �������. "; cin >> num;
	cout << "������� ������ ������� � ������� ���������� ���. ������� ����� �� ( 0 �� " << n << ")";cin >> index;
	arr = Insert(arr, n, num, index);
	Print(arr, n);
	cout << "������ ��������� ������� �������:";
	arr = PoP_back(arr, n);
	Print(arr, n);
	cout << "������ ������ ������� �������:";
	arr = PoP_front(arr, n);
	Print(arr, n);
	cout << "������� ������ ������� ������� ������ ������� ����� �� ( 0 �� " << n << " ) ";cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int index;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� � ������: "; cin >> cols;cout << endl;
	int** arr;
	Allocate(arr, rows, cols);
	Fillrand(arr, rows, cols);
	cout << "������ ������� �� ����� ��� ������ ���������� ����������:" << endl;
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "���������� ������ � ����� �������:" << endl;
	arr = push_row_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "���������� ������ � ������ �������:" << endl;
	arr = push_row_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "������� ������ ���������� ������ ������� �� ( 0 �� " << rows << " )"; cin >> index;cout << endl;
	arr = InsertRow(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "�������� ��������� ������ �������:" << endl;
	arr = pop_row_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "�������� ������ ������ �������:" << endl;
	arr = pop_row_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "������� ������ ������ ��� �������� �� ������� �� ( 0 �� " << rows << " )"; cin >> index;cout << endl;
	arr = erase_row(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = push_col_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = push_col_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "������� ������ ����������� ������� �� ( 0 �� " << cols << " )"; cin >> index;cout << endl;
	arr = insert_cols(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = pop_cols_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = pop_cols_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "������� ������ ���������� ������� �� ( 0 �� " << cols - 1 << " )"; cin >> index;cout << endl;
	arr = erase_cols(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2
}
