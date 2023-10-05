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
//	Constructors //
	Fixed();
	Fixed(const int fpInt);
	Fixed(const float fpFloat);

//	Destructor //
	~Fixed();

//	Copy Constructor //
	Fixed( Fixed const & copy );

//	Operations Functions //
	Fixed &	operator=( Fixed const & assigOp );
	float	operator+( Fixed const & aditOp );
	float	operator*( Fixed const & multOp);
	float	operator-( Fixed const & subtOp );
	float	operator/( Fixed const & diviOp );
	bool	operator>=( Fixed const & compOp ) const;
	bool	operator<=( Fixed const & compOp ) const;
	bool	operator>( Fixed const & compOp ) const;
	bool	operator<( Fixed const & compOp ) const;
	bool	operator==( Fixed const & compOp ) const;
	bool	operator!=( Fixed const & compOp ) const;
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);


//	Member Functions //
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	static Fixed &	min( Fixed & inst1, Fixed & inst2 );
	static const Fixed &	min( Fixed const & inst1, Fixed const & inst2 );
	static Fixed &	max( Fixed & inst1, Fixed & inst2);
	static const Fixed &	max( Fixed const & inst1, Fixed const & inst2 );
};


std::ostream &	operator<<( std::ostream & output, Fixed const & instObj );

#endif