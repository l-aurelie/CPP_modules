#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed e(2);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << std::endl;

	std::cout << (a > b ? "a > b":" a > b is a wrong statement") << std::endl;
	std::cout << (a < b ? "a < b":" a < b is a wrong statement") << std::endl;
	std::cout << (b < a ? "b < a ":"b < a is a wrong statement") << std::endl;
	std::cout << (b == d ? "b == d ":"b == d is a wrong statement") << std::endl;
	std::cout << (b != a ? "b != a ":"b != a is a wrong statement") << std::endl;
	std::cout << (b <= d ? "b <= d ":"b <= d is a wrong statement") << std::endl;
	std::cout << (b >= d ? "b >= d ":"b <= d is a wrong statement") << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	std::cout << std::endl;

	a = 0;
	std::cout << "++a = " << ++a << std::endl;
	a = 0;
	std::cout << "a++ = " << a++ << std::endl;
	a = 0;
	std::cout << "--a = " << --a << std::endl;
	a = 0;
	std::cout << "a-- = " << a-- << std::endl;
	
	std::cout << std::endl;
	a = -1;
	std::cout << "a, e respectively" << std::endl;
	std::cout << a << ", " << e << std::endl;
	std::cout << "min : " << Fixed::min(a, e) << std::endl;
	std::cout << "max : " << Fixed::max(a, e) << std::endl;
	
	std::cout << std::endl;
	std::cout << "b, c respectively" << std::endl;
	std::cout << b << ", " << c << std::endl;
	std::cout << "min : " << Fixed::min(b, c) << std::endl;
	std::cout << "max : " << Fixed::max(b, c) << std::endl;
	return 0;
}
