#include "Point.hpp"
#include <iostream>

void	doBspAndPrint(const Point &a, const Point &b, const Point &c, const Point &p) {
	bool	ret;

	ret = bsp(a, b, c, p);
	if (ret)
		std::cout << "The point is **inside** the triangle" << std::endl;
	else
		std::cout << "The point is **outside** the triangle" << std::endl;
}

int main( void ) {
	Point	a(0, 0);
	Point	b(10.0, 0.0);
	Point	c(0.0, 10.0);

	// inside
	Point	p1(0.1, 0.1);
	doBspAndPrint(a, b, c, p1);
	// edge
	Point	p2(0.0, 0.0);
	doBspAndPrint(a, b, c, p2);
	// outside
	Point	p3(10.0, 10.0);
	doBspAndPrint(a, b, c, p3);
	
	return (0);
}