#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// OCF
		Dog();
		Dog(const Dog &ref);
		Dog	&operator=(const Dog &ref);
		~Dog();

		// MBF
		void	makeSound() const;
};

#endif