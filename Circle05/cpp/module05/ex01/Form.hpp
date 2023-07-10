#pragma once

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	public:
		// OCF
		Form(void);
		Form(const Form& ref);
		Form	&operator=(Form const& ref);
		virtual	~Form(void);

		// GET
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;	

		// MBF
		void	beSigned(const Bureaucrat &ref);

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

std::ostream	&operator<<(std::ostream &os, const Form &ref);