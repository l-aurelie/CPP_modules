
#include "Convert.hpp"
#include <climits>

Convert::Convert(void) {}

Convert::Convert(const Convert &src) { *this = src; }

Convert::Convert(const std::string &input_value) : input_value(input_value), input_val_error(false)
{
	this->setConv();
}

Convert::~Convert(void) {}

void Convert::print(void)
{
	if (this->input_val_error)
		return;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

void Convert::setConv(void)
{
	int index;
	bool (Convert::*is[NB_CONV])()	= {&Convert::isChar, &Convert::isInt, &Convert::isFloat, &Convert::isDouble};
	void (Convert::*set[NB_CONV])() = {&Convert::setFromChar, &Convert::setFromInt, &Convert::setFromFloat, &Convert::setFromDouble};

	for (index = 0; index < NB_CONV; index++)
		if ((this->*is[index])())
			return (this->*set[index])();
	std::cerr << "Error: unknow literal value." << std::endl;
	this->input_val_error = true;
}

bool Convert::isChar(void)
{
	return (this->input_value.length() == 1 && !std::isdigit(this->input_value[0])) ? true : false;
}

bool Convert::isInt(void)
{
	std::stringstream ss;
	std::string residual;

	ss << this->input_value;
	ss >> this->i;
	if (ss.bad() || ss.fail()
		|| (i == std::numeric_limits<int>::min()
			&& this->input_value != std::string("-2147483648")))
		return (false);
	ss >> residual;
	return (residual.empty() ? true : false);
}

bool Convert::isFloat(void)
{
	std::stringstream ss;
	std::string residual;

	if (this->input_value == "nanf" || this->input_value == "+inff"
		|| this->input_value == "inff" || this->input_value == "-inff")
		return (true);

	ss << this->input_value;
	ss >> this->f >> this->c;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> residual;
	if (this->c == 'f' && residual.empty())
{
		std::cout << std::setprecision(this->input_value.length() - 2);
		return (true);
	}
	return (false);
}

bool Convert::isDouble(void)
{
	std::stringstream ss;
	std::string residual;

	if (this->input_value == "nan" || this->input_value == "+inf"
		|| this->input_value == "inf" || this->input_value == "-inf")
		return (true);

	ss << this->input_value;
	ss >> this->d;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> residual;
	if (residual.empty())
{
		std::cout << std::setprecision(this->input_value.length() - 1);
		return (true);
	}
	return (false);
}

void Convert::setFromChar(void)
{
	std::stringstream ss;

	ss << this->input_value;
	ss >> this->c;
	this->i = static_cast<int>(this->c);
	this->f = static_cast<float>(this->c);
	this->d = static_cast<double>(this->c);
}

void Convert::setFromInt(void)
{
	std::stringstream ss;

	ss << this->input_value;
	ss >> this->i;
	this->c = static_cast<int>(this->i);
	this->f = static_cast<float>(this->i);
	this->d = static_cast<double>(this->i);
}

void Convert::setFromFloat(void)
{
	std::stringstream ss;

	ss << this->input_value;
	ss >> this->f;

	if (this->input_value == "inff" || this->input_value == "+inff")
		this->f = std::numeric_limits<float>::infinity();
	else if (this->input_value == "-inff")
		this->f = std::numeric_limits<float>::infinity() * -1;
	else if (this->input_value == "nanf")
		this->f = std::numeric_limits<float>::quiet_NaN();

	this->c = static_cast<int>(this->f);
	this->i = static_cast<float>(this->f);
	this->d = static_cast<double>(this->f);
}

void Convert::setFromDouble(void)
{
	std::stringstream ss;

	ss << this->input_value;
	ss >> this->d;

	if (this->input_value == "inf" || this->input_value == "+inf")
		this->d = std::numeric_limits<double>::infinity();
	else if (this->input_value == "-inf")
		this->d = std::numeric_limits<double>::infinity() * -1;
	else if (this->input_value == "nan")
		this->d = std::numeric_limits<double>::quiet_NaN();

	this->c = static_cast<int>(this->d);
	this->i = static_cast<float>(this->d);
	this->f = static_cast<double>(this->d);
}

void Convert::printChar(void) const
{
	if (this->input_value == "inf" || this->input_value == "+inf"
		|| this->input_value == "-inf" || this->input_value == "nan"
		|| this->input_value == "inff" || this->input_value == "+inff"
		|| this->input_value == "-inff" || this->input_value == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(this->c))
		std::cout << "char: '" << this->c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void Convert::printInt(void) const
{
	if (this->input_value == "inf" || this->input_value == "+inf"
		|| this->input_value == "-inf" || this->input_value == "nan"
		|| this->input_value == "inff" || this->input_value == "+inff"
		|| this->input_value == "-inff" || this->input_value == "nanf"
		|| (this->i == std::numeric_limits<int>::min()
			&& this->input_value != "-2147483648"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->i << std::endl;
}

void Convert::printFloat(void) const
{
	std::cout << "float: " << this->f << ((!fmod(this->f, 1.0f)) ? ".0f" : "f")
			  << std::endl;
}

void Convert::printDouble(void) const
{
	std::cout << "double: " << this->d << ((!fmod(this->d, 1.0)) ? ".0" : "")
			  << std::endl;
}

Convert &Convert::operator=(const Convert &rhs)
{
	if (this == &rhs)
		return (*this);
	this->input_value = rhs.input_value;
	this->c	= rhs.c;
	this->i	= rhs.i;
	this->f	= rhs.f;
	this->d	= rhs.d;
	this->input_val_error = rhs.input_val_error;
	return (*this);
}
