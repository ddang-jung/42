#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void) {
	int	option;

	std::srand(time(NULL));
	option = std::rand() % 3;
	if (option == 0)
		return (new A);
	else if (option == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "This one must be A class!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This one must be B class!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This one must be C class!" << std::endl;
	else
		std::cout << "Failed to identify class." << std::endl;
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "This one must be A class!" << std::endl;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "This one must be B class!" << std::endl;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "This one must be C class!" << std::endl;
	}
	catch (std::bad_cast &e) {}
}

int	main(void) {
	Base	*meta;

	meta = generate();
	identify(meta);
	identify(*meta);
	delete	meta;

	return (0);
}