#include "Bureaucrat.hpp"
#include <iostream>

void	Bureaucrat::checkGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// OCF
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout << BUREAUCRAT << CON << std::endl;
	checkGrade(_grade);
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	std::cout << BUREAUCRAT << MY_CON << std::endl;
	checkGrade(_grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref._name), _grade(ref._grade) {
	std::cout << BUREAUCRAT << COPY_CON << std::endl;
	checkGrade(_grade);
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &ref) {
	std::cout << BUREAUCRAT << ASN << std::endl;
	if (this != &ref) {
		this->_grade = ref._grade;
	}
	checkGrade(this->_grade);
	return (*this);
}
Bureaucrat::~Bureaucrat(void) {
	std::cout << BUREAUCRAT << DES << std::endl;
}

// GET
const std::string	&Bureaucrat::getName() const {
	return (_name);
}
int					Bureaucrat::getGrade() const {
	return (_grade);
}

// MBF
void	Bureaucrat::increaseGrade() {
	checkGrade(this->_grade - 1);
	this->_grade -= 1;
}
void	Bureaucrat::decreaseGrade() {
	checkGrade(this->_grade + 1);
	this->_grade += 1;
}

// EXC
const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.. 1 <= Grade <= 150");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low... 1 <= Grade <= 150");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref) {
	os << ref.getName() << ", bureacrat grade " << ref.getGrade() << "." << std::endl;
	return (os);
}