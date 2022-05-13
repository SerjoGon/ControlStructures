#include<iostream>
using namespace std;
using std::cout;
using std::cin;
//using std::endl;
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
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
	// methods
	double distance(Point other)
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
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRUCT_POINT
//#define DISTANCE

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
	cout << "Расстояние от А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между А и точкой В: " << distance(A, B)<< endl;
	cout << "Расстояние между В и точкой А: " << distance(B, A) << endl;
#endif // DISTANCE
	int a;
	Point A;
	A.print();
	//cout << A.get_x() << '\t' << A.get_y() << endl;
}