#include "ScavTrap.hpp"
#include <iostream>

void	printStatus(const ScavTrap &a) {
	std::cout << "**Status " << a.getName() << " hp:" << a.getHitPoint() << " ep:" << a.getEnergyPoint() << " ad:" << a.getAttackDamage() << std::endl;
}

int	main(void) {
	ScavTrap	john("John");
	ScavTrap	scav;

	std::cout << std::endl;

	printStatus(john);
	printStatus(scav);
	std::cout << std::endl;

	john.attack("Scav");
	scav.takeDamage(john.getAttackDamage());
	std::cout << std::endl;

	printStatus(john);
	printStatus(scav);
	std::cout << std::endl;

	john.guardGate();
	scav.guardGate();
	std::cout << std::endl;

	scav = john;
	std::cout << std::endl;

	printStatus(john);
	printStatus(scav);
	std::cout << std::endl;
	// TEST
	// ClapTrap	clap;

	// clap.guardGate();
	return (0);
}