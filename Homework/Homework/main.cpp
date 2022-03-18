#include<iostream>
using namespace std;

//#define TASK_1
//#define TASK_2
#define TASK_3
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TASK_1
	double money;
	cout << "¬ведите денежную сумму: "; cin >> money;
	cout << money << endl;
	int rub = money;// не €вное преобразование типов из djuble в int с потерей данных
	cout << rub << "руб. \t";
	int cop = (money - rub) * 100;
	cout << cop << "коп.\n";

#endif
#ifdef TASK_2
	double price_of_copybook, price_of_pencil;
	int number_of_copybooks, number_of_pencils;
	cout << "¬ведите стоимость тетради: ";cin >> price_of_copybook;
	cout << "¬ведите количество тетрадей: ";cin >> number_of_copybooks;
	cout << "¬ведите стоимость карандашей: ";cin >> price_of_pencil;
	cout << "¬ведите количество карандашей: ";cin >> number_of_pencils;
	double total_price = (price_of_copybook * number_of_copybooks) + (price_of_pencil * number_of_pencils);
	cout << "ќбща€ стоимость покупки: " << total_price << "руб.\n";
#endif
#ifdef TASK_3

#endif
}