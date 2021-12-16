
#include <iostream>
#include <stdint.h>

struct Data
{
	int nb;
	char c;
	std::string str;
	float float_nb;
	double double_nb;
};

void print_data(Data *data)
{
	std::cout << data->nb << " | " << data->c <<  " | " << data->str <<  " | " << data->float_nb << " | " << data->double_nb << std::endl;
}

uintptr_t serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }

int main(void) {
	Data data = {300, 'a', "Hello_world", 12.2f, 16.4};

	print_data(&data);
	std::cout << "serialize = " << serialize(&data) << std::endl; 

	std::cout << "deserialize = ";
	print_data(deserialize(serialize(&data)));

	return 0;
}
