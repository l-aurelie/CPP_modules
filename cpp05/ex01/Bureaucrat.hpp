#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name = "default", int grade = MIN_GRADE);
	Bureaucrat(Bureaucrat &src);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	class gradeTooHighException: public std::exception
	{	
	public:
		const char *what(void) const throw();
	};
	class gradeTooLowException: public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	void signForm(Form &form) const;


private:
	const std::string _name;
	int _grade;

	Bureaucrat &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
