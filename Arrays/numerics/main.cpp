#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Ru");
	int decimal = 0; // ���������� ����� �������� � ����������
	//int n = 0;
	const int SIZE = 32; // ����������� ��������� ����������� ���������� �����
	bool bin[SIZE] = {}; // ���� ������ ����� ������� ������� ��������� �����
	cout << "������� ���������� �����  :"; cin >> decimal;
	int i = 0;
	for ( ; decimal ; i++)
	{
		bin[i] = decimal % 2;
		decimal /= 2;
		//n++;
	}
	
	cout << "�������� ����� :";
	for (i--; i >= 0; i--)
	{
		cout << bin[i];
	}

}