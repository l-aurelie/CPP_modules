#include <exception>
#include <iostream>
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat{
public:
	class gradeToHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	class gradeToLowException: public std::exception
	{
	public:	
		const char *what() const throw();
	};
	
	Bureaucrat(const std::string & name, int grade)
	Bureaucrat(Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	const std::string  &getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();

private:
	const std::string _name;
	int _grade; //1 a 150
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);
