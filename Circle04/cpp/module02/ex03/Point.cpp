#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const Point &ref) {
	*this = ref;
}

Point	&Point::operator=(const Point &ref) {
	if (this != &ref) {
		const_cast<Fixed&>(this->_x) = ref.getX();
		const_cast<Fixed&>(this->_y) = ref.getY();
	}
	return (*this);
}

Point::~Point() {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

const Fixed Point::getX() const {
	return (_x);
}
const Fixed Point::getY() const {
	return (_y);
}