#include "ScavTrap.hpp"
#include <iostream>

// OCF
ScavTrap::ScavTrap()
		: ClapTrap() {
	std::cout << SCAV_CON << std::endl;
	_class = "ScavTrap";
	_name = "Foo";
	_hp = SCAV_HP;
	_ep = SCAV_EP;
	_ad = SCAV_AD;
}
ScavTrap::ScavTrap(const std::string &name)
		: ClapTrap(name) {
	std::cout << SCAV_STR_CON << std::endl;
	_class = "ScavTrap";
	_name = name;
	_hp = SCAV_HP;
	_ep = SCAV_EP;
	_ad = SCAV_AD;
}
ScavTrap::ScavTrap(const ScavTrap &ref)
		: ClapTrap(ref) {
	std::cout << SCAV_COPY_CON << std::endl;
	if (this != &ref)
		*this = ref;
}
ScavTrap	&ScavTrap::operator=(const ScavTrap &ref) {
	if (this != &ref) {
		std::cout << SCAV_COPY_ASN << std::endl;
		this->_name = ref._name;
		this->_hp = ref._hp;
		this->_ep = ref._ep;
		this->_ad = ref._ad;
	}
	return (*this);
}
ScavTrap::~ScavTrap() {
	std::cout << SCAV_DES << std::endl;
}

// ACT
void	ScavTrap::guardGate() {
	std::cout << _class << " " << _name << " is now in Gatekeeper mode." << std::endl;
}
// void	ScavTrap::attack(const std::string& target) {
// 	(void)target;
// 	std::cout << "hello I'm ScavTrap's attack!" << std::endl;
// }