#include "Cat.hpp"
#include <iostream>

// OCF
Cat::Cat() : Animal() {
	std::cout << CAT << CON << std::endl;
	_type = "Cat";
}
Cat::Cat(const Cat &ref) : Animal(ref) {
	std::cout << CAT << COPY_CON << std::endl;
}
Cat	&Cat::operator=(const Cat &ref){
		std::cout << CAT << ASN << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return (*this);
}
Cat::~Cat() {
	std::cout << CAT << DES << std::endl;
}

// MBF
void	Cat::makeSound() const {
	std::cout << _type << ": MEOWWWWWWWWWW!!!" << std::endl;
}