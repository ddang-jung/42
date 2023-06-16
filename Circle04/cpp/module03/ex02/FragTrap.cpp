#include "FragTrap.hpp"
#include <iostream>

// OCF
FragTrap::FragTrap()
		: ClapTrap() {
	std::cout << FRAG_CON << std::endl;
	_class = "FragTrap";
	_name = "Foo";
	_hp = FRAG_HP;
	_ep = FRAG_EP;
	_ad = FRAG_AD;
}
FragTrap::FragTrap(const std::string &name)
		: ClapTrap(name) {
	std::cout << FRAG_STR_CON << std::endl;
	_class = "FragTrap";
	_name = name;
	_hp = FRAG_HP;
	_ep = FRAG_EP;
	_ad = FRAG_AD;
}
FragTrap::FragTrap(const FragTrap &ref)
		: ClapTrap(ref) {
	std::cout << FRAG_COPY_CON << std::endl;
	if (this != &ref)
		*this = ref;
}
FragTrap	&FragTrap::operator=(const FragTrap &ref) {
	if (this != &ref) {
		std::cout << FRAG_COPY_ASN << std::endl;
		this->_name = ref._name;
		this->_hp = ref._hp;
		this->_ep = ref._ep;
		this->_ad = ref._ad;
	}
	return (*this);
}
FragTrap::~FragTrap() {
	std::cout << FRAG_DES << std::endl;
}

// ACT
void	FragTrap::highFivesGuys(void) {
	std::cout << _class << " " << _name << " high fives!" << std::endl;
}