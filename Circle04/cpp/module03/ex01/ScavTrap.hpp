#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ScavTrap.h"

class ScavTrap : public ClapTrap
{
	public:
		// OCF
		ScavTrap();
		ScavTrap(const std::string &name); // STR_CON
		ScavTrap(const ScavTrap &ref);
		ScavTrap	&operator=(const ScavTrap &ref);
		~ScavTrap();

		// INIT
		void	initHitPoint(void);
		void	initEnergyPoint(void);
		void	initAttackDamage(void);

		// ACT
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate();
		void	printStatus();
};

#endif