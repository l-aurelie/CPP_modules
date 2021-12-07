#include "Span.hpp"

Span::Span(const unsigned int N): _max_size(N)
{}

Span::Span(Span &src){*this = src;}

Span::~Span(){}

/*********************************************/


Span &Span::operator=(const Span &rhs)
{
	if(this == &rhs)
		return(*this);
	this->_vector = rhs._vector;
	return(*this);
}

/*********************************************/


void Span::addNumber(const int to_add)
{
	if(_vector.size() + 1 < _max_size)
	{
		_vector.push_back(to_add);
	}
	else	
		throw NotEnoughSpace();
}

void Span::setRange(int min, int max)
{
	for ( ; min <= max ; min++)
		addNumber(min);
}

int Span::shortestSpan()
{
	return 0;
}
int Span::longestSpan()
{
	if(_vector.size() < 2)
		throw NoSpanToFind();
	std::vector<int>::iterator it = _vector.begin();
	int min = *it;
	int max = *it;
	for( ; it != _vector.end(); it++)
	{
		if(*it < min)
		min = *it;
	}

	for(it = _vector.begin(); it != _vector.end(); it++)
	{
		if(*it > max)
		max = *it;
	}
	return max - min;
}

void Span::printVector()
{
	for(size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << std::endl;
}


/*********************************************/

const char *Span::NotEnoughSpace::what() const throw()
{
	return("Not enough space to add a value");
}

const char *Span::NoSpanToFind::what() const throw()
{
	return("Can find a span : less than two values");
}
