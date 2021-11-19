#include <iostream>
#include <string>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	int i;
	Karen karen;
	std::string level_tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (i = 0; i < 4 && level_tab[i] != argv[1]; i++)
		;
	switch(i)
	{
		case 0:
			karen.complain("DEBUG");
			__attribute__ ((fallthrough));	
	case 1:
			karen.complain("INFO");
			__attribute__ ((fallthrough));	
		case 2:
			karen.complain("WARNING");
			__attribute__ ((fallthrough));	
		case 3:
			karen.complain("ERROR");
			break;
		default:
			std::cout << "not an important problem" << std::endl;
	}
	return 0;
}
