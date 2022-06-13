#include"Teacher.h"

	const std::string& Teacher::get_specialty() const { return specialty; }
	unsigned int Teacher::get_experience() const { return experience; }
	void Teacher::set_specialty(const std::string& specialty) { this->specialty = specialty; }
	void Teacher::set_experience(unsigned int experience) { this->experience = experience; }
	//					CONSTRUCTORS:
	Teacher::Teacher
	(
		HUMAN_TAKES_PARAMETERS, TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experience(experience);
		printf("TeacherConstructor:\t%p\n", this);
	}
	Teacher::~Teacher()
	{
		printf("TeacherDestructor:\t%p\n", this);
	}
	//					METHODS:
	void Teacher::print()const
	{
		Human::print();
		cout << "Специализация - " << specialty << " Стаж преподавателя - " << experience << " лет" << endl;
	}

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os << (Human&)obj
		<< " " << obj.get_specialty()
		<< " " << obj.get_experience();
}