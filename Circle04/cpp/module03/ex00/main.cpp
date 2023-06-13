#include "ClapTrap.hpp"
#include <iostream>

void	printStatus(const ClapTrap &a) {
	std::cout << "**Status " << a.getName() << " hp:" << a.getHitPoint() << " ep:" << a.getEnergyPoint() << " ad:" << a.getAttackDamage() << std::endl;
}

int	main(void) {
	ClapTrap	john("John");
	ClapTrap	nomad;

	std::cout << std::endl;

	printStatus(john);
	printStatus(nomad);
	std::cout << std::endl;

	john.attack("nomad");
	nomad.takeDamage(john.getAttackDamage());
	printStatus(john);
	printStatus(nomad);
	std::cout << std::endl;

	john.setAttackDamage(2);
	john.attack("nomad");
	nomad.takeDamage(john.getAttackDamage());
	printStatus(john);
	printStatus(nomad);
	std::cout << std::endl;

	nomad.beRepaired(1);
	printStatus(nomad);
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		john.attack("nomad");
	for (int i = 0; i < 10; i++)
		nomad.takeDamage(john.getAttackDamage());

	return (0);
}