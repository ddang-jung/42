#include "Form.hpp"
#include <iostream>

void	Form::checkGrade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

// OCF
Form::Form(void) : _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	std::cout << FORM << CON << std::endl;
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}
Form::Form(const Form &ref) : _name(ref._name), _is_signed(ref._is_signed), _grade_to_sign(ref._grade_to_sign), _grade_to_execute(ref._grade_to_execute) {
	std::cout << FORM << COPY_CON << std::endl;
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}
Form& Form::operator=(Form const &ref) {
	std::cout << FORM << ASN << std::endl;
	if (this != &ref) {
		this->_is_signed = ref._is_signed;
	}
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
	return (*this);
}
Form::~Form(void) {
	std::cout << FORM << DES << std::endl;
}

// MY CONSTRUCTOR
Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	std::cout << FORM << MY_CON << std::endl;
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}

// GET
const std::string	&Form::getName() const {
	return (this->_name);
}
bool				Form::getIsSigned() const {
	return (this->_is_signed);
}
int					Form::getGradeToSign() const {
	return (this->_grade_to_sign);
}
int					Form::getGradeToExecute() const {
	return (this->_grade_to_execute);
}

// MBF
void	Form::beSigned(const Bureaucrat &ref) {
	if (ref.getGrade() <= this->getGradeToSign())
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

// EXC
const char	*Form::GradeTooHighException::what() const throw() {
	return ("grade is too high.");
}
const char	*Form::GradeTooLowException::what() const throw() {
	return ("grade is too low.");
}

std::ostream	&operator<<(std::ostream &os, const Form &ref) {
	os << ref.getName() << ", form is_signed : " << ref.getIsSigned() << ", grade to sign : " << ref.getGradeToSign() << ", grade to execute : " << ref.getGradeToExecute();
	return (os);
}