#include "FragTrap.hpp"
#include <iostream>

void	printStatus(const FragTrap &a) {
	std::cout << "**Status " << a.getName() << " hp:" << a.getHitPoint() << " ep:" << a.getEnergyPoint() << " ad:" << a.getAttackDamage() << std::endl;
}

int	main(void) {
	FragTrap	john("John");
	FragTrap	frag;

	std::cout << std::endl;

	printStatus(john);
	printStatus(frag);
	std::cout << std::endl;

	john.attack("Frag");
	frag.takeDamage(john.getAttackDamage());
	std::cout << std::endl;

	printStatus(john);
	printStatus(frag);
	std::cout << std::endl;

	john.highFivesGuys();
	frag.highFivesGuys();
	std::cout << std::endl;

	frag = john;
	std::cout << std::endl;

	printStatus(john);
	printStatus(frag);
	std::cout << std::endl;
	// TEST
	// ClapTrap	clap;

	// clap.guardGate();
	return (0);
}