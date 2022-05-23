#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//#define CHECK
class Fraction
{
	int INT; //integer целое число 
	int num;// numerator - числитель 
	int den;//denominator - делитель(знаменатель) из переводчика гугл
public:
	int get_INT()const
	{
		return INT;
	}
	int get_num()const
	{
		return num;
	}
	int get_den()const
	{
		return den;
	}
	void set_INT(int INT)
	{
		this->INT = INT;
	}
	void set_num(int num)
	{
		this->num = num;
	}
	void set_den(int den)
	{
		if (den == 0)den = 1;
		this->den = den;
	}
	//			Constructors:
	Fraction()
	{
		this->INT = 0;
		this->num = 0;
		this->den = 0;
		cout << "DEFConstructor: \t" << this << endl;
	}
	Fraction(int INT)
	{
		this->INT = INT;
		this->num = 0;
		this->den = 1;
		cout << "OneArgConstructor: \t" << this << endl;
	}
	Fraction(int num, int den)
	{

		this->INT = 0;
		this->num = num;
		this->set_den(den);
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int INT, int num , int den )
	{
		this->INT = INT;
		this->num = num;
		this->den = den;
		cout << "Constructor: \t" << this << endl;
	}
	//Copy Constructor:
	Fraction(const Fraction& other)
	{
		this->INT = other.INT;
		this->num = other.num;
		this->den = other.den;
		cout << "CopyConstructor: " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}
	// Operators:
	Fraction& operator++()
	{
		INT++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		INT++;
		return old;
	}
	Fraction& operator--()
	{
		INT--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		INT--;
		return old;
	}
	Fraction& operator=(const Fraction& other)
	{

		this->INT = other.INT;
		this->num = other.num;
		this->den = other.den;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	/*Fraction& operator-=(Fraction other)
	{
		int INT = other.INT;
		int num = other.num;
		int den = other.den;
		this->num = multiplier(this->den, den,this->den);
		this->den = multiplier(this->den, den,this->den);
		num = multiplier(this->den, den,den);
		den = multiplier(this->den, den,den);
		this->INT -= other.INT;
		this->num -= num;
		this->den = den;
		return *this;

	}*/
	// Methods

	void to_proper()// переводит в правильную дробь(выделяет целую часть )
	{
		INT += num / den;
		num %= den;
	}
	void to_improper()// переводит в неправильную дробь(убирает целую часть )
	{
		num += INT * den;
		INT = 0;
	}
	void print()const
	{
		/*if (INT) cout << INT;
		if (num)
		{
			if (INT)cout << "(";
			cout << num << "/" << den;
			if (INT)cout << ")";
		}
		if (INT == 0)cout << num << "/" << den << endl;*/
		if (this->INT == 0)cout << num << '/' << den << endl;
		else cout << INT << "(" << num << "/" << den << ")" << endl;
	}
};
//Greates common divisor - НОД - наибольший общий делитель (из переводчика гугл)
int GCD(int l_den, int r_den)
{
	if (l_den % r_den == 0) return r_den;
	if (r_den % l_den == 0) return l_den;
	if (l_den > r_den) 
		return GCD(l_den % r_den, r_den);
	return GCD(l_den, r_den % l_den);
}
// least common multiplier - НОК - наименьший общий множитель
int LCM(int l_den, int r_den)
{
	return (l_den * r_den) / GCD(l_den, r_den);
}
//Функция выделения множителя дроби
int multiplier(int l_den, int r_den, int den)
{
	return LCM(l_den, r_den) / den;
}

Fraction operator+(Fraction& left, Fraction& right)
{
	Fraction result;
	Fraction fract_1;
	Fraction fract_2;
	int l_den = left.get_den();
	int r_den = right.get_den();
	fract_1.set_num(left.get_num() * multiplier(l_den, r_den, l_den));
	fract_1.set_den(left.get_den() * multiplier(l_den, r_den, l_den));
	fract_2.set_num(left.get_num() * multiplier(l_den, r_den, r_den));
	fract_2.set_den(left.get_den() * multiplier(l_den, r_den, r_den));
	result.set_INT(left.get_INT() + right.get_INT());
	result.set_num(fract_1.get_num() + fract_2.get_num());
	result.set_den(fract_1.get_den());
	return result;
}
Fraction operator-(Fraction& left, Fraction& right)
{
	Fraction result;
	Fraction fract_1;
	Fraction fract_2;
	int l_den = left.get_den();
	int r_den = right.get_den();
	fract_1.set_num(left.get_num() * multiplier(l_den, r_den, l_den));
	fract_1.set_den(left.get_den() * multiplier(l_den, r_den, l_den));
	fract_2.set_num(left.get_num() * multiplier(l_den, r_den, r_den));
	fract_2.set_den(left.get_den() * multiplier(l_den, r_den, r_den));
	result.set_INT(left.get_INT() - right.get_INT());
	result.set_num(fract_1.get_num() - fract_2.get_num());
	result.set_den(fract_1.get_den());
	return result;
}
Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_num(left.get_num() * right.get_num());
	result.set_den(left.get_den() * right.get_den());*/
	/*Fraction result
	(
		left.get_num() * right.get_num(),
		left.get_den() * right.get_den()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_num() * right.get_num(),
		left.get_den() * right.get_den()
	);
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_num() * right.get_den(),
		left.get_den() * right.get_num()
	);
}

void main()
{
	setlocale(LC_ALL, "RU");
	/*while (true)
	{
		cout << "Введите простую дробь! ";cin >> INT >> num >> den;
		if (den == 0) cout << "\n Делить на 0 нельзя! Введите новую дробь!!! \n";
		else
			break;
	}
	Fraction A(INT, num, den);
	while (true)
	{
	cout << "Введите простую дробь для выполнения арифметических операций! ";cin >> INT >> num >> den;
		if (den == 0) cout << "\n Делить на 0 нельзя! Введите новую дробь!!! \n";
		else
			break;
	}
	Fraction B(INT, num, den);*/
	Fraction A(1,2,3);
	Fraction B(2,3,4);
	A.to_improper();
	B.to_improper();
	A.print();
	B.print();
	Fraction C = A * B;
	C.print();
#ifdef CHECK
		cout << "Проверка инкремента:" << endl;
	A++;
	A.print();
	B++;
	B.print();
	Fraction E = B;
	E.print();
#endif // CHECK
	Fraction D = C / A;
	D.print();
	Fraction M = C + D;
	M.print();

}