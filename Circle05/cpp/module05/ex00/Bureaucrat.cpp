#include "Bureaucrat.hpp"
#include <iostream>

// OCF
Bureaucrat::Bureaucrat(void) {
	std::cout << BUREAUCRAT << CON << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref) {
	std::cout << BUREAUCRAT << COPY_CON << std::endl;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &ref) {
	std::cout << BUREAUCRAT << ASN << std::endl;
	if (this != &ref) {
	}
	return (*this);
}
Bureaucrat::~Bureaucrat(void) {
	std::cout << BUREAUCRAT << DES << std::endl;
}