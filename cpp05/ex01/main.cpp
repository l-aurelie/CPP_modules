#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat bureaucrat("bureaucrat", 5);

	Form f1("f1", 4);
	Form f2("f2", 5);
	Form f3("f3", 6);
	Form f4("f4");

	bureaucrat.signForm(f1);
	bureaucrat.signForm(f2);
	bureaucrat.signForm(f3); // Cannot be signed
	bureaucrat.signForm(f4); // Cannot be signed
	try {
		Form f_err("f_err", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Cannot create form because: " << e.what() << std::endl;
	}
}
