#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _hp(10), _ep(10), _ad(0), _name("Clap") {
	std::cout << CLAP_CON << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &ref) {
	*this = ref;
	std::cout << CLAP_COPY_CON << std::endl;
}
ClapTrap	&ClapTrap::operator=(const ClapTrap &ref) {
	if (this != &ref) {
		_name = ref.getName();
		setHitPoint(ref.getHitPoint());
		setEnergyPoint(ref.getEnergyPoint());
		setAttackDamage(ref.getAttackDamage());
		std::cout << CLAP_COPY_ASN << std::endl;
	}
	return (*this);
}
ClapTrap::~ClapTrap() {
	std::cout << CLAP_DES << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _hp(10), _ep(10), _ad(0), _name(name) {
	std::cout << CLAP_STR_CON << std::endl;
}

const std::string	&ClapTrap::getName() const {
	return (_name);
}
unsigned int		ClapTrap::getHitPoint() const {
	return (_hp);
}
unsigned int		ClapTrap::getEnergyPoint() const {
	return (_ep);
}
unsigned int		ClapTrap::getAttackDamage() const {
	return (_ad);
}
void				ClapTrap::setHitPoint(unsigned int hp) {
	_hp = hp;
}
void				ClapTrap::setEnergyPoint(unsigned int ep) {
	_ep = ep;
}
void				ClapTrap::setAttackDamage(unsigned int ad) {
	_ad = ad;
}

void				ClapTrap::attack(const std::string &target) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "ClapTrap " << getName() << " failed to attack (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "ClapTrap " << getName() << " failed to attack (has no hit point..)" << std::endl;
	} else {
		std::cout << "ClapTrap " << getName() << " attacks " << target;
		if (getAttackDamage() == 0)
			std::cout <<", but it was in vain.." << std::endl;
		else
			std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void				ClapTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() > 0) {
		std::cout << "ClapTrap " << getName() << " took " << amount << " points of damage! now hit point is ";
		if (getHitPoint() > amount) {
			std::cout << (getHitPoint() - amount) << "." << std::endl;
			setHitPoint(getHitPoint() - amount);
		}
		else {
			std::cout << "0.. his dead.." << std::endl;
			setHitPoint(0);
		}
	} else {
		std::cout << "ClapTrap " << getName() << " is already dead.. please stop.." << std::endl;
	}
}
void				ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "ClapTrap " << getName() << "failed to repair (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "ClapTrap " << getName() << "failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "ClapTrap " << getName() << " repaired " << amount << std::endl;
		setHitPoint(getHitPoint() + amount);
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
