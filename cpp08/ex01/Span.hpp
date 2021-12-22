#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span{
public:
	Span(const unsigned int N = 0);
	Span(Span &src);
	~Span();

	Span &operator=(const Span &rhs);

	void addNumber(const int to_add);
	void setRange(int min, int max);
	void setRange(std::vector<int>::iterator it, std::vector<int>::iterator ite);
	void printVector();

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NotEnoughSpace : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class NoSpanToFind : public std::exception
	{
	public:
	   	const char *what() const throw();
	};

private:
	std::vector<int> _vector;
	size_t _max_size;
};

#endif
