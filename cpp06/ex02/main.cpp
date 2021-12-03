#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void)
{
	switch (std::rand() % 3) {
		case 0:
			std::cout << "class a" << std::endl;
			return (new A);
		case 1:
			std::cout << "class b" << std::endl;
			return (new B);
		case 2:
			std::cout << "class c" << std::endl;
			return (new C);	
	}
	return (nullptr);
}

void identify(Base * p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Is class A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Is class B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Is class C" << std::endl;
}

void identify(Base & p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Is class A" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Is class B" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Is class C" << std::endl;
		return ;
	}
	catch(const std::exception &e) {}
}

#include <stdlib.h>

int main()
{
	std::srand(std::time(nullptr));
	Base *base = generate();
	if (!base)
		return 1;
	identify(base);
	identify(*base);
	delete base;
	return(0);
}
