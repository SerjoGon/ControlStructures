//Loops
#include<iostream>
#include<conio.h>
using namespace std;
//#define WHILE
#define Escape 27 //Старый добрый шутер!!! Выполнил домашнее задание в классной работе

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef WHILE
	int i = 0;
	int n;
	cout << "";
	cin >> n;
	while(i<n)
	{
		cout << "Hello! \n";
		i++;
	}
#endif
#ifdef Escape 27
	char key;
	do
	{
		key = _getch();
		
		if (key == 'w'||'W')
			cout << "Шаг вперед!" << endl;
		else if (key == 's'||'S')
			cout << "Шаг назад!" << endl;
		else if (key == 'A'||'a')
			cout << "Шаг влево!" << endl;
		else if (key == 'D'||'d')
			cout << "Шаг вправо!" << endl;
		else if (key == 'q'||'Q')
			cout << "Поворот на лево!" << endl;
		else if (key == 'E'||'e')
			cout << "Поворот на право!" << endl;
		else if (key == 13)
			cout << "Выстрел!!!!!!!" << endl;
		else if (key == 'G'||'g')
			cout << "Бросаю гранату!!" << endl;
		else if (key == 'c'||'C')
			cout << "Пригнулся!" << endl;
		else if (key == 'f'||'F')
			cout << "Аптечка!" << endl;
		else if (key == 32)
			cout << "Прыжок!" << endl;
		else if (key == 'R'||'r')
			cout << "Перезаряжаю оружие!" << endl;
		
	}while (key != Escape);
	cout << " Выход из игры!" << endl;
#endif
}
