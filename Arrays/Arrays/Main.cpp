//Arrays
#include<iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	double sum = 0, average = 0;
	const int n = 5; // ���-�� ���� �������
	int arr[n] = {};
	cout << "������� �������� ������� (" << n << "��)";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "�������� ������� �� �������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "�������� ������� � �������� �������:" << endl;
	for (int i = n - 1; i >= 0; i--)	cout << arr[i] << "\t";
	cout << endl;

	for (int i = 0; i < n; i++) sum += arr[i];
	cout << "����� ��������� �������:" << sum << endl;
	average = sum / n;
	cout << "������� �������������� ��������� �������:" << average << endl;

	cout << "��������� ��������� �������:" << endl;
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