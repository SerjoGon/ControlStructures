#include<iostream>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;

namespace Geometry
{
	//enum (Enumeration - ������������) - ��� ����� ������������� ��������.
// ������������ ��� �� �������� ����� ������.

	enum class Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};

	class Shape
	{
	protected:
		Color color;
	public:
		Color get_color()const { return color; }
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		// Methods
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "������� ������: " << get_area() << endl;
			cout << "��������� ������: " << get_perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const { return side; }
		void set_side(double side)
		{
			if (side <= 0)side = 10;
			this->side = side;
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const { return side * side; }
		double get_perimeter()const { return side * 4; }
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//��� ������������ ������ �������� ���� ������ ���� �������� � �� ���
			SetConsoleTextAttribute(hConsole, (WORD)get_color());
			for (int i = 0;i < side;i++)
			{
				for (int j = 0; j < side;j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, (WORD)Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "����� ������� ��������: " << get_side() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double side_a, side_b;
	public:
		double get_side_a() { return side_a; }
		double get_side_b() { return side_b; }
		void set_side_a(double side_a)
		{
			if (side_a <= 0)side_a = 20;
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			if (side_b <= 0)side_b = 10;
			this->side_b = side_b;
		}
		Rectangle(double side_a, double side_b, Color color) :Shape(color)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}
		double get_area()const
		{
			return side_a * side_b;
		}
		double get_perimeter()const
		{
			return (side_a + side_b) * 2;
		}
		void draw()const
		{
			//1) �������� ���� �������:
			//HWND - Handler to Window(���������� ���� �������)
			HWND hwnd = GetConsoleWindow();
			//HWND hwnd = GetDesktopWindow();
			//2)��� ���� ����� ��������, ����� ������� �������� ����������:
			HDC hdc = GetDC(hwnd);// HDC - Handler to Device Context
			//����� ������, hdc - ��� �� �� ��� ����� ��������

			//3) �������� ����������� �������� �� ����� �������� 
			HPEN hPen = CreatePen(PS_SOLID, 10, (WORD)color);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			//4)������� �������� �� ���������� ��� ��� ����� ������� 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5) ������ �������������
			::Rectangle(hdc, 300, 100, 500, 200);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "������� �:" << side_a << endl;
			cout << "������� �:" << side_b << endl;
			Shape::info();
		}
	};
}

int main()
{
	setlocale(LC_ALL, "Ru");
	//Shape shape(Color::console_blue);
	Geometry::Square square(5, Geometry::Color::console_red);
	/*cout << "����� ������� ��������: " << square.get_side() << endl;
	cout << "������� ��������: " << square.get_area() << endl;
	cout << "��������� ��������: " << square.get_perimeter() << endl;*/
	square.info();
	Geometry::Rectangle rect(50, 30, Geometry::Color::blue);
	rect.info();
	//������ ������� 
	return 0;
}