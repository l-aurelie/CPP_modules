#include "Fixed.hpp"

const int Fixed::_fractional_part_size = 8;

//*********************************************************//

Fixed::Fixed(void): _nb(0)
{}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value): _nb(value << Fixed::_fractional_part_size)
{}

Fixed::Fixed(const float value): _nb(roundf(value * (1 << Fixed::_fractional_part_size)))
{}

Fixed::~Fixed(void)
{}


//*********************************************************//

Fixed & Fixed::operator=(const Fixed & rhs)
{
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
bool Fixed::operator>(const Fixed & rhs) const
{
	return(this->_nb > rhs._nb);
}

bool Fixed::operator<(const Fixed & rhs) const
{
	return(this->_nb < rhs._nb);
}

bool Fixed::operator>=(const Fixed & rhs) const
{
	return(this->_nb >= rhs._nb);
}

bool Fixed::operator<=(const Fixed & rhs) const
{
	return(this->_nb <= rhs._nb);
}

bool Fixed::operator==(const Fixed & rhs) const
{
	return(this->_nb == rhs._nb);
}

bool Fixed::operator!=(const Fixed & rhs) const
{
	return(this->_nb != rhs._nb);
}

Fixed Fixed::operator+(const Fixed & rhs) const
{
	return(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed & rhs) const
{
	return(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed & rhs) const
{
	return(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed & rhs) const
{
	return(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void)
{
	this->_nb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_nb++;
	return (tmp);
}

Fixed & Fixed::operator--(void)
{
	this->_nb--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_nb--;
	return (tmp); 
}


//*********************************************************//	

Fixed & Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return (fix1 < fix2 ? fix1 : fix2);
}

const Fixed & Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	return (fix1 < fix2 ? fix1 : fix2);
}

Fixed & Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return(fix1 > fix2 ? fix1 : fix2);
}

const Fixed  & Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	return(fix1 > fix2 ? fix1 : fix2);
}

int Fixed::getRawBits(void) const
{
	return(this->_nb);
}

void Fixed::setRawBits(int const raw)
{
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
