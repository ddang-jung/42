#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "FragTrap.h"

class FragTrap : virtual public ClapTrap
{
	public:
		// OCF
		FragTrap();
		FragTrap(const std::string &name); // STR_CON
		FragTrap(const FragTrap &ref);
		FragTrap	&operator=(const FragTrap &ref);
		~FragTrap();

		// INIT
		void	initHitPoint(void);
		void	initEnergyPoint(void);
		void	initAttackDamage(void);

		// ACT
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);
};

#endif