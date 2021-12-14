#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define NB_FORM 3

class Intern {
public:
	Intern(void);
	Intern(Intern const &src);
	virtual ~Intern(void);

	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &form_name, std::string const &target);

private:
	AForm *_form;

	AForm *getShrubberyCreationForm(std::string const &target);
	AForm *getRobotomyRequestForm(std::string const &target);
	AForm *getPresidentialPardonForm(std::string const &target);

	std::string formatString(std::string formID);
};

#endif

