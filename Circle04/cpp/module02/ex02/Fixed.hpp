#ifndef FIXED_HPP
# define FIXED_HPP

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
		// ex02
		bool	operator>(const Fixed &ref) const;
		bool	operator<(const Fixed &ref) const;
		bool	operator>=(const Fixed &ref) const;
		bool	operator<=(const Fixed &ref) const;
		bool	operator==(const Fixed &ref) const;
		bool	operator!=(const Fixed &ref) const;

		Fixed	operator+(const Fixed &ref) const;
		Fixed	operator-(const Fixed &ref) const;
		Fixed	operator*(const Fixed &ref) const;
		Fixed	operator/(const Fixed &ref) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed	&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &ref);

#endif