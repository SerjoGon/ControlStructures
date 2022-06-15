#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "ru");

	const int size = 256;
	char sz_filename[size] = {};
	cout << "Введите имя Файла: ";
	cin.getline(sz_filename, size);
	//strcmp()	- String compare (Сравнение строк)
	// int strcmp (char* str1, char* str2);
	// если функция вернула 0, значит строки идентичны
	// значение отличное от нуля - строки разные 
	// strlen - 
	if (strcmp(sz_filename + strlen(sz_filename)-4,".txt"))
	{
		strcat(sz_filename, ".txt");
		// функция strcat() выполняет конкатенацию строк(слияние строк)
		// т.е к содержимому первой строки добавляется содержимое второй строки.
	}
	std::ofstream fout; // создаем поток
	fout.open(sz_filename, std::ios_base::app);// открываем поток
	char sz_contents[size] = {};
	cout << "Введите содержимое Файла: ";
	cin.getline(sz_contents, size);
	fout << sz_contents;
	//fout << "\t\t\tHello World!\n";// выводим в поток
	fout.close();// закрываем поток
	// потоки обязательно нужно закрывать, это так же важно как удалять памят
	// сколько раз был вызван open(), столько же раз нужно вызвать метод close();
	char sz_command[size] = "notepad ";
	strcat(sz_command, sz_filename);
	system(sz_command);
	return 0;
}