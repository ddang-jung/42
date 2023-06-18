#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// OCF
		Cure();
		Cure(const Cure &ref);
		Cure	&operator=(const Cure &ref);
		~Cure();

		// MBF
		AMateria*	clone() const;
		void		use(ICharacter& target);
};