
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class AForm
{
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
	class formUnsigned: public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	AForm(std::string name = "name", const int grade_to_sign = MIN_GRADE, const int grade_to_exec = MIN_GRADE, const std::string& target = "target");
	AForm(const AForm &src);
	virtual ~AForm(void);

	AForm &operator=(const AForm& rhs);

	const std::string &getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExec(void) const;
	void setIsSigned(int status);
	const std::string &getTarget(void) const;

	virtual void execute(Bureaucrat const &executor) const = 0;
	void beSigned(Bureaucrat const &b);

private:
	const std::string _name;
	const int _grade_to_sign;
	const int _grade_to_exec;
	const std::string _target;
	bool _is_signed;
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif
