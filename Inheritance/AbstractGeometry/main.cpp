#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include<wingdi.h>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;

namespace Geometry
{

#define IDM_ELLIPSE		1100
	//enum (Enumeration - перечисление) - это набор целочисленных констант.
// Перечесление так же является типом данных.
	const double p = 3.14;

	enum  class Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF00FF,
		yellow = 0x0000FFFF,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};
	enum Defaults
	{
		min_start_x = 100,
		max_start_x = 800,
		min_start_y = 100,
		max_start_y = 500,
		min_line_width = 5,
		max_line_width = 20,
		min_line_length = 10,
		max_line_length = 500,
	};
	class Shape
	{
	protected:
		int start_x;
		int start_y;
		unsigned int line_width;
		Color color;
	public:
		int get_start_x()const { return start_x; }
		int get_start_y()const { return start_y; }
		unsigned int get_line_width()const { return line_width; }
		Color get_color()const { return color; }
		void set_start_x(int start_x)
		{
			if (start_x < Defaults::min_start_x)this->start_x = Defaults::min_start_x;
			else if (start_x > Defaults::max_start_x)this->start_x = Defaults::max_start_x;
			else this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Defaults::min_start_y)this->start_y = Defaults::min_start_y;
			else if (start_y > Defaults::max_start_y)this->start_y = Defaults::max_start_y;
			else this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < Defaults::min_line_width)this->line_width = Defaults::min_line_width;
			else if (line_width > Defaults::max_line_width)this->line_width = Defaults::max_line_width;
			else this->line_width = line_width;
		}
		Shape(int start_x, int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}
		// Methods
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь Фигуры: " << get_area() << endl;
			cout << "Периметер Фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(int start_x, int start_y, unsigned int line_width, Color color) :
			Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const { return side; }
		void set_side(double side)
		{
			if (side < Defaults::min_line_length) this->side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length) this->side = Defaults::max_line_length;
			else this->side = side;
		}
		EquilateralTriangle(double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, 0x000000FF);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertices[] =
			{
				{start_x, start_y + side },
				{start_x + side,start_y + side},
				{start_x + side / 2,start_y + side - get_height()}
			};
			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};

	class IsoscelesTriangle :public Triangle
	{
		double base;
		double side;
	public:
		double get_base()const { return base; }
		double get_side()const { return side; }
		void set_base(double base)
		{
			if (base < Defaults::min_line_length)base = Defaults::min_line_length;
			else if (base > Defaults::max_line_length)base = Defaults::max_line_length;
			//if (base >= side * 2)base /= 2;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length) side = Defaults::max_line_length;
			if (side * 2 <= base)side = base;
			this->side = side;
		}
		IsoscelesTriangle& operator()(double base, double side)
		{
			if (base >= side * 2)base = side;
			set_base(base);
			set_side(side);
			return *this;
		}
		IsoscelesTriangle(double base, double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			operator()(base, side);
		}
		~IsoscelesTriangle() {}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, 0x0000FFFF);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertices[] =
			{
				{start_x, start_y + side },
				{start_x + base,start_y + side},
				{start_x + base / 2,start_y + side - get_height()}
			};
			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание треугольника: " << base << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class RectangularTriangle :public Triangle
	{
		double base;
		double side;
	public:
		double get_base()const { return base; }
		double get_side()const { return side; }
		void set_base(double base)
		{
			if (base < Defaults::min_line_length)this->base = Defaults::min_line_length;
			else if (base > Defaults::max_line_length) this->base = Defaults::max_line_length;
			else this->base = base;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)this->side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length) this->side = Defaults::max_line_length;
			else this->side = side;
		}
		RectangularTriangle(double base, double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			set_base(base);
			set_side(side);
		}
		~RectangularTriangle(){}
		double get_height()const
		{
			return side;
		}
		double get_area()const
		{
			return (base * side) / 2;
		}
		double get_perimeter()const
		{
			return sqrt(pow(base, 2) + pow(side, 2)) + base + side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, 0x00FF00FF);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertices[] =
			{
				{start_x, start_y },
				{start_x ,start_y + side},
				{start_x + base ,start_y }
			};
			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание треугольника(катет А): " << base << endl;
			cout << "Высота треугольника(Катет В): " << get_height() << endl;
			Shape::info();
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
		Square(double side, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const { return side * side; }
		double get_perimeter()const { return side * 4; }
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//для стандартного вывода текущего окна задаем цвет символов и их фон
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
			cout << "Длина стороны квадрата: " << get_side() << endl;
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
		Rectangle(double side_a, double side_b, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
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
			//1) Получаем окно консоли:
			//HWND - Handler to Window(Обработчик окна консоли)
			HWND hwnd = GetConsoleWindow();
			//HWND hwnd = GetDesktopWindow();
			//2)Для того чтобы рисовать, нужно создать контекст устройства:
			HDC hdc = GetDC(hwnd);// HDC - Handler to Device Context
			//Грубо говоря, hdc - это то на чем будем рисовать

			//3) Создадим инструменты которыми мы будем рисовать 
			HPEN hPen = CreatePen(PS_SOLID, line_width, (WORD)color);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			//4)Создать карандаш не достаточно его еще нужно выбрать 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5) Рисуем прямоугольник
			::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона А:" << side_a << endl;
			cout << "Сторона В:" << side_b << endl;
			Shape::info();
		}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const { return radius; }
		void set_radius(double radius)
		{
			if (radius >= 10 && radius <= 500) this->radius = radius;
			else if (radius < 10)this->radius = 10;
			else this->radius = 500;
		}
		Circle(double radius, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const { return (radius * radius) * M_PI; }
		double get_diameter()const { return radius * 2; }
		double get_perimeter()const { return get_diameter() * M_PI; }
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус окружности: " << radius << endl;
			cout << "Диаметр окружности: " << get_diameter() << endl;
			Shape::info();
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, (WORD)color);
			HBRUSH hBrush = CreateSolidBrush((WORD)color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
	};
}

int main()
{
	setlocale(LC_ALL, "Ru");
	//Shape shape(Color::console_blue);
	/*Geometry::Square square(5,50,10,5, Geometry::Color::red);
	square.info();*/
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметер квадрата: " << square.get_perimeter() << endl;*/
	/*Geometry::Rectangle rect(300, 200,355,220,20, Geometry::Color::red);
	rect.info();
	Geometry::Circle circle(140, 130, 250, 11, Geometry::Color::yellow);
	circle.info();
	Geometry::EquilateralTriangle qtri(200, 190, 300, 5, Geometry::Color::green);
	qtri.info();*/
	/*Geometry::IsoscelesTriangle itri(100, 150, 200, 220, 8, Geometry::Color::red);
	itri.info();*/
	Geometry::RectangularTriangle rtrg(120, 180, 200, 220, 8, Geometry::Color::yellow);
	rtrg.info();
	//Нижняя граница 
	return 0;
}