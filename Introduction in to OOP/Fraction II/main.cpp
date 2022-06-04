#include"Fraction.h"
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define OSTREAM_OPERATOR_CHECK
//#define TYPE_CONVERSIONS_BASE //Type casting
//#define CONVERSIONS_FROM_OTHER_TO_CLASS


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(19, 5);

	/*int a = 2;
	int b = 3;
	int c = a * b;
	Fraction C = A * B;
	C.print();
	(A / B).print();
	A.print();
	B.print();
	(A + B).print();*/

	A *= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (Fraction i(1, 2); i.get_integer() < 10; ++i)
	{
		i.print();
	}
#endif // INCREMENT_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	cout << (Fraction(1, 2) >= Fraction(3, 4)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef OSTREAM_OPERATOR_CHECK
	Fraction A(1, 2);
	cout << A << endl;
	A.print();
#endif // OSTREAM_OPERATOR_CHECK

#ifdef TYPE_CONVERSIONS_BASE
	/*
--------------------------------------
(type)value;	//C_like notation (C-подобная форма записи)
type(value);	//Functional notation (функциональная форма записи)
--------------------------------------
*/
//				r-value
//			l-value = r-value;

	cout << typeid(7 / .2).name() << endl;
	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Converion from more to less without data loss
	int d = 5.5;	//Conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASE

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
			/*
----------------------------------------------
1. From other to Class:
	Single argument constructor
	Assignment operator
2. From Class to other types;
----------------------------------------------
*/

//Fraction A = 5;	//Conversion from int to Fraction
//cout << A << endl;
	Fraction B;
	cout << "\n-------------------------------\n";
	B = (Fraction)(8);
	cout << "\n-------------------------------\n";
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER


	/*
	-----------------------------------------
		operator type()
		{
			conversion code;
		}
	-----------------------------------------
	*/

	/*Fraction A(2, 3, 4);
	int a = (int)A;
	cout << a << endl;

	double b = A;
	cout << b << endl;

	cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;*/
	Fraction C = (Fraction)2.787;
	C.to_proper();
	cout << C;
	/*Fraction C = 2.75;
	cout << C << endl;
	Fraction B(2, 2, 3);
	B.reduce();
	cout << B << endl;*/
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A  = 2.75;
	cout << "Введите простую дробь:"; cin >> A;
	cout << A << endl;
	cout << (double)A << endl;
	A(123, 55, 77);
	cout << A << endl;
}