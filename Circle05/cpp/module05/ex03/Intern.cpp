#include "Intern.hpp"
#include <iostream>

// OCF
Intern::Intern(void) {
}
Intern::Intern(const Intern &ref) {
	(void)ref;
}
Intern& Intern::operator=(Intern const &ref) {
	(void)ref;
	return (*this);
}
Intern::~Intern(void) {
}

// NEW
AForm	*Intern::newShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}
AForm	*Intern::newRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}
AForm	*Intern::newPresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

// MBF
AForm	*Intern::makeForm(const std::string &form_name, const std::string &target_name) {
	std::string	arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*ptr[3])(const std::string &target) = {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (form_name == arr[i]) {
			std::cout << "Intern made " << arr[i] << " successfully." << std::endl;
			return (ptr[i](target_name));
		}
	}
	throw Intern::noExistFormException();
	return (NULL);
}

// EXC
const char	*Intern::noExistFormException::what() const throw() {
	return ("Intern doesn't know how to make this form...");
}