#include "whatever.hpp"
#include <iostream>

int	main(void) {
	int		a = 1, b = 2;
	double	x = 1.123, y = 1.234;

	std::cout << "a: " << a << ", b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min(a,b): " << min(a, b) << std::endl;
	std::cout << "max(a,b): " << max(a, b) << std::endl;

	std::cout << "==================" << std::endl;

	std::cout << "x: " << x << ", y: " << y << std::endl;
	swap(x, y);
	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "min(x,y): " << min(x, y) << std::endl;
	std::cout << "max(x,y): " << max(x, y) << std::endl;

	return (0);
}