#include<iostream>// подключает библиотеку в наш код
using namespace std; // строка указывает на пространство имен std в библиотеке iostream

//#define BOOLEAN
//#define INTEGRAL_TYPES
//#define FLOAT_DOUBLE
#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4


void main()
{
	setlocale(LC_ALL, "Russian");//Позволят выводить кирилицу в консоль
#if defined BOOLEAN
	cout << sizeof(1024) << endl;
	cout << true << endl;// endl переход в начало новой строки так же как и /n
	cout << false << endl;
#endif
#if defined INTEGRAL_TYPES
	cout << "short: \n";
	cout << sizeof(short) << endl;
	cout << SHRT_MIN << "..." << SHRT_MAX << endl;
	cout << 0 << "..." << USHRT_MAX << endl;
#endif
#if defined FLOAT_DOUBLE
	cout << "float: \n";
	cout << sizeof(float) << endl;
	cout << FLT_MIN << "..." << FLT_MAX << endl;
	cout << endl;
	cout << "double: \n";
	cout << sizeof(double) << endl;
	cout << DBL_MIN << "..." << DBL_MAX << endl;
	cout << DBL_MIN << "..." << DBL_MAX << endl;
#endif
#if defined TASK_1
	double number, rub, kop;
	cout << "Преобразование числа в денежный формат" << endl;
	cout << "Введите Ваше число: \n";
	cin >> number;
	rub = int(number);
	kop = (number - rub) * 100;
	cout << rub << " руб.  " << kop << " коп.  \n";
#endif
#if defined TASK_2
	double notebook_price, price_of_pencil, number_of_notebook, number_of_pencil, total_price;
	cout << "Вычисление стоимости покупки тетрадей и карандашей." << endl;
	cout << "Введите исходные данные: " << endl;
	cout << "Цена тетрадей(руб.) - ";
	cin >> notebook_price; 
	cout<< endl;
	cout << "Количество тетрадей - ";
	cin >> number_of_notebook;
	cout << endl;
	cout << "Цена карандашей(руб.) - ";
	cin >> price_of_pencil;
	cout << endl;
	cout << "Количество карандашей - ";
	cin >> number_of_pencil;
	cout << endl;
	total_price = (notebook_price * number_of_notebook) + (price_of_pencil * number_of_pencil);
	cout << "Итоговая цена" << total_price << "(руб.)" << endl;
#endif
#ifdef TASK_3
	double price_1, price_2, number, result;
	cout << "Вычисление стоимости покупки." << endl;
	cout << "Введите цену и количество:" << endl;
	cout << "Цена тетрадей(руб.) - ";
	cin >> price_1;
	cout << endl;
	cout << "Цена обложек для тетрадей(руб.) - ";
	cin >> price_2;
	cout << endl;
	cout << "Количество комплектов - ";
	cin >> number;
	cout << endl;
	result = (price_1 + price_2) * number;
	cout << "Результат(руб.) - "<< result << endl;
#endif
#ifdef TASK_4
	double distance, price_of_fuel, consumption, result;
	cout << "Вычисление стоимости поездки на дачу и обратно." << endl;
	cout << "Введите исходные данные:" << endl;
	cout << "Введите расстояние до дачи(км) - ";
	cin >> distance;
	cout << endl;
	cout << "Введите расход топлива на 100км:";
	cin >> consumption;
	cout << endl;
	cout << "Введите цену топлива(руб.) - ";
	cin >> price_of_fuel;
	cout << endl;
	result = ((distance * (consumption / 100)) * price_of_fuel) * 2;
	cout << "Результат(руб.) - " << result << endl;
#endif

}
