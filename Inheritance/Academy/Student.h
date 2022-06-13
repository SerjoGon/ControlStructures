#pragma once
#include"Defines.h"
#include"Human.h"

class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const;
	const std::string& get_group()const;
	unsigned int get_year()const;
	double get_rating()const;
	double get_attendance()const;
	void set_specialty(const std::string& speciality);
	void set_group(const std::string& group);
	void set_year(unsigned int year);
	void set_rating(double rating);
	void set_attendance(double attendance);
	//					CONSTRUCTORS:
	Student
	(
		HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS
	);
	~Student();
	//					METHODS:
	void print()const;
};

std::ostream& operator<<(std::ostream& os, const Student& obj);