#include "Fixed.hpp"
#include <cmath>

// OCF
Fixed::Fixed() : _rawBit(0) {
}

Fixed::Fixed(const Fixed &ref) {
	*this = ref;
}

Fixed	&Fixed::operator=(const Fixed &ref) {
	this->_rawBit = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
}

// ex00
int		Fixed::getRawBits( void ) const {
	return (_rawBit);
}

void	Fixed::setRawBits( int const raw ) {
	_rawBit = raw;
}

// ex01
Fixed::Fixed(const int value) {
	_rawBit = value << _fracBit;
}

Fixed::Fixed(const float value) {
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

// ex02
bool	Fixed::operator>(const Fixed &ref) {
	return (getRawBits() > ref.getRawBits());
}
bool	Fixed::operator<(const Fixed &ref) {
	return (getRawBits() < ref.getRawBits());
}
bool	Fixed::operator>=(const Fixed &ref) {
	return (getRawBits() >= ref.getRawBits());
}
bool	Fixed::operator<=(const Fixed &ref) {
	return (getRawBits() <= ref.getRawBits());
}
bool	Fixed::operator==(const Fixed &ref) {
	return (getRawBits() == ref.getRawBits());
}
bool	Fixed::operator!=(const Fixed &ref) {
	return (getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &ref) {
	return (Fixed(toFloat() + ref.toFloat()));
}
Fixed	Fixed::operator-(const Fixed &ref) {
	return (Fixed(toFloat() - ref.toFloat()));
}
Fixed	Fixed::operator*(const Fixed &ref) {
	return (Fixed(toFloat() * ref.toFloat()));
}
Fixed	Fixed::operator/(const Fixed &ref) {
	return (Fixed(toFloat() / ref.toFloat()));
}

Fixed	&Fixed::operator++(void) {
	this->_rawBit++;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->_rawBit++;
	return (tmp);
}
Fixed	&Fixed::operator--(void) {
	this->_rawBit--;
	return (*this);
}
Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->_rawBit--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs) {
	return (lhs > rhs ? rhs : lhs);
}
const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return (lhs > rhs ? rhs : lhs);
}
Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs) {
	return (lhs > rhs ? lhs : rhs);
}
const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return (lhs > rhs ? lhs : rhs);
}