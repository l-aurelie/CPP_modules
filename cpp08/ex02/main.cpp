#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "top of mstack = "  << mstack.top() << std::endl;
	std::cout << "mstack size = " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "mstack size after pop = " << mstack.size() << std::endl;
	std::cout << "print mstack = ";
	for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		std::cout << *it << " | ";
		++it;
		--it;
	}
	std::cout << std::endl << std::endl;


	std::stack<int> s(mstack);//MutantStack herite bien de stack
	
	MutantStack<int> m(mstack);
	std::cout << "top of m= "  << mstack.top() << std::endl;
	std::cout << "m size = " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "m size after pop = " << mstack.size() << std::endl;
	std::cout << "print m = ";
	for(MutantStack<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << *it << " | ";
		++it;
		--it;
	}
	std::cout << std::endl << std::endl;

	MutantStack<std::string> stack_str;
	stack_str.push("coucou");
	stack_str.push("every body");
	stack_str.push("hello");
	stack_str.push("tout");
	stack_str.push("le");
	stack_str.push("monde");
	std::cout << "top of stack_str = "  << stack_str.top() << std::endl;
	std::cout << "stack_str size = " << stack_str.size() << std::endl;
	stack_str.pop();
	std::cout << "stack_str size after pop = " << stack_str.size() << std::endl;
	std::cout << "print stack_str = ";
	for(MutantStack<std::string>::iterator it = stack_str.begin(); it != stack_str.end(); it++)
	{
		std::cout << *it << " | ";
		++it;
		--it;
	}
	std::cout << std::endl << std::endl;

	return 0;
}
