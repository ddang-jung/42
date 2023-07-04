#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// void	leak() {
// 	system("leaks ex01_");
// }

int main()
{
	// atexit(leak);
	// std::cout << "************* DOG TEST *************" << std::endl;
	// Dog	*dog1 = new Dog();
	// Dog	*dog2 = new Dog("Bone...");
	// std::cout << std::endl;

	// std::cout << dog1->getBrain().getIdea() << std::endl;
	// std::cout << dog2->getBrain().getIdea() << std::endl;
	// std::cout << std::endl;

	// *dog1 = *dog2;
	// std::cout << std::endl;

	// std::cout << dog1->getBrain().getIdea() << std::endl;
	// std::cout << dog2->getBrain().getIdea() << std::endl;
	// std::cout << std::endl;

	// delete dog1;
	// delete dog2;
	// std::cout << std::endl;

	// std::cout << "************* CAT TEST *************" << std::endl;
	// Cat	*cat1 = new Cat();
	// Cat	*cat2 = new Cat("Fish...");
	// std::cout << std::endl;

	// std::cout << cat1->getBrain().getIdea() << std::endl;
	// std::cout << cat2->getBrain().getIdea() << std::endl;
	// std::cout << std::endl;

	// *cat1 = *cat2;
	// std::cout << std::endl;

	// std::cout << cat1->getBrain().getIdea() << std::endl;
	// std::cout << cat2->getBrain().getIdea() << std::endl;
	// std::cout << std::endl;

	// delete cat1;
	// delete cat2;
	// std::cout << std::endl;

	std::cout << "************* MAIN TEST *************" << std::endl;
	Animal	*animals[4];
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		if (i % 2)
			animals[i] = new Dog("BONE!!!");
		else
			animals[i] = new Cat("FISH!!!");
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << i << " animal is " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "************* EVAL TEST *************" << std::endl;
	Dog	basic;
	std::cout << std::endl;
	{
		Dog	tmp = basic;
		std::cout << std::endl;
	}
	// INSTANTIATE TEST
	// Animal	a;
	return 0;
}