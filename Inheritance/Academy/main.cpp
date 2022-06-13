#include"Defines.h"
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

//#include"Teacher.cpp"
//#include"Student.cpp"
//#include"Graduate.cpp"
//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef INHERITANCE_CHECK

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human human("Goodman", "Saul", 45);
	human.print();
	Student Pinkman("Pinkman", "Jesse", 25, "Chemistry", "WW-220", 1, 90, 80);
	Pinkman.print();
	Teacher White("White", "Walter", 56, "Chemistry", 20);
	White.print();
	Graduate graduate("Pinkman", "Jesse", 28, "Chemistry", "WW-220", 5, 88, 70, "Synthesis Methamphetamine at home", 62, 2013);
	graduate.print();
#endif // INHERITANCE_CHECK

	Human* group[] =
	{
		new Student("Pinkman","Jessie",23,"Chemestry","WW_220",1,90,95),
		new Teacher("White","Walter",50,"Chemestry",25),
		new Graduate("Schreder","Hank",40,"Criminalisics","WW_220",5,90,88,"Catch_Walter_White",62,2013),
		new Student("Vercetti","Tomas",30,"Thief","Vice",2,88,90),
		new Teacher("Diaz","Ricardo",50,"Weapon Distruction",20),
		new Teacher("Einstein","Albert",143,"Astronomy",90)
	};
	cout << "--------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Teacher)) cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Student)) cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate)) cout << *dynamic_cast<Graduate*>(group[i]) << endl;

		cout << "--------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		delete group[i];
	}
}