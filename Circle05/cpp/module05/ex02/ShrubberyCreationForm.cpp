#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// OCF
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreation", 145, 137), _target("Target") {
	// std::cout << SHRUBBERY << CON << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()), _target(ref._target) {
	// std::cout << SHRUBBERY << COPY_CON << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref) {
	// std::cout << SHRUBBERY << ASN << std::endl;
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	// std::cout << SHRUBBERY << DES << std::endl;
}

// MY CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {
	// std::cout << SHRUBBERY << MY_CON << std::endl;
}

// MBF
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	of;

	of.open(this->_target + "_shrubbery", std::ios_base::out);
	if (of.fail())
		throw ShrubberyCreationForm::OpenFailException();
	of << TREE;
	of.close();
}

// EXC
const char	*ShrubberyCreationForm::OpenFailException::what() const throw() {
	return ("failed to open.");
}