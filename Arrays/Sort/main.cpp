#include<iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	/*int b = 3;
	int a = 2;*/
	/*cout << a << tab << b << endl;
	buffer = a;
	a = b;
	b = buffer;
	cout << a << tab << b << endl;
	*/
	const int n = 5;
	int arr[n];
	int minRand, maxRand;
	cout << "Введите минимальное случайное число: "; cin >> minRand;
	cout << "Введите максимальное случайное число: "; cin >> maxRand;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
	// вывод исходного массива
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n;j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	// вывод сортированного массива
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

}