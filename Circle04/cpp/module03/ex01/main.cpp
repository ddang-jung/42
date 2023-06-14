#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap	john("John");
	ClapTrap	foo;

	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	john.attack("Foo");
	foo.takeDamage(john.getAttackDamage());
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

	john.guardGate();
	std::cout << std::endl;
	// UNAVILABLE
	// ClapTrap	clap;

	// clap.guardGate();
	return (0);
}