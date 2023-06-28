#include "MateriaSource.hpp"
#include <iostream>

// OCF
MateriaSource::MateriaSource(void) {
	// std::cout << MATERIASOURCE << CON << std::endl;
	for (int i = 0; i < SIZE; i++)
		_templates[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &ref) {
	// std::cout << MATERIASOURCE << COPY_CON << std::endl;
	*this = ref;
}
MateriaSource& MateriaSource::operator=(MateriaSource const &ref) {
	// std::cout << MATERIASOURCE << ASN << std::endl;
	if (this != &ref) {
		for (int i = 0; i < SIZE; i++) {
			if (this->_templates[i])
				delete _templates[i];
			if (ref._templates[i])
				this->_templates[i] = ref._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}
	return (*this);
}
MateriaSource::~MateriaSource(void) {
	// std::cout << MATERIASOURCE << DES << std::endl;
	for (int i = 0; i < SIZE; i++)
		if (_templates[i])
			delete _templates[i];
}

// MBF
void		MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < SIZE; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m->clone();
			// std::cout << "MateriaSource: learned " << m->getType() << std::endl;
			return ;
		}
	}
	// std::cout << "MateriaSource: no space in templates" << std::endl;
}
AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < SIZE; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	// std::cout << "MateriaSource: there is no " << type << " in templates" << std::endl;
	return (NULL);
}