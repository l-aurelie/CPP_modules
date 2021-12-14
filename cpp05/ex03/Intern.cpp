
#include "Intern.hpp"

Intern::Intern(void) : _form(NULL) {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern(void)
{
	delete _form;
}

/*******************************************************/

Intern &Intern::operator=(const Intern &rhs)
{
	if (this == &rhs)
		return (*this);
	_form = rhs._form;
	return (*this);
}

/*******************************************************/
AForm* Intern::getShrubberyCreationForm(const std::string &target)
{
	delete _form;
	_form = new ShrubberyCreationForm(target);
	return (_form);
}

AForm* Intern::getRobotomyRequestForm(const std::string &target)
{
	delete _form;
	_form = new RobotomyRequestForm(target);
	return (_form);
}

AForm* Intern::getPresidentialPardonForm(const std::string &target)
{
	delete _form;
	_form = new PresidentialPardonForm(target);
	return (_form);
}
/*******************************************************/


std::string Intern::formatString(std::string formatted)
{
	const std::string &sep(" -_");

	for (size_t i = 0; i < formatted.length(); i++)
		formatted[i] = tolower(formatted[i]);

	for (size_t i = 0; i < sep.length(); i++)
		while (formatted.find(sep[i]) != std::string::npos)
			formatted.erase(formatted.find(sep[i]), 1);

	return (formatted);
}

AForm* Intern::makeForm(const std::string &form_name, const std::string &target)
{
	std::string format_string;
	std::string dic_string[NB_FORM]	= { "shrubberycreation", "robotomyrequest", "presidentialpardon" };
	AForm *(Intern::*choose_form[NB_FORM])(const std::string &) = { &Intern::getShrubberyCreationForm,
		   														   &Intern::getRobotomyRequestForm,
		  														   &Intern::getPresidentialPardonForm };

	format_string = formatString(form_name);
	for (int i = 0; i < NB_FORM; i++)
	{
		if (format_string == dic_string[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return ((this->*choose_form[i])(target));
		}
	}
	std::cerr << form_name << ": unknow form" << std::endl;
	return (NULL);
}
