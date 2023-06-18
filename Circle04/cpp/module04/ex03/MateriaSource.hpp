#pragma once

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_templates[SIZE];
	public:
		// OCF
		MateriaSource(void);
		MateriaSource(const MateriaSource& ref);
		MateriaSource	&operator=(MateriaSource const& ref);
		virtual	~MateriaSource(void);

		// MBF
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};