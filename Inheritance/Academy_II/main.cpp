#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using std::cout;
using std::sin;
using std::endl;


#define HUM_TAK_PARAM const std::string& last_name, const std::string& first_name, unsigned int age
#define HUM_GIV_PARAM last_name,first_name,age

class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const { return last_name; }
	const std::string& get_first_name()const { return first_name; }
	const unsigned int get_age()const { return age; }
	void set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(unsigned int age) { this->age = age; }
	//				CONSTRUCTORS:
	Human(HUM_TAK_PARAM)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		printf("HConstrutor:\t%p\n", this);
	}
	virtual ~Human()	{printf("HDestructor:\t%p\n", this);}
	//				METHODS:
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(20); ofs << std::left;
		ofs << last_name + " " + first_name;
		ofs.width(4);  ofs << std::right;
		ofs << age << "\t";
		return ofs;
	}
	virtual std::ostream& print(std::ostream& os) const
	{
		os.width(20); os << std::left;
		os << last_name + " " + first_name;
		os.width(4); os << std::right;
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

std::ofstream& operator << (std::ofstream& ofs, const Human& obj) { return obj.print(ofs); }
std::ostream& operator << (std::ostream& os, const Human& obj) { return obj.print(os); }
std::ifstream& operator >> (std::ifstream& ifs, Human& obj) { return obj.scan(ifs); }

#define STUD_TAK_PARAM const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance
#define STUD_GIV_PARAM speciality, group, year, rating,attendance

class Student :public Human
{
protected:
	std::string speciality;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const { return speciality; }
	const std::string& get_group()const { return group; }
	const unsigned int get_year()const { return year; }
	const double get_rating()const { return rating; }
	const double get_attendence()const { return attendance; }
	void set_speciality(const std::string& speciality) { this->speciality = speciality; }
	void set_group(const std::string& group) { this->group = group; }
	void set_year(unsigned int year) { this->year = year; }
	void set_rating(double rating) { this->rating = rating; }
	void set_attendance(double attendance) { this->attendance = attendance; }
	//					CONSTRUCTORS:
	Student(HUM_TAK_PARAM, STUD_TAK_PARAM) :Human(HUM_GIV_PARAM)
	{
		set_speciality(speciality);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		printf("SConstructor:\t%p\n", this);
	}
	~Student() { printf("SDestructor:\t%p\n", this); }
	//					METHODS:

};
int main()
{
	setlocale(LC_ALL, "RU");

	return 0;
}