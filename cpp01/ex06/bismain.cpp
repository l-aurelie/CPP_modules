#include <iostream>
#include <string>
#include <map>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	Karen karen;
	std::map<std::string, int> level;
	level["DEBUG"] = 1;
	level["INFO"] = 2;
	level["WARNING"] = 3;
	level["ERROR"] = 4;

	switch(level[argv[1]])
	{
		case 1:
			karen.complain("DEBUG");
		case 2:
			karen.complain("INFO");
		case 3:
			karen.complain("WARNING");
		case 4:
			karen.complain("ERROR");
			break;
		default:
			std::cout << "not an important problem\n" << std::endl;
	}
	return 0;
}
