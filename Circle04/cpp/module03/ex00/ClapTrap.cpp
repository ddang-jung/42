#include "ClapTrap.hpp"
#include <iostream>

// OCF
ClapTrap::ClapTrap() : _name("Foo"), _hp(CLAP_HP), _ep(CLAP_EP), _ad(CLAP_AD) {
	std::cout << CLAP_CON << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(CLAP_HP), _ep(CLAP_EP), _ad(CLAP_AD) {
	std::cout << CLAP_STR_CON << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &ref) {
	std::cout << CLAP_COPY_CON << std::endl;
	*this = ref;
}
ClapTrap	&ClapTrap::operator=(const ClapTrap &ref) {
	if (this != &ref) {
		std::cout << CLAP_COPY_ASN << std::endl;
		this->_name = ref._name;
		this->_hp = ref._hp;
		this->_ep = ref._ep;
		this->_ad = ref._ad;
	}
	return (*this);
}
ClapTrap::~ClapTrap() {
	std::cout << CLAP_DES << std::endl;
}

// ACT
void	ClapTrap::attack(const std::string &target) {
	if (_ep == 0 || _hp == 0) {
		if (_ep == 0)
			std::cout << "ClapTrap " << _name << " failed to attack (has no energy..)" << std::endl;
		if (_hp == 0)
			std::cout << "ClapTrap " << _name << " failed to attack (has no hit point..)" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " attacks " << target;
		if (_ad == 0)
			std::cout <<", but it was in vain.." << std::endl;
		else
			std::cout << ", causing " << _ad << " points of damage!" << std::endl;
		_ep -= 1;
	}
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hp > 0) {
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage! now hit point is ";
		if (_hp > amount) {
			std::cout << (_hp - amount) << "." << std::endl;
			_hp -= amount;
		}
		else {
			std::cout << "0.. he's dead.." << std::endl;
			_hp = 0;
		}
	} else {
		std::cout << "ClapTrap " << _name << " is already dead.. please stop.." << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (_ep == 0 || _hp == 0) {
		if (_ep == 0)
			std::cout << "ClapTrap " << _name << " failed to repair (has no energy..)" << std::endl;
		if (_hp == 0)
			std::cout << "ClapTrap " << _name << " failed to repair (has no hit point..)" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " repaired " << amount << std::endl;
		_hp += amount;
		_ep -= 1;
	}
}
void	ClapTrap::printStatus() {
	std::cout << "**Status " << _name << " hp:" << _hp << " ep:" << _ep << " ad:" << _ad << std::endl;
}