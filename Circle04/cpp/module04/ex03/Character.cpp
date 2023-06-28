#include "Character.hpp"
#include <iostream>

// OCF
Character::Character(void) : _name("Default") {
	// std::cout << CHARACTER << CON << std::endl;
	for (int i = 0; i < SIZE; i++)
		_inventory[i] = NULL;
}
Character::Character(const Character &ref) {
	// std::cout << CHARACTER << COPY_CON << std::endl;
	*this = ref;
}
Character& Character::operator=(Character const &ref) {
	// std::cout << CHARACTER << ASN << std::endl;
	if (this != &ref) {
		for (int i = 0; i < SIZE; i++) {
			if (this->_inventory[i])
				delete _inventory[i];
			if (ref._inventory[i])
				this->_inventory[i] = ref._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}
Character::~Character(void) {
	// std::cout << CHARACTER << DES << std::endl;
	for (int i = 0; i < SIZE; i++)
		if (_inventory[i])
			delete _inventory[i];
}

// STR_CON
Character::Character(const std::string &name) : _name(name) {
	// std::cout << CHARACTER << CON << std::endl;
	for (int i = 0; i < SIZE; i++)
		_inventory[i] = NULL;
}

// GET
std::string const	& Character::getName() const {
	return (_name);
}

// MBF
void				Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			// std::cout << _name << " equiped " << m->getType() << std::endl;
			return ;
		}
	}
	delete m;
}
void				Character::unequip(int idx) {
	if (idx < 0 || idx >= SIZE)
		return ;
	if (_inventory[idx]) {
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}
void				Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < SIZE && _inventory[idx])
		_inventory[idx]->use(target);
}