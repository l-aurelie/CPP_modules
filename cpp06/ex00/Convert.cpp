#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(const Convert &src)
{
	*this = src;
}

Convert::Convert(const std::string &literal_value): _literal_value(literal_value), _literal_error(false)
{
	setConv();
}

Convert::~Convert() {}


/*********************************************/

Convert &Convert::operator=(const Convert &rhs)
{
	if (this == &rhs)
		return (*this);
	_literal_value = rhs._literal_value;
	_literal_error = rhs._literal_error;
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	return (*this);
}


/*********************************************/

void Convert::print()
{
	if (_literal_error)
		return ;
	printChar();
	printInt();
	printFloat();
	printDouble();
}

bool Convert::isChar()
{
	if (_literal_value.length() == 1 && !std::isdigit(_literal_value.at(0)))
		return (true);
	return (false);
}

bool Convert::isInt()
{
	std::stringstream ss;
	std::string garbage;

	ss << _literal_value;
	ss >> _i;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	if (garbage.empty())
		return (true);
	return (false);
}

bool Convert::isFloat()
{
	std::stringstream ss;
	std::string garbage;

	if(_literal_value == "nanf" || _literal_value == "+inff" || _literal_value == "inff" || _literal_value == "-inff")
		return (true);

	ss << _literal_value;
	ss >> _f >> _c;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	if (_c == 'f' && garbage.empty())
	{
		std::cout << std::setprecision(_literal_value.length() - 2);
		return (true);
	}
	return (false);
}

bool Convert::isDouble()
{
	std::stringstream ss;
	std::string garbage;

	if(_literal_value == "nan" || _literal_value == "+inf" || _literal_value == "inf" || _literal_value == "-inf")
		return (true);

	ss << _literal_value;
	ss >> _d;
	if (ss.bad() || ss.fail())
		return (false);
	ss >> garbage;
	if (garbage.empty())
	{
		std::cout << std::setprecision(_literal_value.length() - 1);
		return (true);
	}
	return (false);
}

void Convert::setConv()
{
	int index;
	bool (Convert::*is[])() = {
		&Convert::isChar,
		&Convert::isInt,
		&Convert::isFloat,
		&Convert::isDouble
	};
	void (Convert::*set[])() = {
		&Convert::setFromChar,
		&Convert::setFromInt,
		&Convert::setFromFloat,
		&Convert::setFromDouble
	};

	for (index = 0; index < 4; index++)
		if ((this->*is[index])())
			break ;

	if (index >= 4)
	{
		std::cerr << "Error: unknow literal value." << std::endl;
		_literal_error = true;
		return ;
	}
	(this->*set[index])();
}

void Convert::setFromChar()
{
	std::stringstream ss;

	ss << _literal_value;
	ss >> _c;
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void Convert::setFromInt()
{
	std::stringstream ss;

	ss << _literal_value;
	ss >> _i;
	_c = static_cast<int>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void Convert::setFromFloat()
{
	std::stringstream ss;

	ss << _literal_value;
	ss >> _f;

	if(_literal_value == "inff" || _literal_value == "+inff")
		_f = std::numeric_limits<float>::infinity();
	else if(_literal_value == "-inff")
		_f = std::numeric_limits<float>::infinity()	* -1;
	else if(_literal_value == "nanf")
		_f = std::numeric_limits<float>::quiet_NaN();

	_c = static_cast<int>(_f);
	_i = static_cast<float>(_f);
	_d = static_cast<double>(_f);
}

void Convert::setFromDouble()
{
	std::stringstream ss;

	ss << _literal_value;
	ss >> _d;

	if(_literal_value == "inf" || _literal_value == "+inf")
		_d = std::numeric_limits<double>::infinity();
	else if(_literal_value == "-inf")
		_d = std::numeric_limits<double>::infinity() * -1;
	else if(_literal_value == "nan")
		_d = std::numeric_limits<double>::quiet_NaN();

	_c = static_cast<int>(_d);
	_i = static_cast<float>(_d);
	_f = static_cast<double>(_d);
}

void Convert::printChar() const
{
	if(_literal_value == "inf" || _literal_value == "+inf" || _literal_value == "-inf" || _literal_value == "nan" || _literal_value == "inff" || _literal_value == "+inff" || _literal_value == "-inff" || _literal_value == "nanf")
		std::cout << "char: impossible" << std::endl;

	else if (std::isprint(_c))
		std::cout << "char: '" << _c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void Convert::printInt() const
{
	if(_literal_value == "inf" || _literal_value == "+inf" || _literal_value == "-inf" || _literal_value == "nan" || _literal_value == "inff" || _literal_value == "+inff" || _literal_value == "-inff" || _literal_value == "nanf")
		std::cout << "int: impossible" << std::endl;
	
	else
		std::cout << "int: " << _i << std::endl;
}

void Convert::printFloat() const
{
 	if (!fmod(_f, 1.0f))
		std::cout << "float: " << _f << ".0f" << std::endl;
	else
		std::cout << "float: " << _f << "f" << std::endl;
}

void Convert::printDouble() const
{
	if (!fmod(_d, 1.0))
		std::cout << "double: " << _d << ".0" << std::endl;
	else
		std::cout << "double: " << _d << std::endl;
}
