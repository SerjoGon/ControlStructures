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
	Fraction& operator=(const Fraction& other)
	{

		this->INT = other.INT;
		this->num = other.num;
		this->den = other.den;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
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

void main()
{
	setlocale(LC_ALL, "RU");
	int INT = 0, num = 0, den = 0;
	while (true)
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
	Fraction B(INT, num, den);
	
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

}