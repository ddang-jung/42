#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;

	std::cout << "========================================" << std::endl;
	std::cout << std::endl;

	const WrongAnimal*	w_animal = new WrongAnimal();
	const WrongCat*		w_cat = new WrongCat();
	std::cout << std::endl;

	std::cout << w_animal->getType() << " " << std::endl;
	std::cout << w_cat->getType() << " " << std::endl;
	std::cout << std::endl;

	w_animal->makeSound();
	w_cat->makeSound();
	std::cout << std::endl;

	delete w_animal;
	delete w_cat;
	std::cout << std::endl;

	return 0;
}