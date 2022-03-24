//Arrays
#include<iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 0;
	const int n = 5; // кол-во элем массива
	int arr[n] = {};
	cout << "¬ведите элементы массива (" << n << "шт)";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Ёлементы массива по пор€дку:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "Ёлементы массива в обратном пор€дке:" << endl;
	for (int i = n - 1; i >= 0; i--)	cout << arr[i] << "\t";
	cout << endl;

	for (int i = 0; i < n; i++) a += arr[i];
	cout << "—умма элементов массива:" << a << endl;
	b = a / n;
	cout << "—реднее арифметическое элементов массива:" << b << endl;

	cout << "—равнение элементов массива:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i]==arr[j])
			cout << arr[i] << " \t" << arr[j] << "\t";
		}
		cout << endl;
	}
}