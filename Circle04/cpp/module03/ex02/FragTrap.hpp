#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "FragTrap.h"
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &ref);
		FragTrap	&operator=(const FragTrap &ref);
		~FragTrap();

		FragTrap(const std::string &name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif