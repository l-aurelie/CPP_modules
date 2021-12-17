
#include "iter.hpp"
#include"Fixed.hpp"
#include <cstring>
#include <iostream>

void	add_1(Fixed &elem)
{
	elem = elem + 1;
}

void	ft_putchar(char &c)
{
	std::cout << c;
}

int main(void)
{
	Fixed tab[] = {3.5f, 7, 23.2f, 8};
	char str[] = "Hello world\n";

	iter<char>(str, static_cast<int>(strlen(str)), &ft_putchar);
	std::cout << std::endl;

	for(int i = 0; i < 4; i++)
		std::cout << tab[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;

	iter<Fixed>(tab, 4, &add_1);
	for(int i = 0; i < 4; i++)
		std::cout << tab[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
