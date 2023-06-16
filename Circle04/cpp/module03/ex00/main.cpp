#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	john("John");
	ClapTrap	foo;

	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	john.attack("somebody");
	foo.attack("somebody");
	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	john.takeDamage(2);
	foo.takeDamage(2);
	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	john.beRepaired(1);
	foo.beRepaired(1);
	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
		foo.takeDamage(2);
	foo.beRepaired(100);
	foo.printStatus();
	std::cout << std::endl;

	return (0);
}