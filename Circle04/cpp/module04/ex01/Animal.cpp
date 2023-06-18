#include "Animal.hpp"
#include <iostream>

// OCF
Animal::Animal() : _type("Animal") {
	std::cout << ANIMAL << CON << std::endl;
}
Animal::Animal(const Animal &ref) : _type(ref._type) {
	std::cout << ANIMAL << COPY_CON << std::endl;
}
Animal	&Animal::operator=(const Animal &ref){
	std::cout << ANIMAL << ASN << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return (*this);
}
Animal::~Animal() {
	std::cout << ANIMAL << DES << std::endl;
}

// GET
const std::string	&Animal::getType() const {
	return (this->_type);
}

// MBF
void	Animal::makeSound() const {
	std::cout << this->_type << ": Hmm.. Sound?" << std::endl;
}