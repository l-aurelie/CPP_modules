#include "Karen.hpp"

Karen::Karen(void){}
Karen::~Karen(void){}

void Karen::complain(const std::string &level)
{
	const std::string level_tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*fct_tab[])(void) const = {&Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error};		
	for(int i = 0; i < 4; i++)
	{
		if (!level.compare(level_tab[i]))
		{
			(this->*fct_tab[i])();
			return;
		}
	}
	std::cout << "Error on Karen's level" << std::endl;
}

void Karen::_debug(void) const
{
	std::cout << "[DEBUG]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;

}

void Karen::_info(void) const
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}	

void Karen::_warning(void) const
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;

}	

void Karen::_error(void) const
{
	std::cout << "[ERROR]\nThis is unacceptable, I want to speak to the manager now." << std::endl;
}
