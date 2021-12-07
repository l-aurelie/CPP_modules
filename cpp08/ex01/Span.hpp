#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span{
public:
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

	Span(const unsigned int N = 0);
	Span(Span &src);
	~Span();

	Span &operator=(const Span &rhs);

	void addNumber(const int to_add);
	void setRange(int min, int max);
	int shortestSpan();
	int longestSpan();
	void printVector();

private:
	std::vector<int> _vector;
	size_t _max_size;
};

#endif
