#include<iostream>
using std::cout;
using std::cin;
using std::endl;

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

	Fraction(int INT = 0, int num = 0, int den = 0)
	{
		this->INT = INT;
		this->num = num;
		this->den = den;
		cout << "Constructor: \t" << this << endl;
	}
	//Copy Constructor
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
	void print()const
	{
		if (this->INT == 0)cout << num << '/' << den << endl;
		else cout << INT << "(" << num << "/" << den << ")" << endl;
	}
};

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
	A.print();
	while (true)
	{
	cout << "Введите простую дробь для выполнения арифметических операций! ";cin >> INT >> num >> den;
		if (den == 0) cout << "\n Делить на 0 нельзя! Введите новую дробь!!! \n";
		else
			break;
	}
	Fraction B(INT, num, den);
	B.print();
	cout << "Проверка инкремента:" << endl;
	A++;
	A.print();
	B++;
	B.print();
}