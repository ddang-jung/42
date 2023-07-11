#pragma once

# include "Message.hpp"
# include <string>
# include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void				checkGrade(int grade);

	public:
		// OCF
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade); // my constructor
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat	&operator=(Bureaucrat const& ref);
		virtual	~Bureaucrat(void);

		// GET
		const std::string	&getName() const;
		int					getGrade() const;

		// MBF
		void	increaseGrade();
		void	decreaseGrade();

		// EXC
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref);