//Arrays
#include<iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 0;
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

	for (int i = 0; i < n; i++) a += arr[i];
	cout << "����� ��������� �������:" << a << endl;
	b = a / n;
	cout << "������� �������������� ��������� �������:" << b << endl;

	cout << "��������� ��������� �������:" << endl;
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