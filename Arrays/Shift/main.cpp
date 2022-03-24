#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Ru");
	const int n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	// вывод исходного массива на экран
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	// Циклический сдвиг массива
	int number_of_shifts;
	cout << "введите количество сдвигов ";cin >> number_of_shifts;
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;

	}
	// вывод сдвинутого массива на экран

	for (int i = 0; i < n; i++)
	{

		cout << arr[i] << "\t";
	}
	cout << endl;


}