#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void) {
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm		robotomy("Franky");
	PresidentialPardonForm	president("Joe Biden");
	std::cout << std::endl;
	
	{
		std::cout << "====== FORM INFO ======" << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << president << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "====== GUEST TEST ======" << std::endl;
		Bureaucrat	guest("Guest", 140);
		std::cout << guest << std::endl;
		std::cout << std::endl;
		try {
			guest.signForm(shrubbery);
			guest.signForm(robotomy);
			guest.signForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			guest.executeForm(shrubbery);
			guest.executeForm(robotomy);
			guest.executeForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "====== JUNIOR TEST ======" << std::endl;
		Bureaucrat	junior("Junior", 70);
		std::cout << junior << std::endl;
		std::cout << std::endl;
		try {
			junior.signForm(shrubbery);
			junior.signForm(robotomy);
			junior.signForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			junior.executeForm(shrubbery);
			junior.executeForm(robotomy);
			junior.executeForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "====== SENIOR TEST ======" << std::endl;
		Bureaucrat	senior("Senior", 20);
		std::cout << senior << std::endl;
		std::cout << std::endl;
		try {
			senior.signForm(shrubbery);
			senior.signForm(robotomy);
			senior.signForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			senior.executeForm(shrubbery);
			senior.executeForm(robotomy);
			senior.executeForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "====== BOSS TEST ======" << std::endl;
		Bureaucrat	boss("Boss", 1);
		std::cout << boss << std::endl;
		std::cout << std::endl;
		try {
			boss.signForm(shrubbery);
			boss.signForm(robotomy);
			boss.signForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			boss.executeForm(shrubbery);
			boss.executeForm(robotomy);
			boss.executeForm(president);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}