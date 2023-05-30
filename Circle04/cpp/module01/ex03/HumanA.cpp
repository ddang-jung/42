#include "HumanA.hpp"

void	HumanA::attack( void ) {
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon.getType();
	std::cout << std::endl;
}

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon), _name(name) {
	_name = name;
	std::cout << "HumanA Constructor is called" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA Destructor is called" << std::endl;
}
