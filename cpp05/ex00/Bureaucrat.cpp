#include "Bureaucrat.hpp"

const char *what() const throw();
const char *what() const throw();
	
Bureaucrat::Bureaucrat(const std::string & name = "default", int grade = MIN_GRADE)
Bureaucrat::Bureaucrat(Bureaucrat &src);
Bureaucrat::~Bureaucrat();

Bureaucrat &operator=(const Bureaucrat &rhs);

const std::string  &Bureaucrat::getName() const;
int Bureaucrat::getGrade() const;
void Bureaucrat::incGrade();
void Bureaucrat::decGrade();

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);
