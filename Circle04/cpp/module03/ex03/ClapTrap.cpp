#include "ClapTrap.hpp"
#include <iostream>

// OCF
ClapTrap::ClapTrap() {
	setName("Foo");
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << CLAP_CON << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) {
	setName(name);
	initHitPoint();
	initEnergyPoint();
	initAttackDamage();
	std::cout << CLAP_STR_CON << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &ref) {
	*this = ref;
	std::cout << CLAP_COPY_CON << std::endl;
}
ClapTrap	&ClapTrap::operator=(const ClapTrap &ref) {
	if (this != &ref) {
		setName(ref.getName());
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

// GET / SET
const std::string	&ClapTrap::getName() const {
	return (_name);
}
const unsigned int	&ClapTrap::getHitPoint() const {
	return (_hp);
}
const unsigned int	&ClapTrap::getEnergyPoint() const {
	return (_ep);
}
const unsigned int	&ClapTrap::getAttackDamage() const {
	return (_ad);
}
void				ClapTrap::setName(const std::string &name) {
	_name = name;
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

// INIT
void	ClapTrap::initHitPoint() {
	setHitPoint(CLAP_HP);
}
void	ClapTrap::initEnergyPoint() {
	setEnergyPoint(CLAP_EP);
}
void	ClapTrap::initAttackDamage() {
	setAttackDamage(CLAP_AD);
}

// ACT
void	ClapTrap::attack(const std::string &target) {
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
void	ClapTrap::takeDamage(unsigned int amount) {
	if (getHitPoint() > 0) {
		std::cout << "ClapTrap " << getName() << " took " << amount << " points of damage! now hit point is ";
		if (getHitPoint() > amount) {
			std::cout << (getHitPoint() - amount) << "." << std::endl;
			setHitPoint(getHitPoint() - amount);
		}
		else {
			std::cout << "0.. he's dead.." << std::endl;
			setHitPoint(0);
		}
	} else {
		std::cout << "ClapTrap " << getName() << " is already dead.. please stop.." << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoint() == 0 || getHitPoint() == 0) {
		if (getEnergyPoint() == 0)
			std::cout << "ClapTrap " << getName() << " failed to repair (has no energy..)" << std::endl;
		if (getHitPoint() == 0)
			std::cout << "ClapTrap " << getName() << " failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "ClapTrap " << getName() << " repaired " << amount << std::endl;
		setHitPoint(getHitPoint() + amount);
		setEnergyPoint(getEnergyPoint() - 1);
	}
}
void	ClapTrap::printStatus() {
	std::cout << "**Status " << getName() << " hp:" << getHitPoint() << " ep:" << getEnergyPoint() << " ad:" << getAttackDamage() << std::endl;
}