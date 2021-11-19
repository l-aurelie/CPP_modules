#include <iostream>
#include <string>
#include "Karen.hpp"

int	main()
{
	Karen karen;

	karen.complain("DEBUG");
	std::cout << std::endl;
	karen.complain("INFO");
	std::cout << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;
	karen.complain("ERROR");
	std::cout << std::endl;
	karen.complain("ERRrOR");
	return 0;
}
