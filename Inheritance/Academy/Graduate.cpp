#include"Graduate.h"
	const std::string& Graduate::get_diploma()const { return diploma; }
	unsigned int Graduate::get_pages()const { return pages; }
	unsigned int Graduate::get_release()const { return release; }
	void Graduate::set_diploma(const std::string& diploma) { this->diploma = diploma; }
	void Graduate::set_pages(unsigned int pages) { this->pages = pages; }
	void Graduate::set_release(unsigned int release) { this->release = release; }

	//					CONSTRUCTORS:
	Graduate::Graduate
	(
		HUMAN_TAKES_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS
	) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_diploma(diploma);
		set_pages(pages);
		set_release(release);
		printf("GraduateConstructor:\t%p\n", this);
	}
	Graduate::~Graduate()
	{
		printf("GraduateConstructor:\t%p\n", this);
	}
	//					METHODS:
	void Graduate::print()const
	{
		Student::print();
		cout << "Тема Дипломной работы - " << diploma << " страниц: " << pages << " Год выпуска:" << release << endl;
	}

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	return os << (Student&)obj
		<< " " << obj.get_diploma()
		<< " " << obj.get_pages()
		<< " " << obj.get_release();
}