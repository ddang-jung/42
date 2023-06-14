#include "DiamondTrap.hpp"
#include <iostream>

// OCF
DiamondTrap::DiamondTrap()
		: FragTrap(), ScavTrap() {
	_name = "Diamond";
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << DIA_CON << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name)
		: ClapTrap(name + "_clap_name"), FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_name") {
	_name = name;
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << DIA_STR_CON << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &ref)
		: ClapTrap(ref), FragTrap(ref), ScavTrap(ref) {
	*this = ref;
	std::cout << DIA_COPY_CON << std::endl;
}
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref) {
	if (this != &ref) {
		_name = ref._name;
		setHitPoint(ref.getHitPoint());
		setEnergyPoint(ref.getEnergyPoint());
		setAttackDamage(ref.getAttackDamage());
		std::cout << DIA_COPY_ASN << std::endl;
	}
	return (*this);
}
DiamondTrap::~DiamondTrap() {
	std::cout << DIA_DES << std::endl;
}

// INIT
void	DiamondTrap::initHitPoint(void) {
	FragTrap::initHitPoint();
}
void	DiamondTrap::initEnergyPoint(void) {
	ScavTrap::initEnergyPoint();
}
void	DiamondTrap::initAttackDamage(void) {
	FragTrap::initAttackDamage();
}

// ACT
void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
void	DiamondTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() > 0) {
		std::cout << "DiamondTrap " << _name << " took " << amount << " points of damage! now hit point is ";
		if (getHitPoint() > amount) {
			std::cout << (getHitPoint() - amount) << "." << std::endl;
			setHitPoint(getHitPoint() - amount);
		}
		else {
			std::cout << "0.. he's dead.." << std::endl;
			setHitPoint(0);
		}
	} else {
		std::cout << "DiamondTrap " << _name << " is already dead.. please stop.." << std::endl;
	}
}
void	DiamondTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "DiamondTrap " << _name << "failed to repair (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "DiamondTrap " << _name << "failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "DiamondTrap " << _name << " repaired " << amount << std::endl;
		setHitPoint(getHitPoint() + amount);
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << " // ClapTrap name: " << getName() << std::endl;
}
void	DiamondTrap::printStatus() {
	std::cout << "**Status " << _name << " hp:" << getHitPoint() << " ep:" << getEnergyPoint() << " ad:" << getAttackDamage() << std::endl;
}