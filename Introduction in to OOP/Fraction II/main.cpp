#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define FULL_COMPARISON
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
		//	явный
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	/*explicit Fraction(double decimal)
	{
		this->integer = 0;
		this->numerator = decimal *= 100;
		this->denominator = 100;
		cout << "1argConstructor:" << this << endl;
	}*/
	//explicit Fraction(double decimal)
	//{
	//	decimal += 1e-11;
	//	integer = decimal;
	//	decimal -= integer;
	//	numerator = 0;
	//	int i = 0;
	//	int digit = 0; // старший дробный разряд
	//	for (; decimal&& i <9;i++)
	//	{
	//		numerator *= 10;
	//		decimal *= 10;
	//		digit = decimal;
	//		numerator += digit;
	//		decimal -= digit;
	//	}
	//	denominator = pow(10, i);
	//	cout << "1argConstructor:" << this << endl;
	//}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "Constructor double" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "\nDestructor:\t" << this << endl;
	}

	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}


	//				Methods:
	Fraction& to_proper()
	{
		//TODO: переводит дробь в правильную (выделяет целую часть)
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//TODO: переводит дробь в неправильную (выделяет целую часть)
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}

	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
	ostream& print(ostream& os)const
	{
		if (integer) os << integer;
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer)os << ")";
		}
		if (integer == 0 && numerator == 0)os << 0;
		return os;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = denominator;
			more = numerator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;// greates common Divisor(наибольший общий делитель)
		if (GCD == 0) return *this;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	);*/

	return left.to_improper() * right.inverted();
}

#ifdef FULL_COMPARISON
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	//	!true == false
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
	//return !(left > right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
#endif // FULL_COMPARISON

bool operator==(const Fraction& left, const Fraction& right)
{
	return (double)left == (double)right;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;*/
	return obj.print(os);
}
istream& operator >> (istream& is, Fraction& obj)
{
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//cin >> buffer;
	cin.getline(buffer, SIZE);
	char delimeters[] = "()/ ";
	char* sz_numbers[3] = {};// массив строк, который будет хранить числа в строковом формате
	int i = 0;// loop iterator
	for (char* pch = strtok(buffer, delimeters);pch;pch = strtok(NULL, delimeters))
	{
		sz_numbers[i++] = pch;
	}
	obj = Fraction(); // обнуляем, сбрасываем обьект до значений по умолчанию
	switch (i)
	{
	case 1:obj.set_integer(atoi(sz_numbers[0]));
		//atoi() - ASCII string to integer(Преобразует строку в число)
		break;
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3:
		obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));
	}
	return is;
}
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