
#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

int main(void) {
	MateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	std::cout << "========print source1 ";
	src1->printSource();

	std::cout << std::endl;

	MateriaSource* src2 = new MateriaSource();
	*src2				= *src1;
	std::cout << "========print source2 ";
	src2->printSource();

	std::cout << std::endl;

	Character* aurelie  = new Character("aurelie");
	Character* some_student = new Character();

	AMateria* tmp1;
	tmp1 = src2->createMateria("ice");
	aurelie->equip(tmp1);
	AMateria* tmp2;
	tmp2 = src1->createMateria("cure");
	aurelie->equip(tmp2);

	std::cout << "========print aurelie inventory";
	aurelie->printInventory();
	std::cout << std::endl;

	*some_student = *aurelie;
	std::cout << "========print some_student inventory"; 
	some_student->printInventory();
	std::cout << std::endl;

	Character* punching_ball = new Character("punching_ball");

	std::cout << "aurelie attacks punching_ball : " << std::endl;
	aurelie->use(0, *punching_ball);
	aurelie->use(1, *punching_ball);

	std::cout << std::endl;

	std::cout << "some_student attacks punching_ball : " << std::endl;
	some_student->use(0, *punching_ball);
	some_student->use(1, *punching_ball);

	aurelie->unequip(0);

	delete tmp1;
	delete punching_ball;
	delete aurelie;
	delete some_student;
	delete src1;
	delete src2;
	return 0;
}
