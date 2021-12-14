
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_exec, const std::string &target): _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _target(target), _is_signed(false)
{
	if (_grade_to_exec > MIN_GRADE || _grade_to_sign > MIN_GRADE)
		throw AForm::gradeTooLowException();
	else if (_grade_to_exec < MAX_GRADE || _grade_to_sign < MAX_GRADE)
		throw AForm::gradeTooHighException();
}

AForm::AForm(const AForm &src):	_name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _target(src._target), _is_signed(src._is_signed)
{}

AForm::~AForm(void) {}


/****************************************************************/

AForm &AForm::operator=(const AForm &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
	o << "Form " << rhs.getName() << ": sign grade " << rhs.getGradeToSign()
	  << " | execute grade" << rhs.getGradeToExec() << " | signed ? "
	  << rhs.getIsSigned() << " | target " << rhs.getTarget() << std::endl;
	return o;
}


/****************************************************************/
const char *AForm::gradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char *AForm::gradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

const char *AForm::formUnsigned::what(void) const throw()
{
	return ("unsigned form can't be executed");
}

void AForm::setIsSigned(int status)
{
	_is_signed = status;
}
/****************************************************************/
const std::string &AForm::getName(void) const
{
	return (_name);
}

bool AForm::getIsSigned(void) const
{
	return (_is_signed);
}

int AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int AForm::getGradeToExec(void) const
{
	return (_grade_to_exec);
}

const std::string &AForm::getTarget(void) const
{
	return (_target);
}
/*==================================================================*/


void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _grade_to_sign)
		throw AForm::gradeTooLowException();
	else
		_is_signed = true;
}
