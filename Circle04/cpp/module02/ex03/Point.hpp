#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed _y;
	public:
		Point();
		Point(const Point &ref);
		Point	&operator=(const Point &ref);
		~Point();

		Point(const float x, const float y);

		const Fixed getX();
		const Fixed getY();
};

#endif