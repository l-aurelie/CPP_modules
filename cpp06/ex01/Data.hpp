#ifndef DATA_HPP
#define DATA_HPP 

#include <ostream>
#include <string>

class Data{
public: 

	Data(char c = '0', std::string s = "default", int i = 0, float f = 0.0f, double d = 0.0);
	Data(const Data &src);
	~Data();

	Data &operator=(const Data &rhs);

	char c;		
	std::string s;
	int i;		
	float f;		
	double d;		
};

std::ostream &operator<<(std::ostream &os, const Data &rhs);
#endif
