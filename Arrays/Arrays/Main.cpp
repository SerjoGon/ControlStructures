//Arrays
#include<iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	double sum = 0, average = 0;
	const int n = 10; // кол-во элем массива
	int arr[n] = {};
	int minRand = 0;
	int maxRand = 0;
	cout << "¬ведите минимальное возможное случайное число:"; cin >> minRand;
	cout << "¬ведите максимально возможное случайное число:"; cin >> maxRand;
	int result = maxRand - minRand;
	//cout << "¬ведите элементы массива (" << n << "шт)";
	for (int i = 0; i < n; i++)
	{
		//cin >> arr[i];
		arr[i] = rand()%(maxRand - minRand) + minRand;
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

	for (int i = 0; i < n; i++) sum += arr[i];
	cout << "—умма элементов массива:" << sum << endl;
	average = sum / n;
	cout << "—реднее арифметическое элементов массива:" << average << endl;

	cout << "—равнение элементов массива:" << endl;
	int min, max;
	min = max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	cout << "Mininal value  " << min << endl;
	cout << "Maximal value  " << max << endl;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i]==arr[j])
			cout << arr[i] << " \t" << arr[j] << "\t";
		}
		cout << endl;
	}*/
}