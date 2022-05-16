#include<iostream>
using namespace std;
using std::cout;
using std::cin;
//using std::endl;
#define delimetr "\n-----------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor: \t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t" << this << endl;
	}
	//Copy Constructor
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	// Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t"<< this << endl;
		return *this;
	}

	// methods
	double distance(const Point& other)
	{
		//this - точка от которой нужно считать расстояние до следующей
		// other - точка, до которой нужно найти расстояние 
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\t Y = " << y << endl;
	}
};
double distance(const Point& A,const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
#define ASSIGNMENT_CHECK_2
void main()
{
	setlocale(LC_ALL, "Ru");
#ifdef STRUCT_POINT


	//type name;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Объявление объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;

	cout << sizeof(Point) << endl;
	cout << typeid(A).name() << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE


	Point A;
	Point B;
	double x, y;
	cout << "Введите координаты:"; cin >> x >> y;
	A.set_x(x);
	A.set_y(y);
	B.set_x(7);
	B.set_y(8);
	cout << A.get_x() << '\t' << A.get_y() << endl;
	cout << delimetr << endl;
	cout << "Расстояние от А до точки В: " << A.distance(B) << endl;
	cout << delimetr << endl;
	cout << "Расстояние от B до точки A: " << B.distance(A) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между А и точкой В: " << distance(A, B)<< endl;
	cout << delimetr << endl;
	cout << "Расстояние между В и точкой А: " << distance(B, A) << endl;
	cout << delimetr << endl;
#endif // DISTANCE
#ifdef CONSTRUCTORS_CHECK


	int a(9990);
	cout << a << endl;
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(99);
	C.print();
	
	Point D(2, 3);
	D.print();

	Point E = D;//Copy Constructor
	E.print();

	Point F(C);//Copy Constructor
	F.print();
	//cout << A.get_x() << '\t' << A.get_y() << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK_1


	Point A(2, 3);
	Point B = A;// Copy Constructor Потомучто создается обьект
	Point C;
	C = B;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK_1
#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A(1,3), B(5,6), C(8,9);
	A.print();
	B.print();
	C.print();
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK_2

}