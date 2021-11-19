#include "Fixed.hpp"

const int Fixed::_fractional_part_size = 8;

//*********************************************************//

Fixed::Fixed(void): _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value): _nb(value << Fixed::_fractional_part_size)
{
	std::cout << "Int construction called" << std::endl;
}

Fixed::Fixed(const float value): _nb(roundf(value * (1 << Fixed::_fractional_part_size)))
{
	std::cout << "Float construction called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


//*********************************************************//

Fixed & Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_nb = rhs._nb;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &nb)
{
	o << nb.toFloat();
	return o;	
}


//*********************************************************//
	
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_nb);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->_nb) / (1 << Fixed::_fractional_part_size));
}

int Fixed::toInt(void) const
{
	return (this->_nb >> Fixed::_fractional_part_size);
}
