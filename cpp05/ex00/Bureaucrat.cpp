
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (_grade > MIN_GRADE)
		throw gradeTooLowException();
	if (_grade < MAX_GRADE)
		throw gradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &src): _name(src._name), _grade(src._grade)
{}

Bureaucrat::~Bureaucrat(void) {}

/**********************************************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "."<< std::endl;
	return o;
}


/**********************************************/

const std::string &Bureaucrat::getName(void) const 	
{ 
	return (this->_name);
}

int Bureaucrat::getGrade(void) const 
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade > MAX_GRADE + 1)
		_grade--;
	else
		throw Bureaucrat::gradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade < MIN_GRADE - 1)
		_grade++;
	else
		throw Bureaucrat::gradeTooLowException();
}

const char *Bureaucrat::gradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char *Bureaucrat::gradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}
