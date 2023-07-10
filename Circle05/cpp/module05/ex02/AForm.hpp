#pragma once

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		int					_grade_to_sign;
		int					_grade_to_execute;
		void				checkGrade(int grade);

	public:
		// OCF
		AForm(void);
		AForm(const AForm& ref);
		AForm	&operator=(AForm const& ref);
		virtual	~AForm(void);

		// MY CONSTRUCTOR
		AForm(const std::string &name, int grade_to_sign, int grade_to_execute);

		// GET
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// MBF
		void	beSigned(const Bureaucrat &ref);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator<<(std::ostream &os, const AForm &ref);