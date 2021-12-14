
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreation", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	setIsSigned(src.getIsSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/*******************************************************/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return (*this);
}


/*******************************************************/

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw AForm::gradeTooLowException();
	else if (!getIsSigned())
		throw AForm::formUnsigned();

	std::ofstream outfile;

	outfile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	outfile.open(std::string().append(getTarget()).append("_shrubbery").c_str());
	outfile << "          .     .  .      +     .      .          ." << std::endl
	<< "     .       .      .     #       .           ." << std::endl
	<< "        .      .         ###            .      .      ." << std::endl
	<< "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl
	<< "          .      . \"####\"###\"####\"  ." << std::endl
	<< "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl
	<< "  .             \"#########\"#########\"        .        ." << std::endl
	<< "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl
	<< "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl
	<< "                .\"##\"#####\"#####\"##\"           .      ." << std::endl
	<< "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl
	<< "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl
	<< "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl
	<< "            .     \"      000      \"    .     ." << std::endl
	<< "       .         .   .   000     .        .       ." << std::endl
	<< ".. .. ..................O000O........................ ...... ..." << std::endl;
}
