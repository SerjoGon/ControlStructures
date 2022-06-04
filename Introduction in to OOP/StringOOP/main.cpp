#include<iostream>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
class String;
String operator+(const String& left, const String& right);

class String
{
	int size;
	char* str;
public:
	//					GET_METHODS:
	int get_size()const { return size; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	//					CONSTRUCTORS:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		printf("DEFConstructor:\t%p\n", this);
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		printf("Constructor:\t%p\n", this);
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0;i < size;i++) this->str[i] = other.str[i];
		printf("CopyConstructor:\t%p\n", this);

	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		printf("MoveConstructor:\t%p\n", this);
	}
	~String()
	{
		delete[] this->str;
		printf("Destructor:\t%p\n", this);
	}
	//					OPERATORS:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		printf("CopyAssignment:\t%p\n", this);
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		printf("MoveAssignment:\t%p\n", this);
		return *this;
	}
	const char& operator[](int i)const { return str[i]; }
	char& operator[](int i) { return str[i]; }
	String operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//					METHODS:
	void print()const
	{
		printf("Size:\t%d\nStr:\t%s\n", size, str);
	}
};

std::istream& operator>>(std::istream& is, String& obj)
{
	const int size = 256;
	char buffer[size] = {};
	cin.getline(buffer, size);
	obj = buffer;
	return is;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) cat[i] = left[i];
	for (int i = 0; i < right.get_size();i++) cat[i + left.get_size() - 1] = right[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


void main()
{
	setlocale(LC_ALL, "RU");
	String word1("Hello");
	String word2("World!");
	word1 += word2;
	word1.print();
	String str1 = "Operator";
	String str2(" Check");
	str1 += str2;
	cout << str1 << endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String str3;
	cin >> str3;
	str3.print();
}