// Calculator
#include<iostream>
#include<math.h>
using namespace std;
//#define CALCULATOR
#define TUTORIAL
int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CALCULATOR
	double a,n,b,d;
	cout << " " << endl;
	cin >> a; 
	cout << endl;
	cout << "" << endl;
	cin >> n;
	cout << endl;
	cout << "" << endl;
	cin >> b;
	cout << endl;
	d = a;
	cout << "" << endl;
#endif

#ifdef TUTORIAL
	cout << "Консольный калькулятор!!!" << endl << endl;
	cout << "Пожалуйства введите операцию для выполнения! В формате: a + b | a - b | a * b | a / b " << endl;
	return 0;
#endif



}