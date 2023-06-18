#include "Ice.hpp"
#include <iostream>

// OCF
Ice::Ice(void) : AMateria("ice") {
	// std::cout << ICE << CON << std::endl;
}
Ice::Ice(const Ice &ref) : AMateria(ref) {
	// std::cout << ICE << COPY_CON << std::endl;
	*this = ref;
}
Ice& Ice::operator=(Ice const &ref) {
	// std::cout << ICE << ASN << std::endl;
	if (this != &ref) {
		this->_type = ref.getType();
	}
	return (*this);
}
Ice::~Ice(void) {
	// std::cout << ICE << DES << std::endl;
}

// MBF
AMateria*	Ice::clone() const {
	// std::cout << ICE << CLONE << std::endl;
	return (new Ice);
}
void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}