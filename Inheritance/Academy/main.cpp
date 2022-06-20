#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<iomanip>
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
	 virtual std::ofstream&  print(std::ofstream& ofs)const
	{
		 ofs.width(20);
		 ofs << std::left;
		 ofs << last_name + " " + first_name;
		 ofs.width(4);
		 ofs << std::right;
		 ofs << age<< "\t";
		return ofs;
	}

 	virtual std::ostream& print(std::ostream& os/* = std::cout*/)const
	{
		//return os << last_name << " " << first_name << " " << age << " years\n";
		os.width(20);
		os << std::left;
		os << last_name + " " + first_name;
		os.width(4);
		os << std::right;
		os << age << "\t";
		return os;
	}

	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		std::string buffer;
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ofstream& operator <<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);

}

std::ostream& operator <<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ifstream& operator >> (std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty,group, year, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const { return speciality; }
	const std::string& get_group()const { return group; }
	unsigned int get_year()const { return year; }
	double get_rating()const { return rating; }
	double get_attendance()const { return attendance; }
	void set_specialty(const std::string& speciality) { this->speciality = speciality; }
	void set_group(const std::string& group) { this->group = group; }
	void set_year(unsigned int year) { this->year = year; }
	void set_rating(double rating) { this->rating = rating; }
	void set_attendance(double attendance) { this->attendance = attendance; }
	//					CONSTRUCTORS:
	Student
	(HUMAN_TAKES_PARAMETERS,STUDENT_TAKE_PARAMETERS	) :Human(HUMAN_GIVE_PARAMETERS)
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

	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(20);
		ofs << std::left;
		ofs << speciality<< " ";
		ofs.width(8);
		ofs << group  << year;
		ofs.width(8);
		ofs << std::right;
		ofs << std::setprecision(2) << std::fixed;
		ofs << rating << "\t" << attendance<<"\t";
		return ofs;
	}

	std::ostream& print(std::ostream& os )const
	{
		Human::print(os);
		
		//return os << "Специализация - " << speciality << " Группа - " << group << " " << year << "-й курс " << rating << "% успеваемость " << attendance << "% посещаемость" << endl;
		os.width(15);
		os << std::left;
		os << speciality << " ";
		os.width(8);
		os << group << year;
		os.width(8);
		os << std::right;
		os << std::setprecision(2) << std::fixed;
		os << rating << "\t" << attendance << "\t";
		return os;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		ifs >> speciality;
		ifs >> group;
		ifs >> year;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}

};
#define TEACHER_TAKE_PARAMETERS const std::string& specialty, unsigned int experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_specialty() { return speciality; }
	unsigned int get_experience() { return experience; }
	void set_speciality(const std::string& specialty) { this->speciality = specialty; }
	void set_experience(unsigned int experience) { this->experience = experience; }
	//					CONSTRUCTORS:
	Teacher
	(
		HUMAN_TAKES_PARAMETERS,	TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(specialty);
		set_experience(experience);
		printf("TeacherConstructor:\t%p\n", this);
	}
	~Teacher()
	{
		printf("TeacherDestructor:\t%p\n", this);
	}
	//					METHODS:

	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(27);
		ofs << std::left;
		ofs << speciality;
		ofs.width(23);
		ofs << std::left;
		ofs << experience;
		return ofs;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		//return os << "Специализация - " << speciality << " Стаж преподавателя - " << experience << " лет" << endl;
		os.width(23);
		os << std::left;
		os << speciality << experience;
		return os;
	}

	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		//ifs >> speciality;
		const int n = 25;
		char speciality[n] = {};
		ifs.read(speciality, n);
		for (int i = n - 1; speciality[i] == ' '; i--)speciality[i] = 0;
		set_speciality(speciality);
		ifs >> experience;
		return ifs;
	}
};
#define GRADUATE_TAKE_PARAMETERS const std::string& diploma/*, unsigned int pages, unsigned int release*/
class Graduate :public Student
{
	std::string diploma;
	/*unsigned int pages;
	unsigned int release;*/

public:
	const std::string& get_diploma() { return diploma; }
	//unsigned int get_pages() { return pages; }
	//unsigned int get_release() { return release; }
	void set_diploma(const std::string& diploma) { this->diploma = diploma; }
	//void set_pages(unsigned int pages) { this->pages = pages; }
	//void set_release(unsigned int release) { this->release = release; }

	//					CONSTRUCTORS:
	Graduate
	(
		HUMAN_TAKES_PARAMETERS,	STUDENT_TAKE_PARAMETERS,GRADUATE_TAKE_PARAMETERS
	) :Student(HUMAN_GIVE_PARAMETERS,STUDENT_GIVE_PARAMETERS)
	{
		set_diploma(diploma);
		//set_pages(pages);
		//set_release(release);
		printf("GraduateConstructor:\t%p\n", this);
	}
	~Graduate()
	{
		printf("GraduateConstructor:\t%p\n", this);
	}
	//					METHODS:

	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs);
		ofs.width(10);
		ofs << std::left;
		ofs << " " << diploma/* <<"\t" << pages <<"\t" << release*/;
		return ofs;
	}

	std::ostream& print(std::ostream& os)const
	{
		Student::print(os);
		//return Student::print(os) << "Тема Дипломной работы - " << diploma << " страниц: " << pages << " Год выпуска:" << release << endl;
		os.width(10);
		os << " " << diploma /*<< "\t" << pages << "\t" << release*/;
		return os;
	}

	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, this->diploma);
		return ifs;
	}
};

Human* HumanFactory(const std::string& type)
{
	if (type.find("class Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0, 0);
	if (type.find("class Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, 0, "");
	if (type.find("class Teacher") != std::string::npos)return new Teacher("","",0,"",0);
}

Human** load(const std::string& filename, int& n)
{
	Human** group;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			n++;
		}
		n--;
		group = new Human * [n] {};
		fin.clear();
		fin.seekg(0);
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
		return nullptr;
	}
	fin.close();
	return group;

}

//#define INHERITANCE_CHECK
//#define WRITE_TO_FILE
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

#ifdef WRITE_TO_FILE



	Human* group[] =
	{
		new Teacher("Einstein","Albert",143,"Astronomy",90),
		new Teacher("Diaz","Ricardo",50,"Weapon Distruction",20),
		new Teacher("White","Walter",50,"Chemestry",25),
		new Student("Pinkman","Jessie",23,"Chemestry","WW_220",1,91.22,95),
		new Student("Vercetti","Tomas",30,"Thief","Vice",2,88,90),
		new Graduate("Schreder","Hank",40,"Criminalisics","WW_220",5,94.543,88,"Catch_Walter_White"),\
	};
	std::ofstream fout("Academy.txt");
		cout << "--------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << "--------------------------\n";
		//group[i]->fout();
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
		//fout << "--------------------------\n";
	}
	fout.close();

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);i++)
	{
		delete group[i];
	}
	system("notepad Academy.txt");
#endif // WRITE_TO_FILE
	int n = 0;
	Human** group = load("Academy.txt", n);

	for (int i = 0;  i < n;  i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
}