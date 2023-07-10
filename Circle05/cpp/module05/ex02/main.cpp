#include "Form.hpp"
#include <iostream>

int	main(void) {
	try
	{
		Form	a("A", 0, 75);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form	b("B", 75, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	{
		Form		doc("Document", 75, 75);
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	intern("Intern", 150);
		std::cout << std::endl;

		boss.signForm(doc);
		intern.signForm(doc);
		std::cout << std::endl;
	}
	return (0);
}