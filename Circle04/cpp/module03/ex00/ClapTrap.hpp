#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "ClapTrap.h"

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_ad;

	public:
		// OCF
		ClapTrap();
		ClapTrap(const std::string &name); // STR_CON
		ClapTrap(const ClapTrap &ref);
		ClapTrap	&operator=(const ClapTrap &ref);
		~ClapTrap();

		// ACT
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStatus();
};


#endif