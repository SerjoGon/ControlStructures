#include<iostream>
using namespace std;
int left_bound(int arr, int n, int x)
{
	int left = -1;
	int right = n;
	while (right - left > 1)
	{
		int middle = (left + right) / 2;
		if (arr[middle] < x)
		{
			left = middle;
		}
		else right = middle;
	}

	return 0;
}
 /*int find(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return 0;
}*/

void main()
{
	setlocale(LC_ALL, "Ru");
	const int n = 10;
	int x;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	cin >> x;
	//cout << "Индекс числа "<< x<< " в массиве:" << find(arr, n, x) << '\n';
	cout << "Индекс числа "<< x<< " в массиве:" << left_bound(arr, n, x) << '\n';
}