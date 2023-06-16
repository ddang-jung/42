#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ScavTrap.h"

class ScavTrap : virtual public ClapTrap
{
	public:
		// OCF
		ScavTrap();
		ScavTrap(const std::string &name); // STR_CON
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &ref);
		~ScavTrap();

		// ACT
		void	guardGate();
		// void	attack(const std::string& target);
};

#endif