
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, const int grade_to_sign, const int grade_to_exec): _name(name),_is_signed(false), _grade_to_sign(grade_to_sign),_grade_to_exec(grade_to_exec)
{
	if (_grade_to_exec > MIN_GRADE || _grade_to_sign > MIN_GRADE)
		throw Form::gradeTooLowException();
	else if (_grade_to_exec < MAX_GRADE || _grade_to_sign < MAX_GRADE)
		throw Form::gradeTooHighException();
}

Form::Form(Form const &src) : _name(src._name), _is_signed(src._is_signed),	_grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec)
{}

Form::~Form(void) {}

/*************************************************************/

Form &Form::operator=(const Form &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form " << rhs.getName() << ": grade to sign " << rhs.getGradeToSign()
	  << " | grade to exec " << rhs.getGradeToExec() << " | is signed "
	  << rhs.getIsSigned() << std::endl;
	return o;
}


/*************************************************************/

const std::string &Form::getName(void) const 
{
	return (_name);
}

bool Form::getIsSigned(void) const
{
	return (_is_signed);
}

int Form::getGradeToSign(void) const
{ return (_grade_to_sign); }

int Form::getGradeToExec(void) const
{ return (_grade_to_exec); }


/*************************************************************/

const char *Form::gradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char *Form::gradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}


/*==============================================================*/

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() < _grade_to_sign)
		throw Form::gradeTooLowException();
	else
		_is_signed = true;
}
