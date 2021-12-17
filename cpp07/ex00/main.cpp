
#include <iostream>
#include <string>
#include "whatever.hpp"
#include "Fixed.hpp"

int main(void)
{
	int a = 1;
	int b = 42;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "Swap : a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "bonjour";
	std::string d = "coucou";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "Swap : c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;

	Fixed f1(62.5f);
	Fixed f2(32.5f);
	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	swap(f1, f2);
	std::cout << "Swap : f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min(f1, f2) = " << min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << max(f1, f2) << std::endl;

	return (0);
}
