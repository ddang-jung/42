#pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		// OCF
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const& ref);
		~PresidentialPardonForm(void);

		// MY CONSTRUCTOR
		PresidentialPardonForm(const std::string &target);

		// MBF
		void	execute(Bureaucrat const &executor) const;
};