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
			cout << "��� ������!" << endl;
		else if (key == 115)
			cout << "��� �����!" << endl;
		else if (key == 97)
			cout << "��� �����!" << endl;
		else if (key == 100)
			cout << "��� ������!" << endl;
		else if (key == 113)
			cout << "������� �� ����!" << endl;
		else if (key == 101)
			cout << "������� �� �����!" << endl;
		else if (key == 13)
			cout << "�������!!!!!!!" << endl;
		else if (key == 103)
			cout << "������ �������!!" << endl;
		else if (key == 99)
			cout << "���������!" << endl;
		else if (key == 102)
			cout << "�������!" << endl;
		else if (key == 32)
			cout << "������!" << endl;
		else if (key == 114)
			cout << "����������� ������!" << endl;

	} while (key != 27);
	cout << " ����� �� ����!" << endl;
#endif
}