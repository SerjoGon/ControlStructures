#include"Defines.h"
#include"Human.h"

	const std::string& Human::get_last_name()const { return last_name; }
	const std::string& Human::get_first_name()const { return first_name; }
	unsigned int Human::get_age()const { return age; }
	void Human::set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void Human::set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void Human::set_age(unsigned int age) { this->age = age; }
	//					CONSTRUCTORS:
	Human::Human(HUMAN_TAKES_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		printf("HumanContructor:\t%p\n", this);
	}
	Human::~Human()
	{
		printf("HumanDestructor:\t%p\n", this);
	}

	//					METHODS:
	void Human::print()const
	{
		cout << last_name << " " << first_name << " " << age << " years\n";
		//printf("%s\t%s\t%u\n", last_name, first_name, age);
	}

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " years";
}