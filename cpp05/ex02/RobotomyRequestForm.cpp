#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequest", 72, 45, target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	setIsSigned(src.getIsSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/*******************************************************/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return (*this);
}


/*******************************************************/

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();
	std::cout << "* some drilling noise *" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << getTarget() << "'s brain is safe!" << std::endl;
}
