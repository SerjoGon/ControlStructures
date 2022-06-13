#include"Student.h"

	const std::string& Student::get_specialty()const { return specialty; }
	const std::string& Student::get_group()const { return group; }
	unsigned int Student::get_year()const { return year; }
	double Student::get_rating()const { return rating; }
	double Student::get_attendance()const { return attendance; }
	void Student::set_specialty(const std::string& speciality) { this->specialty = speciality; }
	void Student::set_group(const std::string& group) { this->group = group; }
	void Student::set_year(unsigned int year) { this->year = year; }
	void Student::set_rating(double rating) { this->rating = rating; }
	void Student::set_attendance(double attendance) { this->attendance = attendance; }
	//					CONSTRUCTORS:
	Student::Student
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
	Student::~Student()
	{
		printf("StudentDestructor:\t%p\n", this);
	}
	//					METHODS:
	void Student::print()const
	{
		Human::print();
		cout << "Специализация - " << specialty << " Группа - " << group << " " << year << "-й курс " << rating << "% успеваемость " << attendance << "% посещаемость" << endl;
	}

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
