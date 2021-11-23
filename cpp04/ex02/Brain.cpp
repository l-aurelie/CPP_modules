#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor default" << std::endl;
	setIdea();
}

Brain::Brain(const std::string idea[100])
{
	std::cout << "Brain constructor param" << std::endl;
	for(int i = 0; i < 100; i++)
		this->_idea[i] = idea[i];
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain constructor copy" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor " << std::endl;
}

/*****************************************************/

Brain & Brain::operator=(const Brain &rhs)
{
	std::cout << "Assignation" << std::endl;
	if(this == &rhs)
		return (*this);
	for(int i = 0; i < 100; i++)
		this->_idea[i] = rhs._idea[i];
	return (*this);
}

/*****************************************************/


void	Brain::setIdea()
{
	for (int i = 0; i < 3; i++)
		this->_idea[i] = "I have no idea?";
}

void	Brain::setIdea(int index, std::string new_idea)
{
	if(new_idea.empty())
		new_idea = " ";
	this->_idea[index] = new_idea;
}

void Brain::print_brain_content() const
{
	for(int i = 0; i < 100 && !this->_idea[i].empty(); i++)
		std::cout << this->_idea[i] << std::endl;
}
