#include <iostream>
#include <cstring>

using namespace std;

bool check_polindrom(string word)
{
	int len = word.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str;
	cout << "Введите слово или число: ";
	cin >> str;
	if (check_polindrom(str))
	{
		cout << "Это палиндром.";
	}
	else
	{
		cout << "Это не палиндром!";
	}
	return 0;

	
}