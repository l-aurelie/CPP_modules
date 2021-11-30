#ifndef CONVERT_HPP 
#define CONVERT_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>

class Convert {
public:
	Convert(const Convert &src);
	Convert(const std::string &literal_value);
	~Convert();

	void print();

	Convert &operator=(const Convert &rhs);

private:
	Convert();

	std::string _literal_value;

	bool _literal_error;

	int _i;
	char _c;
	float _f;
	double _d;

	bool isChar();
	bool isInt();
	bool isFloat();
	bool isDouble();

	void setConv();

	void setFromChar();
	void setFromInt();
	void setFromFloat();
	void setFromDouble();

	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;
};

#endif
