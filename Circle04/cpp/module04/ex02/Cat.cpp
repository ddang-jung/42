#include "Cat.hpp"
#include <iostream>

// OCF
Cat::Cat() : Animal() {
	std::cout << CAT << CON << std::endl;
	_type = "Cat";
	_brain = new Brain();
}
Cat::Cat(const Cat &ref) : Animal(ref) {
	std::cout << CAT << COPY_CON << std::endl;
	this->_brain = new Brain(*ref._brain);
}
Cat	&Cat::operator=(const Cat &ref) {
	std::cout << CAT << ASN << std::endl;
	if (this != &ref) {
		this->_type = ref._type;
		*this->_brain = *ref._brain;
	}
	return (*this);
}
Cat::~Cat() {
	std::cout << CAT << DES << std::endl;
	delete _brain;
}

// STR_CON
Cat::Cat(const std::string &idea) : Animal() {
	std::cout << CAT << STR_CON << std::endl;
	_type = "Cat";
	_brain = new Brain(idea);
}

// GET
const Brain	&Cat::getBrain() const {
	return (*_brain);
}

// MBF
void	Cat::makeSound() const {
	std::cout << _type << ": Yaong Yaong" << std::endl;
}