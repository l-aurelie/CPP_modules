
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat b_min("b_min", MIN_GRADE);
		std::cout << b_min;
		b_min.incrementGrade();
		std::cout << b_min;

		//Bureaucrat b_error("b_error", 300);//grade hors champ 
		//std::cout << b_error;

		Bureaucrat b_max("b_max", MAX_GRADE);
		std::cout << b_max;

		b_max.incrementGrade();//grade hors champ
	}
	catch (const Bureaucrat::gradeTooLowException &e)
	{
		std::cerr << "Error: the grade is too low." << std::endl;
	}
	catch (const Bureaucrat::gradeTooHighException &e)
	{
		std::cerr << "Error: the grade is too high." << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		Bureaucrat b_min("b_min", MIN_GRADE);
		std::cout << b_min;

		Bureaucrat b_max("b_max", MAX_GRADE);
		std::cout << b_max;

		b_max.decrementGrade(); 
		std::cout << b_max;
		b_min.decrementGrade();
		std::cout << b_min;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
