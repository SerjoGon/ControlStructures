#pragma once
#include"Student.h"

class Graduate :public Student
{
	std::string diploma;
	unsigned int pages;
	unsigned int release;

public:
	const std::string& get_diploma()const;
	unsigned int get_pages()const;
	unsigned int get_release()const;
	void set_diploma(const std::string& diploma);
	void set_pages(unsigned int pages);
	void set_release(unsigned int release);

	//					CONSTRUCTORS:
	Graduate
	(
		HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS
	);
	~Graduate();
	//					METHODS:
	void print()const;
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj);