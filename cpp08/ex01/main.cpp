#include "Span.hpp"

int	main()
{
	std::cout << "============Test span" << std::endl;
	Span span(6);
	try
	{
		span.addNumber(50);
		span.addNumber(40);
		span.addNumber(5);
		span.addNumber(2);
		span.addNumber(0);
		span.addNumber(0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	span.printVector();
	std::cout << "longest span = " << span.longestSpan() << std::endl;
	std::cout << "shortest span = " << span.shortestSpan() << std::endl;


	std::cout << "============Test span2" << std::endl;
	Span span2(20);
	try
	{
		span2.setRange(1, 20);
		span2.printVector();
		std::cout << "longest span = " << span2.longestSpan() << std::endl;
		std::cout << "shortest span = " << span2.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}



	std::cout << "============Test span3" << std::endl;
	Span span3(1);
	try
	{
		span3.addNumber(5);
		span3.printVector();
		std::cout << "longest" << std::endl;
		std::cout << "longest span = " << span3.longestSpan() << std::endl;
		std::cout << "shortest span = " << span3.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
