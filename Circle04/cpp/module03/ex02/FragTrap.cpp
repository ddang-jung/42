#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
		: ClapTrap() {
	_name = "Frag";
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << FRAG_CON << std::endl;
}
FragTrap::FragTrap(const FragTrap &ref)
		: ClapTrap(ref) {
	std::cout << FRAG_COPY_CON << std::endl;
}
FragTrap	&FragTrap::operator=(const FragTrap &ref) {
	if (this != &ref) {
		_name = ref.getName();
		setHitPoint(ref.getHitPoint());
		setEnergyPoint(ref.getEnergyPoint());
		setAttackDamage(ref.getAttackDamage());
		std::cout << FRAG_COPY_ASN << std::endl;
	}
	return (*this);
}
FragTrap::~FragTrap() {
	std::cout << FRAG_DES << std::endl;
}

FragTrap::FragTrap(const std::string &name)
		: ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << FRAG_STR_CON << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "FragTrap " << getName() << " failed to attack (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "FragTrap " << getName() << " failed to attack (has no hit point..)" << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " attacks " << target;
		if (getAttackDamage() == 0)
			std::cout <<", but it was in vain.." << std::endl;
		else
			std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	FragTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() > 0) {
		std::cout << "FragTrap " << getName() << " took " << amount << " points of damage! now hit point is ";
		if (getHitPoint() > amount) {
			std::cout << (getHitPoint() - amount) << "." << std::endl;
			setHitPoint(getHitPoint() - amount);
		}
		else {
			std::cout << "0.. his dead.." << std::endl;
			setHitPoint(0);
		}
	} else {
		std::cout << "FragTrap " << getName() << " is already dead.. please stop.." << std::endl;
	}
}
void	FragTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "FragTrap " << getName() << "failed to repair (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "FragTrap " << getName() << "failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " repaired " << amount << std::endl;
		setHitPoint(getHitPoint() + amount);
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " high fives!" << std::endl;
}