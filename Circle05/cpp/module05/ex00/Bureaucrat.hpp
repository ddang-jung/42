#pragma once

# include "Message.hpp"
# include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		const int			_grade;

	public:
		// OCF
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat	&operator=(Bureaucrat const& ref);
		virtual	~Bureaucrat(void);

		// GET
		const std::string	getName() const ;
		const int			getGrade() const ;
};