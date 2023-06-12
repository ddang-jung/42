#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const Point &ref) {
	*this = ref;
}

Point	&Point::operator=(const Point &ref) {
	if (this != &ref) {
		this->_x = ref.getX();
		this->_y = ref.getY();
	}
	return (*this);
}

Point::~Point() {
}

Point::Point(const float x, const float y) {
}