#include<iostream>
using namespace std;

/* Функция для решения головоломки Башня Ханой
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
		cout << "Переношу диск 1 со столба " << i << " на столбец " << k << "\n";
	} 
	else
	{
		int tmp = 6 - i - k;
		hanoi(i, tmp, n - 1);
		cout << "Переношу диск " << n << " со столба " << i << " на столбец " << k << "\n";
		hanoi(tmp, k, n - 1);
	}
}