#include<iostream>
#include<string>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;

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
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		printf("HumanContructor:\t%p\n", this);
	}
	~Human()
	{
		printf("HumanDestructor:\t%p\n", this);
	}

	//					METHODS:
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
		//printf("%s\t%s\t%u\n", last_name, first_name, age);
	}
};
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
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
	) :Human(last_name, first_name, age)
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
class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty() { return specialty; }
	unsigned int get_experience() { return experience; }
	void set_specialty(const std::string& specialty) { this->specialty = specialty; }
	void set_experience(unsigned int experience) { this->experience = experience; }
	//					CONSTRUCTORS:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
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

class Graduate :public Student
{
	std::string diploma;
	unsigned int pages;
	unsigned int release;

public:
	const std::string& get_diploma() { return diploma; }
	unsigned int get_pages() { return pages; }
	unsigned int get_release() { return release; }
	void set_diploma(const std::string& diploma) { this->diploma = diploma; }
	void set_pages(unsigned int pages) { this->pages = pages; }
	void set_release(unsigned int release) { this->release = release; }

	//					CONSTRUCTORS:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance,
		const std::string& diploma, unsigned int pages,unsigned int release
	) :Student(last_name, first_name, age, specialty, group, year, rating, attendance)
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
		cout << "Тема Дипломной работы - " << diploma << " страниц: " << pages << " Год выпуска:"<< release << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human human("Goodman", "Saul", 45);
	human.print();
	Student Pinkman("Pinkman", "Jesse", 25, "Chemistry", "WW-220", 1, 90, 80);
	Pinkman.print();
	Teacher White("White", "Walter", 56, "Chemistry", 20);
	White.print();
	Graduate graduate("Pinkman", "Jesse", 28, "Chemistry", "WW-220", 5, 88, 70, "Synthesis Methamphetamine at home", 62,2013);
	graduate.print();
}