#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test_animal()
{
	std::cout << "ANIMAL ====" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;
}

void test_wrong_animal()
{
	std::cout << "WRONG ANIMAL ====" << std::endl;
	const WrongAnimal* metawrong = new WrongCat();
	metawrong->makeSound();
	delete metawrong;
}

int main()
{
	test_animal();
	test_wrong_animal();
}
