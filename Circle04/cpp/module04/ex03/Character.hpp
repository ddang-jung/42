#pragma once

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string const	_name;
		AMateria			*_inventory[SIZE];

	public:
		// OCF
		Character();
		Character(const Character &ref);
		Character	&operator=(const Character &ref);
		~Character();

		// STR_CON
		Character(const std::string &name);

		// GET
		std::string const	& getName() const;

		// MBF
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};