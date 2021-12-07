#include "Span.hpp"

int	main()
{
	Span span(2);
	
	span.printVector();
	try
	{
		span.addNumber(5);
		span.addNumber(4);
		span.addNumber(3);
		span.addNumber(2);
		span.addNumber(1);
		span.addNumber(0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	span.printVector();

	Span span2(20);
	
	span.printVector();
	try
	{
		span2.setRange(1, 20);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	span2.printVector();
	return 0;
}
