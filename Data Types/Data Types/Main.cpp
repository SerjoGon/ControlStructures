#include<iostream>// ���������� ���������� � ��� ���
using namespace std; // ������ ��������� �� ������������ ���� std � ���������� iostream

//#define BOOLEAN
//#define INTEGRAL_TYPES
//#define FLOAT_DOUBLE
#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4


void main()
{
	setlocale(LC_ALL, "Russian");//�������� �������� �������� � �������
#if defined BOOLEAN
	cout << sizeof(1024) << endl;
	cout << true << endl;// endl ������� � ������ ����� ������ ��� �� ��� � /n
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
	cout << "�������������� ����� � �������� ������" << endl;
	cout << "������� ���� �����: \n";
	cin >> number;
	rub = int(number);
	kop = (number - rub) * 100;
	cout << rub << " ���.  " << kop << " ���.  \n";
#endif
#if defined TASK_2
	double notebook_price, price_of_pencil, number_of_notebook, number_of_pencil, total_price;
	cout << "���������� ��������� ������� �������� � ����������." << endl;
	cout << "������� �������� ������: " << endl;
	cout << "���� ��������(���.) - ";
	cin >> notebook_price; 
	cout<< endl;
	cout << "���������� �������� - ";
	cin >> number_of_notebook;
	cout << endl;
	cout << "���� ����������(���.) - ";
	cin >> price_of_pencil;
	cout << endl;
	cout << "���������� ���������� - ";
	cin >> number_of_pencil;
	cout << endl;
	total_price = (notebook_price * number_of_notebook) + (price_of_pencil * number_of_pencil);
	cout << "�������� ����" << total_price << "(���.)" << endl;
#endif
#ifdef TASK_3
	double price_1, price_2, number, result;
	cout << "���������� ��������� �������." << endl;
	cout << "������� ���� � ����������:" << endl;
	cout << "���� ��������(���.) - ";
	cin >> price_1;
	cout << endl;
	cout << "���� ������� ��� ��������(���.) - ";
	cin >> price_2;
	cout << endl;
	cout << "���������� ���������� - ";
	cin >> number;
	cout << endl;
	result = (price_1 + price_2) * number;
	cout << "���������(���.) - "<< result << endl;
#endif
#ifdef TASK_4
	double distance, price_of_fuel, consumption, result;
	cout << "���������� ��������� ������� �� ���� � �������." << endl;
	cout << "������� �������� ������:" << endl;
	cout << "������� ���������� �� ����(��) - ";
	cin >> distance;
	cout << endl;
	cout << "������� ������ ������� �� 100��:";
	cin >> consumption;
	cout << endl;
	cout << "������� ���� �������(���.) - ";
	cin >> price_of_fuel;
	cout << endl;
	result = ((distance * (consumption / 100)) * price_of_fuel) * 2;
	cout << "���������(���.) - " << result << endl;
#endif

}
