#include "RobotomyRequestForm.hpp"
#include <iostream>

// OCF
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequest", 72, 45), _target("Target") {
	// std::cout << ROBOTOMY << CON << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()), _target(ref._target) {
	// std::cout << ROBOTOMY << COPY_CON << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
	// std::cout << ROBOTOMY << ASN << std::endl;
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void) {
	// std::cout << ROBOTOMY << DES << std::endl;
}

// MY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequest", 72, 45), _target(target) {
	// std::cout << ROBOTOMY << MY_CON << std::endl;
}

// MBF
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << DRILL << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " failed to robotomize." << std::endl;
}