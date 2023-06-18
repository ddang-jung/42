#include "Brain.hpp"
#include <iostream>

// OCF
Brain::Brain() {
	std::cout << BRAIN << CON << std::endl;
	setIdeas("Default Idea");
}
Brain::Brain(const Brain &ref) {
	std::cout << BRAIN << COPY_CON << std::endl;
	*this = ref;
}
Brain	&Brain::operator=(const Brain &ref){
	std::cout << BRAIN << ASN << std::endl;
	if (this != &ref)
		setIdeas(ref.getIdea());
	return (*this);
}
Brain::~Brain() {
	std::cout << BRAIN << DES << std::endl;
}

// STR_CON
Brain::Brain(const std::string &idea) {
	std::cout << BRAIN << STR_CON << std::endl;
	setIdeas(idea);
}

// GET / SET
const std::string	&Brain::getIdea(void) const {
	return (_ideas[0]);
}
void	Brain::setIdeas(const std::string &idea) {
	for (int i = 0; i < SIZE; i++)
		_ideas[i] = idea;
}