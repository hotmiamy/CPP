#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fpNumber;
	int	static const _fracNumber;

public:
//	Constructors
	Fixed();
	Fixed(const int fpInt);
	Fixed(const float fpFloat);

//	Destructor
	~Fixed();

//	Copy Constructor
	Fixed( Fixed const & copy );

//	Member Functions
	Fixed &	operator=( Fixed const & copyAssig );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
};

std::ostream &	operator<<( std::ostream & output, Fixed const & instObj);

#endif