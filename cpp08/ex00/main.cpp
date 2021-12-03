#include <iostream>
#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

int main()
{
	std::cout << "test vector=========" << std::endl;
	int to_find = 2;
	std::vector<int> vector(4, 2);
	std::vector<int>::iterator it;

	try
	{
		it = easyfind(vector, to_find);
		std::cout << to_find << " found in vector" << std::endl;
	}
	catch(const ElementNotFound &e)
	{	
		std::cerr << e.what() << std::endl;
	}	
	vector.push_back(5);
	try
	{
		it = easyfind(vector, to_find);
		std::cout << to_find << " found in vector" << std::endl;
	}
	catch(const ElementNotFound &e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "test list=========" << std::endl;
	std::list<int> list;
	std::list<int>::iterator it2;

	list.push_back(4);
	list.push_back(4);
	try
	{
		it2 = easyfind(list, to_find);
		std::cout << to_find << " found in vector" << std::endl;
	}
	catch(const ElementNotFound &e)
	{	
		std::cerr << e.what() << std::endl;
	}	
	list.push_back(5);
	try
	{
		it2 = easyfind(list, to_find);
		std::cout << to_find << " found in vector" << std::endl;
	}
	catch(const ElementNotFound &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
