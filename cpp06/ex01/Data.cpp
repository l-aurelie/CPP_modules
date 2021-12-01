#include "Data.hpp"

Data::Data(char c, std::string s, int i, float f, double d): c(c), s(s), i(i), f(f), d(d){}

Data::Data(const Data &src){*this = src;}

Data::~Data(){}

Data &Data::operator=(const Data &rhs)
{
	if(this == &rhs)
		return (*this);
	c = rhs.c;
	s = rhs.s;
	i = rhs.i;
	f = rhs.f;
	d = rhs.d;
	return(*this);
}

std::ostream &operator<<(std::ostream &os, const Data &rhs)
{
	os << "add = " << &rhs << " | " << rhs.c <<  " | " << rhs.s <<  " | " << rhs.i <<  " | " << rhs.f <<  " | " << rhs.d << std::endl; 
	return os;
}

