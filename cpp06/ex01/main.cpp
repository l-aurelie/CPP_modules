#include <iostream>
#include "Data.hpp"
#include <cstdint>

uintptr_t serialize(Data* ptr)
{
	return(0);
}

Data* deserialize(uintptr_t raw)
{
	return(nullptr);
}

int main()
{
	Data data('1', "coucou", 2, 3.0f, 4.0);

	std::cout << data << std::endl;
	std::cout << *deserialize(serialize(&data)) << std::endl;
	return 0;
}
