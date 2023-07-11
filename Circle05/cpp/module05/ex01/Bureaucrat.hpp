#pragma once

# include "Message.hpp"
# include "Form.hpp"
# include <string>
# include <stdexcept>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void				checkGrade(int grade);

	public:
		// OCF
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat	&operator=(Bureaucrat const& ref);
		virtual	~Bureaucrat(void);

		// MY CONSTRUCTOR
		Bureaucrat(const std::string &name, int grade);

		// GET
		const std::string	&getName() const;
		int					getGrade() const;

		// MBF
		void	increaseGrade();
		void	decreaseGrade();
		void	signForm(Form &ref) const;

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