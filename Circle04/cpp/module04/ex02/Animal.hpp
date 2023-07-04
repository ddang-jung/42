#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Message.h"
# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		// OCF
		Animal();
		Animal(const Animal &ref);
		Animal	&operator=(const Animal &ref);
		virtual	~Animal();

		// GET
		const std::string	&getType() const;

		// MBF
		virtual void	makeSound() const = 0;
};

#endif