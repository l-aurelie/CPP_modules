
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	Intern intern;
	AForm* f1;
	AForm* f2;
	AForm* f_err;
	Bureaucrat bureaucrat("bureaucrat", MAX_GRADE);

	f1 = intern.makeForm("Robotomy_request", "Children");
	if (f1)
	{
		bureaucrat.signForm(*f1);
		bureaucrat.executeForm(*f1);
	}

	std::cout << std::endl;

	f2 = intern.makeForm("PresidentialPardon", "pauvre_manant");
	if (f2)
	{
		bureaucrat.signForm(*f2);
		bureaucrat.executeForm(*f2);
	}

	std::cout << std::endl;

	f_err = intern.makeForm("Unknown_form", "someone");
	if (f_err)
	{
		bureaucrat.signForm(*f_err);
		bureaucrat.executeForm(*f_err);
	}
	return 0;
}
