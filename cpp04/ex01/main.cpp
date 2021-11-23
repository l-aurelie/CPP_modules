#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

//destruct as an animal(doit appeler aussi le destructeur cat/dog)
//->virtual destructor
void leak_tests()
{
	std::cout << "================ LEAKS TEST=================" << std::endl;
	std::cout << std::endl;
	const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	std::cout << std::endl;
	std::cout << std::endl;
}

//destruct as an animal(doit appeler aussi le destructeur cat/dog)
void animal_array_test()
{
	std::cout << "================ ARRAY TEST=================" << std::endl;
	std::cout << std::endl;
	Animal* tab[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 4/2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	for (int i = 0; i < 4; i++)
			delete tab[i];
	std::cout << std::endl;
	std::cout << std::endl;
}


//changer les idees de dog2 n'influ pas sur dog2 (on a bien une deep copie)
void deep_copy_test()
{
	std::cout << "================DEEP COPY TEST=================" << std::endl;
	std::cout << std::endl;
	std::cout << "===CREATION DOG 1" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "My name is dog1");
	std::cout << "==Dog1 brain content: " << std::endl;
	dog1.getBrain()->print_brain_content();
	std::cout << "===CREATION DOG 2" << std::endl;
	Dog dog2(dog1);
	dog2.getBrain()->setIdea(0, "My name is Dog2");
	std::cout << "==Dog2 brain content: " << std::endl;
	dog2.getBrain()->print_brain_content();

	std::cout << "==Dog1 brain content: " << std::endl;
	dog1.getBrain()->print_brain_content();
}

int main(void)
{
	leak_tests();
	animal_array_test();
	deep_copy_test();
	return 0;
}
