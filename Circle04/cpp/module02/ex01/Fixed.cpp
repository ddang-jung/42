#include "Fixed.hpp"
#include <cmath>

// OCF
Fixed::Fixed() : _rawBit(0) {
	std::cout << CON << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << COPY_CON << std::endl;
	*this = ref;
}

Fixed	&Fixed::operator=(const Fixed &ref) {
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
	// std::cout << "getRawBits" << MBR << std::endl;
	return (_rawBit);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits" << MBR << std::endl;
	_rawBit = raw;
}

// ex01
Fixed::Fixed(const int value) {
	std::cout << INT_CON << std::endl;
	_rawBit = value << _fracBit;
}

Fixed::Fixed(const float value) {
	std::cout << FLOAT_CON << std::endl;
	_rawBit = roundf(value * (1 << _fracBit));
}

float	Fixed::toFloat( void ) const {
	return ((float)_rawBit / (1 << _fracBit));
}

int		Fixed::toInt( void ) const {
	return (_rawBit >> _fracBit);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &ref) {
	os << ref.toFloat();
	return (os);
}