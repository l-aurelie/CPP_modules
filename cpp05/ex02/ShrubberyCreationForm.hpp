
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm(const std::string &target = "target");
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm(void);

		void execute(const Bureaucrat &executor) const;

	private:
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};

#endif
