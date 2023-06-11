#ifndef FIXED_HPP
# define FIXED_HPP

# include "Fixed.h"

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
};

#endif