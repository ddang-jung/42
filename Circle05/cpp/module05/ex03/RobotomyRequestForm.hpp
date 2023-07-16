#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		// OCF
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const& ref);
		~RobotomyRequestForm(void);

		// MY CONSTRUCTOR
		RobotomyRequestForm(const std::string &target);

		// MBF
		void	execute(Bureaucrat const &executor) const;
};