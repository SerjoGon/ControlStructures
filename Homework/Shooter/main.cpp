#include<iostream>
#include<conio.h>
using namespace std;
#define IIIDSHOOTER
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef IIIDSHOOTER
	char key;
	do
	{
		key = _getch();

		if (key == 119)
			cout << "Шаг вперед!" << endl;
		else if (key == 115)
			cout << "Шаг назад!" << endl;
		else if (key == 97)
			cout << "Шаг влево!" << endl;
		else if (key == 100)
			cout << "Шаг вправо!" << endl;
		else if (key == 113)
			cout << "Поворот на лево!" << endl;
		else if (key == 101)
			cout << "Поворот на право!" << endl;
		else if (key == 13)
			cout << "Выстрел!!!!!!!" << endl;
		else if (key == 103)
			cout << "Бросаю гранату!!" << endl;
		else if (key == 99)
			cout << "Пригнулся!" << endl;
		else if (key == 102)
			cout << "Аптечка!" << endl;
		else if (key == 32)
			cout << "Прыжок!" << endl;
		else if (key == 114)
			cout << "Перезаряжаю оружие!" << endl;

	} while (key != 27);
	cout << " Выход из игры!" << endl;
#endif
}