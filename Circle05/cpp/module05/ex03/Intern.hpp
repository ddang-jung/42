#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		// NEW
		static AForm	*newShrubberyCreationForm(const std::string &target);
		static AForm	*newRobotomyRequestForm(const std::string &target);
		static AForm	*newPresidentialPardonForm(const std::string &target);

	public:
		// OCF
		Intern(void);
		Intern(const Intern& ref);
		Intern	&operator=(Intern const& ref);
		virtual	~Intern(void);

		// MBF
		AForm	*makeForm(const std::string &form_name, const std::string &target_name);

		// EXC
		class	noExistFormException : public std::exception {
			public:
				const char	*what() const throw();
		};
};