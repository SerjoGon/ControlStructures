#include<iostream>
using namespace std;
#define tab "\t"

void Fillrand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Sort(int arr[], const int n);
int Sum(int arr[], const int n);
double AVG(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "RU");
	const int n = 5;
	int arr[n];
	Fillrand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(arr, n) << endl;

	const int m = 8;
	int brr[m];
	Fillrand(brr, m, 20, 50);
	Print(brr, m);
	Sort(brr, m);
	Print(brr, m);

}
void Fillrand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
int Sum(int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double AVG(int arr[], const int n)
{
	return (double)Sum(arr,n)/n;
}
