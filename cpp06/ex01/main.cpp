#include <iostream>
#include "Data.hpp"
#include <cstdint>

uintptr_t serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}

int main()
{
	Data data('1', "coucou", 2, 3.0f, 4.0);

	std::cout << data << std::endl;
	std::cout << "serialize return = " << serialize(&data) << std::endl;
	std::cout << *deserialize(serialize(&data)) << std::endl;
	return 0;
}
