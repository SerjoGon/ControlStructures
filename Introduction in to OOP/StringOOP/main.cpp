#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class string
{
	int size;
	char* str;
public:
	//					GET_METHODS:
	int get_size()const { return size; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	//					CONSTRUCTORS:
	explicit string(int size = 80)
	{
		this->size = size;
		this->str = new char[size]{};
		printf("DEFConstructor:\t%p\n", this);
	}
	string(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size]{};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		printf("Constructor:\t%p\n", this);
	}
	string(const string& other)
	{
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0;i < size;i++) this->str[i] = other.str[i];
		printf("CopyConstructor:\t%p\n", this);

	}
	~string()
	{
		delete[] this->str;
		printf("Destructor:\t%p\n", this);
	}
	//					OPERATORS:
	string& operator=(const string& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		printf("CopyAssigment:\t%p\n", this);
		return *this;
	}
	const char& operator[](int i)const { return str[i]; }
	char& operator[](int i){ return str[i]; }
	string operator+=(const string& other)
	{
		return *this = *this + other;
	}
	//					METHODS:
	void print()const
	{
		printf("Size:\t%d\nStr:\t%s\n", size, str);
	}
};

string operator+(const string& left, const string& right)
{
	string cat(left.get_size()+right.get_size()-1);
	for (int i = 0; i < left.get_size(); i++) cat[i] = left[i];
	for (int i = 0; i < right.get_size();i++) cat[i + left.get_size() - 1] = right[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const string& obj) 
{
	return os << obj.get_str(); 
}


void main()
{
	setlocale(LC_ALL, "RU");
	string word1("Hello");
	string word2("World!");
	word1 += word2;
	word1.print();
	string str1 = "Operator";
	string str2(" Check");
	/*str1 += str2;
	cout << str1 << endl;*/
}