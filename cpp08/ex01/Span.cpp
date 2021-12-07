#include "Span.hpp"
#include <cmath>
#include <climits>

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
	if(_vector.size() + 1 <= _max_size)
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
	//std::cout << "shortest" << std::endl;
	if(_vector.size() < 2)
		throw NoSpanToFind();
	int shortest = INT_MAX;
	for(std::vector<int>::iterator it = _vector.begin(); it != _vector.end() ; it++)
	{
		for(std::vector<int>::iterator jt = _vector.begin(); jt != _vector.end() ; jt++)
		{
	//		std::cout << *it << " | " << *jt << std::endl;
			if(it == jt)
			{
	//			std::cout << "increment j" << std::endl;
				jt++;
				if(jt == _vector.end())
					break;
			}
			if(abs(*it - *jt) < shortest)
			{
				shortest = abs(*it - *jt);
	//			std::cout << "shortest = " << shortest << std::endl;
			}
		}
	}
	return(shortest);
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
	std::cout << "Vector : " << std::endl;
	for(size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " | ";
	std::cout << std::endl;
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
