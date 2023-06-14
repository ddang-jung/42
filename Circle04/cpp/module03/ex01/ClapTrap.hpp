#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "ClapTrap.h"
# include <string>

class ClapTrap
{
	private:
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_ad;

	protected:
		std::string		_name;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &ref);
		ClapTrap	&operator=(const ClapTrap &ref);
		~ClapTrap();

		ClapTrap(const std::string &name);

		const std::string	&getName() const;
		unsigned int		getHitPoint() const;
		unsigned int		getEnergyPoint() const;
		unsigned int		getAttackDamage() const;
		void				setHitPoint(unsigned int hp);
		void				setEnergyPoint(unsigned int ep);
		void				setAttackDamage(unsigned int ad);

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
};


#endif