#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;
		
	public:
		void	announce( void );
		void	setZombieName( std::string str );
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );

		Zombie();
		~Zombie();
};

#endif