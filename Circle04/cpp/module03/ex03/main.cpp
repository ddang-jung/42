#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	DiamondTrap	amy("Amy");
	FragTrap	tom("Tom");
	ScavTrap	john("John");
	ClapTrap	foo;

	std::cout << std::endl;

	amy.printStatus();
	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	amy.attack("Tom");
	tom.takeDamage(FRAG_AD);
	amy.attack("John");
	john.takeDamage(FRAG_AD);
	amy.attack("Foo");
	foo.takeDamage(FRAG_AD);
	std::cout << std::endl;

	amy.printStatus();
	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	amy.beRepaired(1);
	tom.beRepaired(1);
	john.beRepaired(1);
	foo.beRepaired(1);
	std::cout << std::endl;

	amy.printStatus();
	tom.printStatus();
	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	amy.whoAmI();
	amy.highFivesGuys();
	amy.guardGate();
	tom.highFivesGuys();
	john.guardGate();
	std::cout << std::endl;

	return (0);
}