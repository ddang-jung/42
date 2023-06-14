#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ScavTrap.h"
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &ref);
		~ScavTrap();

		ScavTrap(const std::string &name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate();
};

#endif