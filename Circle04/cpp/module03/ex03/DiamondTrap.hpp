#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "DiamondTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		// OCF
		DiamondTrap();
		DiamondTrap(const std::string &name); // STR_CON
		DiamondTrap(const DiamondTrap &ref);
		DiamondTrap	&operator=(const DiamondTrap &ref);
		~DiamondTrap();

		// ACT
		void	attack(const std::string &target);
		void	whoAmI();
		void	printStatus();
};

#endif