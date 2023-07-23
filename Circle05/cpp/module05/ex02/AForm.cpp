#include "AForm.hpp"
#include <iostream>

void	AForm::checkGrade(int grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

// OCF
AForm::AForm(void) : _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}
AForm::AForm(const AForm &ref) : _name(ref._name), _is_signed(ref._is_signed), _grade_to_sign(ref._grade_to_sign), _grade_to_execute(ref._grade_to_execute) {
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}
AForm& AForm::operator=(AForm const &ref) {
	if (this != &ref) {
		this->_is_signed = ref._is_signed;
	}
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
	return (*this);
}
AForm::~AForm(void) {
}

// MY CONSTRUCTOR
AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	checkGrade(_grade_to_sign);
	checkGrade(_grade_to_execute);
}

// GET
const std::string	&AForm::getName() const {
	return (this->_name);
}
bool				AForm::getIsSigned() const {
	return (this->_is_signed);
}
int					AForm::getGradeToSign() const {
	return (this->_grade_to_sign);
}
int					AForm::getGradeToExecute() const {
	return (this->_grade_to_execute);
}

// MBF
void	AForm::beSigned(const Bureaucrat &ref) {
	if (ref.getGrade() <= this->getGradeToSign())
		this->_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

// EXC
const char	*AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high.");
}
const char	*AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low.");
}
const char	*AForm::IsNotSignedException::what() const throw() {
	return ("not signed.");
}

std::ostream	&operator<<(std::ostream &os, const AForm &ref) {
	os << ref.getName() << ", form is_signed : " << ref.getIsSigned() << ", grade to sign : " << ref.getGradeToSign() << ", grade to execute : " << ref.getGradeToExecute();
	return (os);
}