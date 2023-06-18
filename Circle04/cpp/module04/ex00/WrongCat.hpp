#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// OCF
		WrongCat();
		WrongCat(const WrongCat &ref);
		WrongCat	&operator=(const WrongCat &ref);
		~WrongCat();

		// MBF
		virtual void	makeSound() const;
};

#endif