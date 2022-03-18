#include<iostream>
#include<conio.h>
using namespace std;
//#define ROMBUS
//#define TERN
//#define TERN_2
//#define ASCII_TEST
//#define CHESS_BOARD
#define CHESS_WORK
void main()
{
	//setlocale(LC_ALL, "");
	int n;
	cout << "input number: ";cin >> n;
#ifdef ROMBUS
	cout << "Input number :"; cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = i; j < n; j++)cout << " ";cout << "/";
		for (int j = 0; j < i * 2;j++)cout << " ";cout << "\\";
		cout << endl;
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j <= i;j++)cout << " ";cout << "\\";
		for (int j = 0; j < (n - 1 - i) * 2; j++)cout << " ";cout << "/";
		cout << endl;
	}
#endif
#ifdef TERN
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if(i%2==j%2)Другой вариант условия
			//cout << "* ";
			//if ((i+j) % 2 == 0)cout << "+ "; else cout<< "- ";
			//(i + j) % 2 == 0 ? cout << "+ " : cout << "- ";
			cout << ((i + j) % 2 == 0 ? "+ " : "- ");
		}
		cout << endl;
	}
#endif
#ifdef TERN_2
	for (int i = 0; i < n;i++)
		for (int j = 0; j <= n; j++)
			cout << (j == n ? "\n" : (i + j) % 2 == 0 ? "+ " : "- ");
#endif
#ifdef ASCII_TEST
	for (int i = 0; i <= 255; i++)
	{
		cout << "code = " << i << "\t" << "char = " << (char)i << endl;
	}
#endif
#ifdef CHESS_BOARD
	for (int i = 0; i <= n;i++)		cout << (i == 0 ? " " : i < n ? "___" : "\n");
	for (int i = 0; i < n;i++)
		for (int j = -1; j <= n; j++)
		{
			cout << (j == -1 ? "|  " : j == n ? "| \n" : (i + j) % 2 == 0 ? "+ " : "- ");
		}
	for (int i = 0; i <= n;i++)		cout << (i == 0 ? " " : i < n ? "___" : "\n");
#endif
#ifdef CHESS_WORK
	int a = 32, b = 254, c = 179, d = 95, e = 13; //a black block, b = white block,c= vert line, d line , e = enter
	for (int i = 0; i <= n;i++)
		cout << (i == 0 ? " " : i < n ? "__" : "\n");
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j <= n +1;j++)
		{
			/*cout << (j == 0 || j == n + 1 ? "|  " : "|");*/
			cout << (j == 0 ? (char)c : j == n+1 ? (char)c : (i + j) % 2 == 0 ? (char) a : (char)b);
		}
			cout << endl;
	}
	for (int i = 0; i <= n;i++)cout << (i == 0 ? " " : i < n ? "--" : "\n");

#endif

}