#pragma once
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
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
bool operator==(const Fraction& left, const Fraction& right);
ostream& operator<<(ostream& os, const Fraction& obj);
istream& operator >> (istream& is, Fraction& obj);


 /*bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);*/


class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				Constructors:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);

	Fraction& operator++();
	Fraction operator++(int);

	//				Type-cast operators:
	explicit operator int()const;
	operator double()const;
	//				Methods:
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;

	void print()const;
	ostream& print(ostream& os)const;
	Fraction& reduce();
};
