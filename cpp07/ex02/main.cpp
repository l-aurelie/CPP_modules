#include "Array.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <cstdio>

int main(void)
{
	Array<int> ints;
	
	std::cout << "size of ints = " << ints.size() << std::endl;
	try {
		std::cout << "first elem of ints = " << ints[0] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	Array<int> ints2(12);
	std::cout << "size of ints2 = " << ints2.size() << std::endl;
	std::cout << "default ints2 tab : ";
	for (unsigned int i = 0; i < ints2.size(); i++)
		std::cout << ints2[i] ;
	std::cout << std::endl;
	std::cout << std::endl;


	Array<char> chars(7);
	std::cout << "size of chars = " << chars.size() << std::endl;
	const char *str = "coucou\n";

	std::cout << "default char tab : ";
	for (unsigned int i = 0; i < chars.size(); i++)
		std::putchar(chars[i]);
	for (unsigned int i = 0; i < chars.size(); i++)
		chars[i] = str[i];
	std::cout << std::endl;
	std::cout << "set char tab : ";
	for (unsigned int i = 0; i < chars.size(); i++)
		std::putchar(chars[i]);
	std::cout << "last char of 'coucou\\n' =  "	<< static_cast<int>(chars[chars.size() - 1]) << std::endl;
	std::cout << std::endl;

	Array<Fixed> fixeds(4);
	fixeds[0] = Fixed(12);
	fixeds[1] = Fixed(34.56f);
	fixeds[2] = Fixed(42);
	fixeds[3] = Fixed(42.42f);
	for (unsigned int i = 0; i < fixeds.size(); i++)
		std::cout << fixeds[i] << std::endl;

	return (0);
}
