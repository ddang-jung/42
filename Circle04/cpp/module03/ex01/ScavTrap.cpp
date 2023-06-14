#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
		: ClapTrap("Scav") {
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << SCAV_CON << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &ref)
		: ClapTrap(ref) {
	std::cout << SCAV_COPY_CON << std::endl;
}
ScavTrap	&ScavTrap::operator=(const ScavTrap &ref) {
	if (this != &ref) {
		_name = ref.getName();
		setHitPoint(ref.getHitPoint());
		setEnergyPoint(ref.getEnergyPoint());
		setAttackDamage(ref.getAttackDamage());
		std::cout << SCAV_COPY_ASN << std::endl;
	}
	return (*this);
}
ScavTrap::~ScavTrap() {
	std::cout << SCAV_DES << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
		: ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << SCAV_STR_CON << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}