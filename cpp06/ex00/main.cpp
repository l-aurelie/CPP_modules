#include <cstdlib>
#include <iostream>
#include "Convert.hpp"

// TODO: add const to member functions.

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Bad number of arguments." << std::endl
			<< "Usage ./convert \"literal_value\"" << std::endl;
		return (EXIT_FAILURE);
	}
	
	Convert convert(argv[1]);
	convert.print();

	return (EXIT_SUCCESS);
}

