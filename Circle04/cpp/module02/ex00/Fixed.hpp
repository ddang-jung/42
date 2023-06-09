#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_bit = 8;

	public:
		// OCF
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		// ex00
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif