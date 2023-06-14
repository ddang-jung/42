#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	DiamondTrap	john("John");
	DiamondTrap	dia;

	std::cout << std::endl;

	john.printStatus();
	dia.printStatus();
	std::cout << std::endl;

	john.attack("Diamond");
	dia.takeDamage(john.getAttackDamage());
	std::cout << std::endl;

	john.printStatus();
	dia.printStatus();
	std::cout << std::endl;

	john.guardGate();
	dia.guardGate();
	std::cout << std::endl;

	john.highFivesGuys();
	dia.highFivesGuys();
	std::cout << std::endl;

	john.whoAmI();
	dia.whoAmI();
	std::cout << std::endl;

	dia = john;
	std::cout << std::endl;

	john.printStatus();
	dia.printStatus();
	std::cout << std::endl;
	// TEST
	// ClapTrap	clap;

	// clap.guardGate();
	return (0);
}