#include "DiamondTrap.hpp"
#include <iostream>

// OCF
DiamondTrap::DiamondTrap()
		: FragTrap(), ScavTrap() {
	std::cout << DIA_CON << std::endl;
	_class = "DiamondTrap";
	_name = "Dia";
	_hp = FRAG_HP;
	_ep = SCAV_EP;
	_ad = FRAG_AD;
}
DiamondTrap::DiamondTrap(const std::string &name)
		: FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") {
	std::cout << DIA_STR_CON << std::endl;
	_class = "DiamondTrap";
	_name = name;
	_hp = FRAG_HP;
	_ep = SCAV_EP;
	_ad = FRAG_AD;
}
DiamondTrap::DiamondTrap(const DiamondTrap &ref)
		: FragTrap(ref), ScavTrap(ref) {
	std::cout << DIA_COPY_CON << std::endl;
	*this = ref;
}
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref) {
	if (this != &ref) {
		std::cout << DIA_COPY_ASN << std::endl;
		this->_name = ref._name;
		this->_hp = ref._hp;
		this->_ep = ref._ep;
		this->_ad = ref._ad;
	}
	return (*this);
}
DiamondTrap::~DiamondTrap() {
	std::cout << DIA_DES << std::endl;
}

// ACT
void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI() {
	std::cout << _class << " Who am I(" << _name << ") ClapTrap name(" << ClapTrap::_name << ")" << std::endl;
}
void	DiamondTrap::printStatus() {
	std::cout << "**Status " << _name << " hp:" << _hp << " ep:" << _ep << " ad:" << _ad << std::endl;
}