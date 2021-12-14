
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	Bureaucrat chief("Chief", MAX_GRADE);
	std::cout << chief;
	Bureaucrat slave("Slave", MIN_GRADE);
	std::cout << slave;
	std::cout << std::endl << std::endl;


	// ShrubberyCreation================================
	ShrubberyCreationForm shrubbery_creation("BeautyGarden");
	std::cout << shrubbery_creation << std::endl;

	chief.executeForm(shrubbery_creation);//not signed
	chief.signForm(shrubbery_creation);
	chief.executeForm(shrubbery_creation);
	std::cout << std::endl;

	slave.signForm(shrubbery_creation);
	slave.executeForm(shrubbery_creation);
	std::cout << std::endl << std::endl;


	// RobotomyCreation================================
	RobotomyRequestForm robotomy_request("Children");
	std::cout << robotomy_request << std::endl;

	chief.executeForm(robotomy_request);//not signed
	chief.signForm(robotomy_request);
	chief.executeForm(robotomy_request);
	std::cout << std::endl;

	slave.signForm(robotomy_request);
	slave.executeForm(robotomy_request);
	std::cout << std::endl << std::endl;


	// PresidentialPardon================================
	PresidentialPardonForm presidential_pardon("pauvre_manant");
	std::cout << presidential_pardon << std::endl;

	chief.executeForm(presidential_pardon);//not signed 
	chief.signForm(presidential_pardon);
	chief.executeForm(presidential_pardon);
	std::cout << std::endl;

	slave.signForm(presidential_pardon);
	slave.executeForm(presidential_pardon);
	return (0);
}
