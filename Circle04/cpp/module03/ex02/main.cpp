#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	FragTrap	tom("Tom");
	ScavTrap	john("John");
	ClapTrap	foo;

	std::cout << std::endl;

	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	tom.attack("John");
	john.takeDamage(FRAG_AD);
	tom.attack("Foo");
	foo.takeDamage(FRAG_AD);
	std::cout << std::endl;

	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	tom.beRepaired(1);
	john.beRepaired(1);
	foo.beRepaired(1);
	std::cout << std::endl;

	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	tom.highFivesGuys();
	john.guardGate();
	std::cout << std::endl;
	// UNAVILABLE
	// tom.guardGate();
	// john.highFivesGuys();
	// ClapTrap	clap;

	// clap.guardGate();
	return (0);
}