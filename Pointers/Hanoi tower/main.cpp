#include<iostream>
using namespace std;

/* ������� ��� ������� ����������� ����� �����
* i: start pin number
* k: finifh pin number
* n: number of disks
* 
*/

void hanoi(int i, int k, int n);

void main()
{
	setlocale(LC_ALL, "RU");
	hanoi(1, 2, 6);
}
void hanoi(int i, int k, int n)
{
	if (n == 1)
	{
		cout << "�������� ���� 1 �� ������ " << i << " �� ������� " << k << "\n";
	} 
	else
	{
		int tmp = 6 - i - k;
		hanoi(i, tmp, n - 1);
		cout << "�������� ���� " << n << " �� ������ " << i << " �� ������� " << k << "\n";
		hanoi(tmp, k, n - 1);
	}
}