//Operatrs
#include <iostream>
using namespace std;
//#define ARITMETICALS_OPERATORS
//#define ASSIGNED // l-value = r-value;
//#define INCREMENT_DECREMENT
//#define COMPOUND_ASSIGNMENTS // Составные присваивания 
#define COMPARISON_OPERATORS
void main()
{
	setlocale(LC_ALL, "Russian");
	//cout << "Hello operators" << endl;
#if defined ARITMETICALS_OPERATORS
	cout << 17 / 5 << endl; // Результат от деления
	cout << 28 % 16 << endl; // Остаток от деления
	cout << 5. / 17 << endl;
	cout << 5. / 17 << endl;

#endif
#if defined ASSIGNED
	//int a = 2; // в переменную "а" 
	//int b = 49;
	//int c = a + b;
	//cout << c << endl;
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
#endif
#ifdef INCREMENT_DECREMENT
	int i = 0;
	++i;
	i++;
	cout << i << endl;
	int j = 0;
	--j;
	j--;
	cout << j << endl;
#endif


#ifdef COMPOUND_ASSIGNMENTS
	int a = 2;
	int b = 3;
	//a = a + b;
	a += b;
	cout << a << endl;
#endif

#ifdef COMPARISON_OPERATORS
	//cout << (!true == false) << endl;
	
#endif
}