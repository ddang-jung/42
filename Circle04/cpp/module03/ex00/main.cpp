#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	john("John");
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

	john.setAttackDamage(2);
	john.attack("Foo");
	foo.takeDamage(john.getAttackDamage());
	std::cout << std::endl;

	john.printStatus();
	foo.printStatus();
	std::cout << std::endl;

	foo.beRepaired(1);
	foo.printStatus();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		john.attack("Foo");
		foo.takeDamage(john.getAttackDamage());
		std::cout << std::endl;
	}
	foo.beRepaired(100);
	foo.printStatus();
	std::cout << std::endl;

	return (0);
}