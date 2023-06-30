#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "************* DOG TEST *************" << std::endl;
	Dog	*dog1 = new Dog();
	Dog	*dog2 = new Dog("Bone...");
	Dog	*dog3(dog2);
	std::cout << std::endl;

	std::cout << dog1->getBrain().getIdea() << std::endl;
	std::cout << dog2->getBrain().getIdea() << std::endl;
	std::cout << dog3->getBrain().getIdea() << std::endl;
	std::cout << std::endl;

	*dog1 = *dog2;
	*dog3 = *dog2; // self assignment check
	std::cout << std::endl;

	std::cout << dog1->getBrain().getIdea() << std::endl;
	std::cout << dog2->getBrain().getIdea() << std::endl;
	std::cout << dog3->getBrain().getIdea() << std::endl;
	std::cout << std::endl;

	delete dog1;
	delete dog2;
	// delete dog3; // is double free
	std::cout << std::endl;

	std::cout << "************* CAT TEST *************" << std::endl;
	Cat	*cat1 = new Cat();
	Cat	*cat2 = new Cat("Fish...");
	std::cout << std::endl;

	std::cout << cat1->getBrain().getIdea() << std::endl;
	std::cout << cat2->getBrain().getIdea() << std::endl;
	std::cout << std::endl;

	*cat1 = *cat2;
	std::cout << std::endl;

	std::cout << cat1->getBrain().getIdea() << std::endl;
	std::cout << cat2->getBrain().getIdea() << std::endl;
	std::cout << std::endl;

	delete cat1;
	delete cat2;
	std::cout << std::endl;

	std::cout << "************* MAIN TEST *************" << std::endl;
	Animal	*animals[10];
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Dog("BONE!!!");
		else
			animals[i] = new Cat("FISH!!!");
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << i << " animal is " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << std::endl;

	Dog	basic;
	{
		Dog	tmp = basic;
	}
	system("leaks ex01_");
	return 0;
}