#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Message.h"
# include <string>

class Brain
{
	private:
		std::string	_ideas[SIZE];

	public:
		// OCF
		Brain();
		Brain(const Brain &ref);
		Brain	&operator=(const Brain &ref);
		virtual	~Brain();

		// STR_CON
		Brain(const std::string &idea);

		// GET / SET
		const std::string	&getIdea(void) const;
		void				setIdeas(const std::string &idea);
};

#endif