#include "AMateria.hpp"
#include <iostream>

// OCF
AMateria::AMateria(void) : _type("default") {
	// std::cout << AMATERIA << CON << std::endl;
}
AMateria::AMateria(const AMateria &ref) {
	// std::cout << AMATERIA << COPY_CON << std::endl;
	*this = ref;
}
AMateria& AMateria::operator=(AMateria const &ref) {
	// std::cout << AMATERIA << ASN << std::endl;
	if (this != &ref) {
		this->_type = ref._type;
	}
	return (*this);
}
AMateria::~AMateria(void) {
	// std::cout << AMATERIA << DES << std::endl;
}

// STR_CON
AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << AMATERIA << STR_CON << std::endl;
}

// GET
std::string	const & AMateria::getType() const {
	return (_type);
};

// MBF
void	AMateria::use(ICharacter &target) {
	std::cout << "AMateria: " << target.getName() << std::endl;
}