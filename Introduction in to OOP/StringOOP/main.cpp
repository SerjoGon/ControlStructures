#include<iostream>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;

class String;

class String
{
	int SIZE;
	char* str;
public:
	int get_SIZE()const
	{
		return SIZE;
	}
	char get_str()const
	{
		return *str;
	}
	int set_SIZE(int SIZE)
	{
		return this->SIZE = SIZE;
	}
	char  set_str(char str)
	{
		return *this->str = str;
	}
	//				Constructors:
	String()
	{
		this->SIZE = 256;
		this->str[SIZE] = {};
	}
	String(int SIZE, char* str)
	{
		this->SIZE = new int SIZE;
	}
};


void main()
{
	setlocale(LC_ALL, "RU");

}