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

		// INIT
		void	initHitPoint(void);
		void	initEnergyPoint(void);
		void	initAttackDamage(void);

		// ACT
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	whoAmI();
		void	printStatus();
};

#endif