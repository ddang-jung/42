#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		// OCF
		Dog();
		Dog(const Dog &ref);
		Dog	&operator=(const Dog &ref);
		~Dog();

		// STR_CON
		Dog(const std::string &idea);

		// GET
		const Brain	&getBrain() const;

		// MBF
		void	makeSound() const;
};

#endif