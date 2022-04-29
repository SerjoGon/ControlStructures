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
void main()
{
	setlocale(LC_ALL, "RU");

	int n; 
	int d;
	cout << "Input number:"; cin >> n;
	cout << "Input number for last elem of array:"; cin >> d;
	int* arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	arr[n++];
	//arr[n] += d;
	Fillrand(arr, n);
	Print(arr, n);
	delete[] arr;
}