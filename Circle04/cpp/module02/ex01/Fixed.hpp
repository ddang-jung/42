#ifndef FIXED_HPP
# define FIXED_HPP

# include "Fixed.h"
# include <iostream>

class Fixed {
	private:
		int					_rawBit;
		static const int	_fracBit = 8;

	public:
		// OCF
		Fixed();
		Fixed(const Fixed &ref);
		Fixed	&operator=(const Fixed &ref);
		~Fixed();
		// ex00
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		// ex01
		Fixed(const int value);
		Fixed(const float value);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &ref);

#endif