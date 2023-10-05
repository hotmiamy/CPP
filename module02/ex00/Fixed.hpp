#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_fpNumber;
	int	static const _fracNumber;

public:
	Fixed();
	Fixed( Fixed const & copy );
	~Fixed();

	Fixed &	operator=( Fixed const & copyAssig );
	int		getRawBits( void ) const;
	void	setRawBits(  int const raw );
};

std::ostream &	operator<<( std::ostream & output, Fixed const & instObj);

#endif