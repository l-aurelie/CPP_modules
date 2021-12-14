
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardon", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	setIsSigned(src.getIsSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

/*******************************************************/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm  &rhs)
{
	(void)rhs;
	return (*this);
}


/*******************************************************/

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
