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
	checkGrade(_grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref._name), _grade(ref._grade) {
	checkGrade(_grade);
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &ref) {
	if (this != &ref) {
		this->_grade = ref._grade;
	}
	checkGrade(this->_grade);
	return (*this);
}
Bureaucrat::~Bureaucrat(void) {
}

// MY CONSTRUCTOR
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	checkGrade(_grade);
}

// GET
const std::string	&Bureaucrat::getName() const {
	return (this->_name);
}
int					Bureaucrat::getGrade() const {
	return (this->_grade);
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
void	Bureaucrat::signForm(AForm &ref) const {
	try
	{
		ref.beSigned(*this);
		std::cout << this->getName() << " signed " << ref.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << ref.getName() << " because " << e.what() << std::endl;
	}
}
void	Bureaucrat::executeForm(AForm const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

// EXC
const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.. 1 <= Grade <= 150");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low... 1 <= Grade <= 150");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref) {
	os << ref.getName() << ", bureacrat grade " << ref.getGrade() << ".";
	return (os);
}