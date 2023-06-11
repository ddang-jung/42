#include "Fixed.hpp"
#include <iostream>

// OCF
Fixed::Fixed() : _rawBit(0) {
	std::cout << CON << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << COPY_CON << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref) {
	if (this != &ref) {
		std::cout << COPY_ASN << std::endl;
		this->_rawBit = ref.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << DES << std::endl;
}

// ex00
int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits" << MBR << std::endl;
	return (_rawBit);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits" << MBR << std::endl;
	_rawBit = raw;
}