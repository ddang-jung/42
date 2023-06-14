#include "ScavTrap.hpp"
#include <iostream>

// OCF
ScavTrap::ScavTrap()
		: ClapTrap() {
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << SCAV_CON << std::endl;
}
ScavTrap::ScavTrap(const std::string &name)
		: ClapTrap(name) {
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << SCAV_STR_CON << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &ref)
		: ClapTrap(ref) {
	if (this != &ref)
		*this = ref;
	std::cout << SCAV_COPY_CON << std::endl;
}
ScavTrap	&ScavTrap::operator=(const ScavTrap &ref) {
	if (this != &ref) {
		setName(ref.getName());
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

// INIT
void	ScavTrap::initHitPoint(void) {
	setHitPoint(SCAV_HP);
}
void	ScavTrap::initEnergyPoint(void) {
	setEnergyPoint(SCAV_EP);
}
void	ScavTrap::initAttackDamage(void) {
	setAttackDamage(SCAV_AD);
}

// ACT
void	ScavTrap::attack(const std::string &target) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "ScavTrap " << getName() << " failed to attack (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "ScavTrap " << getName() << " failed to attack (has no hit point..)" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " attacks " << target;
		if (getAttackDamage() == 0)
			std::cout <<", but it was in vain.." << std::endl;
		else
			std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	ScavTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() > 0) {
		std::cout << "ScavTrap " << getName() << " took " << amount << " points of damage! now hit point is ";
		if (getHitPoint() > amount) {
			std::cout << (getHitPoint() - amount) << "." << std::endl;
			setHitPoint(getHitPoint() - amount);
		}
		else {
			std::cout << "0.. he's dead.." << std::endl;
			setHitPoint(0);
		}
	} else {
		std::cout << "ScavTrap " << getName() << " is already dead.. please stop.." << std::endl;
	}
}
void	ScavTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "ScavTrap " << getName() << "failed to repair (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "ScavTrap " << getName() << "failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " repaired " << amount << std::endl;
		setHitPoint(getHitPoint() + amount);
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode." << std::endl;
}