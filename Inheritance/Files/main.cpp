#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "ru");
	std::ofstream fout; // создаем поток
	fout.open("File.txt", std::ios_base::app);// открываем поток
	fout << "\t\t\tHello World!\n";// выводим в поток
	fout.close();// закрываем поток
	// потоки обязательно нужно закрывать, это так же важно как удалять памят
	// сколько раз был вызван open(), столько же раз нужно вызвать метод close();
	system("notepad File.txt");
	return 0;
}