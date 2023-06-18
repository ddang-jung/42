#include "WrongCat.hpp"
#include <iostream>

// OCF
WrongCat::WrongCat() : WrongAnimal() {
	std::cout << WRONG_CAT << CON << std::endl;
	_type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal(ref) {
	std::cout << WRONG_CAT << COPY_CON << std::endl;
}
WrongCat	&WrongCat::operator=(const WrongCat &ref){
		std::cout << WRONG_CAT << ASN << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return (*this);
}
WrongCat::~WrongCat() {
	std::cout << WRONG_CAT << DES << std::endl;
}

// MBF
void	WrongCat::makeSound() const {
	std::cout << _type << ": Meow???" << std::endl;
}