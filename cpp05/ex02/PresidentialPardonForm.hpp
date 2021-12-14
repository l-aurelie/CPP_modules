
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(const std::string &target = "target");
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm(void);

	void execute(const Bureaucrat &executor) const;

private:
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};

#endif
