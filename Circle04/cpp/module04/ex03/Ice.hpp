#pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// OCF
		Ice();
		Ice(const Ice &ref);
		Ice	&operator=(const Ice &ref);
		~Ice();

		// MBF
		AMateria*	clone() const;
		void		use(ICharacter& target);
};