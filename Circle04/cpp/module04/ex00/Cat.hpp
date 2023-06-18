#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// OCF
		Cat();
		Cat(const Cat &ref);
		Cat	&operator=(const Cat &ref);
		~Cat();

		// MBF
		void	makeSound() const;
};

#endif