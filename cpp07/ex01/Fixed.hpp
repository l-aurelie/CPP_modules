
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int);
	Fixed(const float);
	~Fixed(void);

	Fixed &operator=(const Fixed & rhs);
	bool operator>(const Fixed & rhs) const;
	bool operator<(const Fixed & rhs) const;
	bool operator>=(const Fixed & rhs) const;
	bool operator<=(const Fixed & rhs) const;
	bool operator==(const Fixed & rhs) const;
	bool operator!=(const Fixed & rhs) const;
	Fixed operator+(const Fixed & rhs) const;
	Fixed operator-(const Fixed & rhs) const;
	Fixed operator*(const Fixed & rhs) const;
	Fixed operator/(const Fixed & rhs) const;
	Fixed &operator++(void);
	Fixed	operator++(int);
	Fixed &operator--(void);
	Fixed	operator--(int);

	static Fixed &min(Fixed &fix1, Fixed &fix2);
	static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
	static Fixed &max(Fixed &fix1, Fixed &fix2);
	static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
	
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
