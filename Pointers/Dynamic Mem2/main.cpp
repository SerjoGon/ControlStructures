#include<iostream>
using namespace std;
void Print(int* arr, int n)
{
for (int i = 0; i < n; i++)
	{
		cout << arr[i]<< "  ";
	}
cout << endl;
}
void Fillrand(int* arr, int n)
{
for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (n * n);
	}
}
int* push_back(int* arr, int n, int num);

void main()
{
	setlocale(LC_ALL, "RU");

	int n; 
	int num;
	cout << "������� ���������� ��������� �������: "; cin >> n;
	int* arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "������� �������������� ������� �������. "; cin >> num;
	//n++;
	//Print(parr, n + 1);
	arr = push_back(arr, n,num);
	//n++;
	// ������� ��� ������ � ������ ������
	/*for (int i = 1; i < n ;i++)
	{
		parr[i] = arr[i -1];
	}
	parr[0] = num;*/

	Print(arr, n+1);
	delete[] arr;
	//delete[] parr;
}
int* push_back(int* arr, int n, int num)
{
	int* parr = arr;
	parr = new int[n + 1]{};
	for (int i = 0; i < n;i++)
	{
		parr[i] = arr[i];
	}
	delete[] arr;
	parr[n++] = num;
	arr = parr;
	return arr;
}