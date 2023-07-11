#include "PresidentialPardonForm.hpp"
#include <iostream>

// OCF
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardoen", 25, 5), _target("Target") {
	// std::cout << PRESIDENT << CON << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()), _target(ref._target) {
	// std::cout << PRESIDENT << COPY_CON << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {
	// std::cout << PRESIDENT << ASN << std::endl;
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(void) {
	// std::cout << PRESIDENT << DES << std::endl;
}

// MY CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardoen", 25, 5), _target(target) {
	// std::cout << PRESIDENT << MY_CON << std::endl;
}

// MBF
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}