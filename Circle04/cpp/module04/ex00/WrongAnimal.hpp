#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Message.h"
# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		// OCF
		WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal	&operator=(const WrongAnimal &ref);
		virtual	~WrongAnimal();

		// GET
		const std::string	&getType() const;

		// MBF
		void	makeSound() const;
};


#endif