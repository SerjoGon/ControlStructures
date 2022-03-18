#include<iostream>
using namespace std;
#define PALINDROME
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef PALINDROME
	int number;// число с клавиатуры
	int reverse = 0; //перевернет твое число
	cout << "Введите число:"; cin >> number;
	int copy = number; // сохранит копию исходного числа
	while (copy > 0)
	{
		reverse *= 10;// умножением сдвигаем разряд влево
		reverse += copy % 10;// += оператор прибавить 
		copy /= 10;// деление с присвоением убирает младший разряд
	}
	cout << number << endl;
	cout << reverse << endl;

	if (number == reverse)
	{
		cout << "Polindrome!!!" << endl;
	}
	else
	{
		cout << "Not Polindrome!!!" << endl;
	}
#endif

}