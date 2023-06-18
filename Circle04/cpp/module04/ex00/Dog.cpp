#include "Dog.hpp"
#include <iostream>

// OCF
Dog::Dog() : Animal() {
	std::cout << DOG << CON << std::endl;
	_type = "Dog";
}
Dog::Dog(const Dog &ref) : Animal(ref) {
	std::cout << DOG << COPY_CON << std::endl;
}
Dog	&Dog::operator=(const Dog &ref){
	std::cout << DOG << ASN << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return (*this);
}
Dog::~Dog() {
	std::cout << DOG << DES << std::endl;
}

// MBF
void	Dog::makeSound() const {
	std::cout << _type << ": WUFFFFFFFFFFF!!!" << std::endl;
}