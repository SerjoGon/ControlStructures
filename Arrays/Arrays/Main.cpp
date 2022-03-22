//Arrays
#include<iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 5; // кол-во элем массива
	int arr[n] = {};
	cout << "¬ведите элементы массива (" << n << "шт)";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	/*arr[0] = 111;
	arr[1] = 222;
	arr[2] = 123;
	arr[3] = 333;
	arr[4] = 999;*/
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	/*for (int i = n -1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}*/
	cout << endl;
}