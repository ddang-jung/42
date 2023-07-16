#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		// OCF
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const& ref);
		~ShrubberyCreationForm(void);

		// MY CONSTRUCTOR
		ShrubberyCreationForm(const std::string &target);

		// MBF
		void	execute(Bureaucrat const &executor) const;

		// EXC
		class	OpenFailException : public std::exception {
			public:
				const char	*what() const throw();
		};
};