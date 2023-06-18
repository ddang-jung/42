#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		// OCF
		Cat();
		Cat(const Cat &ref);
		Cat	&operator=(const Cat &ref);
		~Cat();

		// STR_CON
		Cat(const std::string &idea);

		// GET
		const Brain	&getBrain() const;

		// MBF
		void	makeSound() const;
};

#endif