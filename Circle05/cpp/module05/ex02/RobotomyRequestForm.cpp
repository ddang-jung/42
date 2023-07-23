#include "RobotomyRequestForm.hpp"
#include <iostream>

// OCF
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequest", 72, 45), _target("Target") {
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()), _target(ref._target) {
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void) {
}

// MY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequest", 72, 45), _target(target) {
}

// MBF
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << DRILL << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " failed to robotomize." << std::endl;
}