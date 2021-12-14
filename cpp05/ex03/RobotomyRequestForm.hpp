
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(std::string const &target = "target");
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm(void);

	void execute(Bureaucrat const &executor) const;

private:
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
};

#endif
