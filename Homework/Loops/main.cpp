//Loops
#include<iostream>
#include<conio.h>
using namespace std;
//#define WHILE
#define Escape 27 //������ ������ �����!!! �������� �������� ������� � �������� ������

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
			cout << "��� ������!" << endl;
		else if (key == 's'||'S')
			cout << "��� �����!" << endl;
		else if (key == 'A'||'a')
			cout << "��� �����!" << endl;
		else if (key == 'D'||'d')
			cout << "��� ������!" << endl;
		else if (key == 'q'||'Q')
			cout << "������� �� ����!" << endl;
		else if (key == 'E'||'e')
			cout << "������� �� �����!" << endl;
		else if (key == 13)
			cout << "�������!!!!!!!" << endl;
		else if (key == 'G'||'g')
			cout << "������ �������!!" << endl;
		else if (key == 'c'||'C')
			cout << "���������!" << endl;
		else if (key == 'f'||'F')
			cout << "�������!" << endl;
		else if (key == 32)
			cout << "������!" << endl;
		else if (key == 'R'||'r')
			cout << "����������� ������!" << endl;
		
	}while (key != Escape);
	cout << " ����� �� ����!" << endl;
#endif
}
