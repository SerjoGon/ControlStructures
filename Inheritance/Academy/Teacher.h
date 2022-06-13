#pragma once
#include"Defines.h"
#include"Human.h"

class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty() const;
	unsigned int get_experience() const;
	void set_specialty(const std::string& specialty);
	void set_experience(unsigned int experience);
	//					CONSTRUCTORS:
	Teacher
	(
		HUMAN_TAKES_PARAMETERS, TEACHER_TAKE_PARAMETERS
	);
	~Teacher();
	//					METHODS:
	void print()const;
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj);