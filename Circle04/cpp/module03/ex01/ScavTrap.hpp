#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ScavTrap.h"
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:


	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &ref);
		~ScavTrap();

		ScavTrap(const std::string &name);

		void	guardGate();
};

#endif