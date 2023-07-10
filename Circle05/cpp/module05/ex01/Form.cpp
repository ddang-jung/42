#include "Form.hpp"
#include <iostream>

// OCF
Form::Form(void) {
	std::cout << FORM << CON << std::endl;
}

Form::Form(const Form &ref) {
	std::cout << FORM << COPY_CON << std::endl;
}
Form& Form::operator=(Form const &ref) {
	std::cout << FORM << ASN << std::endl;
	if (this != &ref) {
	}
	return (*this);
}
Form::~Form(void) {
	std::cout << FORM << DES << std::endl;
}
