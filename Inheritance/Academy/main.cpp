#include<iostream>
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
 	virtual std::ostream& print(std::ostream& os/* = std::cout*/)const
	{
		return os << last_name << " " << first_name << " " << age << " years\n";
		//printf("%s\t%s\t%u\n", last_name, first_name, age);
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);

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
		HUMAN_TAKES_PARAMETERS,	STUDENT_TAKE_PARAMETERS
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
	std::ostream& print(std::ostream& os )const
	{
		Human::print(os);
		return os << "Специализация - " << specialty << " Группа - " << group << " " << year << "-й курс " << rating << "% успеваемость " << attendance << "% посещаемость" << endl;
	}
};
#define TEACHER_TAKE_PARAMETERS const std::string& specialty, unsigned int experience
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
		HUMAN_TAKES_PARAMETERS,	TEACHER_TAKE_PARAMETERS
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
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << "Специализация - " << specialty << " Стаж преподавателя - " << experience << " лет" << endl;
	}
};
#define GRADUATE_TAKE_PARAMETERS const std::string& diploma, unsigned int pages, unsigned int release
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
		HUMAN_TAKES_PARAMETERS,	STUDENT_TAKE_PARAMETERS,GRADUATE_TAKE_PARAMETERS
	) :Student(HUMAN_GIVE_PARAMETERS,STUDENT_GIVE_PARAMETERS)
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
	std::ostream& print(std::ostream& os)const
	{
		//Student::print(os);
		return Student::print(os) << "Тема Дипломной работы - " << diploma << " страниц: " << pages << " Год выпуска:" << release << endl;
	}
};

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
		cout << *group[i] << endl;
		cout << "--------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		delete group[i];
	}
}