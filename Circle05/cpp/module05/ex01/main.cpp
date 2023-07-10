#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	{
		try
		{
			Bureaucrat	john("John", 150);

			std::cout << john;
			john.decreaseGrade();
			std::cout << john;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat	amy("Amy", 10);

			while (true) {
				std::cout << amy;
				amy.increaseGrade();
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat	wrong("Wrong", 200);

			std::cout << wrong;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}