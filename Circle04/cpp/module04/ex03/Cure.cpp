#include "Cure.hpp"
#include <iostream>

// OCF
Cure::Cure(void) : AMateria("cure") {
	// std::cout << CURE << CON << std::endl;
}
Cure::Cure(const Cure &ref) : AMateria(ref) {
	// std::cout << CURE << COPY_CON << std::endl;
	*this = ref;
}
Cure& Cure::operator=(Cure const &ref) {
	// std::cout << CURE << ASN << std::endl;
	if (this != &ref) {
		this->_type = ref.getType();
	}
	return (*this);
}
Cure::~Cure(void) {
	// std::cout << CURE << DES << std::endl;
}

// MBF
AMateria*	Cure::clone() const {
	// std::cout << CURE << CLONE << std::endl;
	return (new Cure);
}
void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}