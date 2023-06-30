#include "Dog.hpp"
#include <iostream>

// OCF
Dog::Dog() : Animal() {
	std::cout << DOG << CON << std::endl;
	_type = "Dog";
	_brain = new Brain();
}
Dog::Dog(const Dog &ref) : Animal(ref) {
	std::cout << DOG << COPY_CON << std::endl;
	*this = ref;
}
Dog	&Dog::operator=(const Dog &ref) {
	std::cout << DOG << ASN << std::endl;
	if (this != &ref) {
		this->_type = ref._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(ref._brain->getIdea());
	}
	return (*this);
}
Dog::~Dog() {
	std::cout << DOG << DES << std::endl;
	delete _brain;
}

// STR_CON
Dog::Dog(const std::string &idea) : Animal() {
	std::cout << DOG << STR_CON << std::endl;
	_type = "Dog";
	_brain = new Brain(idea);
}

// GET
const Brain	&Dog::getBrain() const {
	return (*_brain);
}

// MBF
void	Dog::makeSound() const {
	std::cout << _type << ": Wal Wal" << std::endl;
}