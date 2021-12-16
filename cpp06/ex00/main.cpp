
#include "Convert.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		return (1);
	}

	Convert convert(argv[1]);
	convert.print();

	return (0);
}

