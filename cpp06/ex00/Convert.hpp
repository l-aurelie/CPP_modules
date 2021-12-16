
#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#define NB_CONV 4

class Convert
{
public:
	Convert(const Convert &src);
	Convert(const std::string &input_value);

	~Convert(void);

	void print(void);

	Convert &operator=(const Convert &rhs);

private:
	std::string input_value;
	int i;
	char c;
	float f;
	double d;
	bool input_val_error;

	Convert(void);

	bool isChar(void);
	bool isInt(void);
	bool isFloat(void);
	bool isDouble(void);
	void setConv(void);
	void setFromChar(void);
	void setFromInt(void);
	void setFromFloat(void);
	void setFromDouble(void);
	void printChar(void) const;
	void printInt(void) const;
	void printFloat(void) const;
	void printDouble(void) const;
};

#endif
