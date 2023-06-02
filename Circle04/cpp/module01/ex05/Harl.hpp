#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		std::string	name[4];
		void		(Harl::*ptr[4])(void);

		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );

	public:
		void	complain( std::string level );

		Harl();
		~Harl();
};



#endif