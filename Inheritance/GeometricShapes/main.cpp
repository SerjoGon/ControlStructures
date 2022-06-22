#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Shape
{
protected:
	int height = 0, widht = 0;
public:
	int get_height()const { return height; }
	int get_widht()const { return widht; }
	void set_height(int height) { this->height = height; }
	void set_widht(int widht) { this->widht = widht; }
	
	virtual int square() = 0;
	void print_area()
	{
		cout << this->square() << endl;
	}
};

class Rectangle : public Shape
{
public:
	int square(void)
	{
		return (height * widht);
	}
};
//std::ostream& operator<<(std::ostream& os, Rectangle obj)
//{
//	return obj.print(os);
//}

class Triangle: public Shape
{
public:
	int square(void)
	{
		return (height * widht / 2);
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	
	Rectangle rect;
	Triangle trgl;
	Shape* shape1 = &rect;
	Shape* shape2 = &trgl;

	shape1->set_height(4);shape1->set_widht(5);
	shape2->set_height(3);shape2->set_widht(6);
	shape1->print_area();
	shape2->print_area();
	return 0;
}