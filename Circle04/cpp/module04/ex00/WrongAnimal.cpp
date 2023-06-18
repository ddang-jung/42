#include "WrongAnimal.hpp"
#include <iostream>

// OCF
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << WRONG_ANIMAL << CON << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &ref) : _type(ref._type) {
	std::cout << WRONG_ANIMAL << COPY_CON << std::endl;
	*this = ref;
}
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref){
		std::cout << WRONG_ANIMAL << ASN << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return (*this);
}
WrongAnimal::~WrongAnimal() {
	std::cout << WRONG_ANIMAL << DES << std::endl;
}

// GET
const std::string	&WrongAnimal::getType() const {
	return (this->_type);
}

// MBF
void	WrongAnimal::makeSound() const {
	std::cout << _type << ": Animal???" << std::endl;
}