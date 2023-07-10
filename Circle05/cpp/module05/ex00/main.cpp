#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	{
		try
		{
			Bureaucrat	john("John", 150);

			std::cout << john << std::endl;
			john.decreaseGrade();
			std::cout << john << std::endl;
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
				std::cout << amy << std::endl;
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

			std::cout << wrong << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}