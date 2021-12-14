#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
public:
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

	Form(std::string name = "default", const int grade_to_sign = MIN_GRADE, const int grade_to_exec = MIN_GRADE);//supp signed default
	Form(const Form &src);
	virtual ~Form(void);
	Form& operator=(const Form &rhs);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExec(void) const;

	void beSigned(const Bureaucrat &b);

private:
	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_exec;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
