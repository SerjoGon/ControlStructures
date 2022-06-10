﻿#include<iostream>
#include<string>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;




#define HUMAN_TAKES_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name,age
class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const { return last_name; }
	const std::string& get_first_name()const { return first_name; }
	unsigned int get_age()const { return age; }
	void set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(unsigned int age) { this->age = age; }
	//					CONSTRUCTORS:
	Human(HUMAN_TAKES_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		printf("HumanContructor:\t%p\n", this);
	}
	virtual ~Human()
	{
		printf("HumanDestructor:\t%p\n", this);
	}

	//					METHODS:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
		//printf("%s\t%s\t%u\n", last_name, first_name, age);
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " years";
}

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty,group, year, rating, attendance
class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const { return specialty; }
	const std::string& get_group()const { return group; }
	unsigned int get_year()const { return year; }
	double get_rating()const { return rating; }
	double get_attendance()const { return attendance; }
	void set_specialty(const std::string& speciality) { this->specialty = speciality; }
	void set_group(const std::string& group) { this->group = group; }
	void set_year(unsigned int year) { this->year = year; }
	void set_rating(double rating) { this->rating = rating; }
	void set_attendance(double attendance) { this->attendance = attendance; }
	//					CONSTRUCTORS:
	Student
	(
		HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		printf("StudentConstructor:\t%p\n", this);
	}
	~Student()
	{
		printf("StudentDestructor:\t%p\n", this);
	}
	//					METHODS:
	void print()const
	{
		Human::print();
		cout << "Специализация - " << specialty << " Группа - " << group << " " << year << "-й курс " << rating << "% успеваемость " << attendance << "% посещаемость" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	//os << (Human&)obj;
	return os << (Human&)obj
		<< " " << obj.get_specialty()
		<< " " << obj.get_group()
		<< " " << obj.get_year()
		<< " " << obj.get_rating()
		<< " " << obj.get_attendance();
}

#define TEACHER_TAKE_PARAMETERS const std::string& specialty, unsigned int experience
class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty() const { return specialty; }
	unsigned int get_experience() const { return experience; }
	void set_specialty(const std::string& specialty) { this->specialty = specialty; }
	void set_experience(unsigned int experience) { this->experience = experience; }
	//					CONSTRUCTORS:
	Teacher
	(
		HUMAN_TAKES_PARAMETERS, TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experience(experience);
		printf("TeacherConstructor:\t%p\n", this);
	}
	~Teacher()
	{
		printf("TeacherDestructor:\t%p\n", this);
	}
	//					METHODS:
	void print()const
	{
		Human::print();
		cout << "Специализация - " << specialty << " Стаж преподавателя - " << experience << " лет" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os << (Human&)obj
		<< " " << obj.get_specialty()
		<< " " << obj.get_experience();
}

#define GRADUATE_TAKE_PARAMETERS const std::string& diploma, unsigned int pages, unsigned int release
class Graduate :public Student
{
	std::string diploma;
	unsigned int pages;
	unsigned int release;

public:
	const std::string& get_diploma()const { return diploma; }
	unsigned int get_pages()const { return pages; }
	unsigned int get_release()const { return release; }
	void set_diploma(const std::string& diploma) { this->diploma = diploma; }
	void set_pages(unsigned int pages) { this->pages = pages; }
	void set_release(unsigned int release) { this->release = release; }

	//					CONSTRUCTORS:
	Graduate
	(
		HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS
	) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_diploma(diploma);
		set_pages(pages);
		set_release(release);
		printf("GraduateConstructor:\t%p\n", this);
	}
	~Graduate()
	{
		printf("GraduateConstructor:\t%p\n", this);
	}
	//					METHODS:
	void print()const
	{
		Student::print();
		cout << "Тема Дипломной работы - " << diploma << " страниц: " << pages << " Год выпуска:" << release << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	return os << (Student&)obj
		<< " " << obj.get_diploma()
		<< " " << obj.get_pages()
		<< " " << obj.get_release();
}

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