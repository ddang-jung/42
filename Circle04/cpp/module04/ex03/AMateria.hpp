#pragma once

# include <string>
# include "Message.h"
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		// OCF
		AMateria();
		AMateria(const AMateria &ref);
		AMateria	&operator=(const AMateria &ref);

	public:
		virtual	~AMateria();

		// STR_CON
		AMateria(std::string const & type);

		// GET
		std::string	const & getType() const; //Returns the materia type

		// MBF
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};