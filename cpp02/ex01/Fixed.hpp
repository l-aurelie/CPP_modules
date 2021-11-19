#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int);
	Fixed(const float);
	~Fixed(void);

	Fixed &operator=(const Fixed & rhs);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _nb;
	static const int _fractional_part_size;
};

std::ostream &operator<<(std::ostream &o, const Fixed &nb);

#endif
