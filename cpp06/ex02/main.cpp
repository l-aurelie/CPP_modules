
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "generate class a" << std::endl;
			return (new A);
		case 1:
			std::cout << "generate class b" << std::endl;
			return (new B);
		case 2:
			std::cout << "generate class c" << std::endl;
			return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified as class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified as class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified as class C" << std::endl;
}

void identify(Base &p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Identified as class A" << std::endl;
		return;
	} catch (const std::exception &e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Identified as class B" << std::endl;
		return;
	} catch (const std::exception &e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Identified as class C" << std::endl;
		return;
	} catch (const std::exception &e) {}
}

int main(void)
{
	std::srand(std::time(NULL));
	Base *base = generate();
	if (!base)
		return 1;
	identify(base);
	identify(*base);
	return (0);
}
