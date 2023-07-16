#include "Intern.hpp"
#include <iostream>

int	main(void) {
	Intern		intern;
	AForm		*form;
	Bureaucrat	senior("Senior", 20);

	std::cout << "====== ROBOTOMY TEST ======"<< std::endl;
	try
	{
		form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;

		senior.signForm(*form);
		senior.executeForm(*form);

		delete	form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "====== NOEXIST TEST ======"<< std::endl;
	try
	{
		form = intern.makeForm("noexist form", "???");
		std::cout << *form << std::endl;

		senior.signForm(*form);
		senior.executeForm(*form);

		delete	form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}