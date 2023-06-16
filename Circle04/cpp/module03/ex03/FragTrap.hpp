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

		// ACT
		void	highFivesGuys(void);
};

#endif