#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//				Constructors:
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
//	€вный
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1argConstructor:" << this << endl;
}
/*Fraction:: Fraction(double decimal)
{
	this->integer = 0;
	this->numerator = decimal *= 100;
	this->denominator = 100;
	cout << "1argConstructor:" << this << endl;
}*/
//Fraction:: Fraction(double decimal)
//{
//	decimal += 1e-11;
//	integer = decimal;
//	decimal -= integer;
//	numerator = 0;
//	int i = 0;
//	int digit = 0; // старший дробный разр€д
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
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
	cout << "Constructor double" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:" << this << endl;
}
Fraction::~Fraction()
{
	cout << "\nDestructor:\t" << this << endl;
}

//				Operators:
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}

Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}

//				Type-cast operators:
Fraction:: operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}


//				Methods:
Fraction& Fraction::to_proper()
{
	//TODO: переводит дробь в правильную (выдел€ет целую часть)
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	//TODO: переводит дробь в неправильную (выдел€ет целую часть)
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}

void Fraction::print()const
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

ostream& Fraction::print(ostream& os)const
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
Fraction& Fraction::reduce()
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
	obj = Fraction(); // обнул€ем, сбрасываем обьект до значений по умолчанию
	switch (i)
	{
	case 1:obj.set_integer(atoi(sz_numbers[0]));
		//atoi() - ASCII string to integer(ѕреобразует строку в число)
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
