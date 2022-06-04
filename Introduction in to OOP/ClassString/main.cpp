#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//#define CONSTRUCTORS_CHECK
class String
{
	int size;// размер строки в байтах
	char* str;// Указатель на строку
public:
	// get_methods
	int get_Size() const { return size; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	//			Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Def_1A_Constructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "Constructor: \t" << this << endl;
	}
	String(const String& other)
	{
		// CopyConstructor must do DeepCopy (Побитовое копирование)
		//т.е., выделить новую память, и скопировать в нее содержимое другого обьекта
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstrucor:\t" << this << endl;
	}
	String(String&& other)
	{
		// MoveConstructor выполняет ShellowCopy (Поверхностное копирование)
		this->size = other.size;
		this->str = other.str;// копируем адрес памяти другого обьекта
		other.size = 0;
		other.str = nullptr; // зануляем адрес памяти в др обьекте что бы его не удалил деструктор
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size;i++)this->str[i] = other.str[i];
		cout << "CopyAssigment: \t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	 const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//			Methods:
	void Print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_Size()+right.get_Size() - 1);
	//левую строку копируем соответственно:
	for (int i = 0; i < left.get_Size(); i++)
	{
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	// Правую строку копируем со смещением вправо на размер левой строки
	for (int i = 0;i < right.get_Size();i++)
	{
		cat[i + left.get_Size() - 1] = right[i];
	}
	return cat;
}
std::ostream& operator<< (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	const int size = 256;
	char buffer[size] = {};
	is >> buffer;
	obj = buffer;
	return is;

}
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef CONSTRUCTORS_CHECK

	String str1;//Default constructor
	str1.Print();
	String str2(5);//explicit Single argument constructor
	str2.Print();
	String str3 = "Hello";
	str3.Print();
	str3 = str3;
	String str4 = str3;
	str4.Print();
	String str5;
	str5.Print();
	str5 = str4;// CopyAssigment
	str5.Print();
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2("World");
	//String str3 = str1 + str2; // moveconstructor
	String str3;
	str3 = str1 + str2;
	str3.Print();
}