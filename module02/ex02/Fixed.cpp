#include "Fixed.hpp"

const int Fixed::_fracNumber = 8;

//	***************************************************** //
//	*				Constructors						*
//	***************************************************** //
Fixed::Fixed()
{
	this->_fpNumber = 0;
	return;
}

Fixed::Fixed( const int ftInt )
{
	this->_fpNumber = ftInt << this->_fracNumber;
}

Fixed::Fixed( const float ftFloat )
{
	this->_fpNumber = roundf(ftFloat * ( 1 << this->_fracNumber));
}

//	Destructor
Fixed::~Fixed()
{

}

//	***************************************************** //
//	*				Copy Constructor					*
//	***************************************************** //
Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
	return;
}
//	***************************************************** //
//	*				Operations Functions				*
//	***************************************************** //
Fixed	&Fixed::operator=( Fixed const & assigOp )
{
	if (this != &assigOp)
		this->_fpNumber = assigOp.getRawBits();
	return (*this);
}

float	Fixed::operator+( Fixed const & aditOp )
{
	return (this->toFloat() + aditOp.toFloat());
}

float	Fixed::operator*( Fixed const &  multOp )
{
	return (this->toFloat() * multOp.toFloat());
}

float	Fixed::operator-( Fixed const &  subtOp ) 
{
	return (this->toFloat() - subtOp.toFloat());
}

float	Fixed::operator/( Fixed const &  diviOp )
{
	return (this->toFloat() / diviOp.toFloat());
}

bool	Fixed::operator>=( Fixed const & compOp ) const
{
	return (this->toFloat() >= compOp.toFloat());
}

bool	Fixed::operator<=( Fixed const & compOp ) const
{
	return (this->toFloat() <= compOp.toFloat());
}

bool	Fixed::operator>( Fixed const & compOp ) const
{
	return (this->toFloat() > compOp.toFloat());
}

bool	Fixed::operator<( Fixed const & compOp ) const
{
	return (this->toFloat() < compOp.toFloat());
}

bool	Fixed::operator==( Fixed const & compOp ) const
{
	return (this->toFloat() == compOp.toFloat());
}

bool	Fixed::operator!=( Fixed const & compOp ) const
{
	return (this->toFloat() != compOp.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fpNumber++;

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	this->_fpNumber++;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_fpNumber--;

	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	this->_fpNumber--;
	return (tmp);
}

//	*****************************************************	//
//	*				Member Functions					*
//	*****************************************************	//
float Fixed::toFloat() const
{
	return static_cast<float>(this->_fpNumber) / (1 << this->_fracNumber);
}

int	Fixed::toInt() const
{
	return this->_fpNumber  >> this->_fracNumber;
}

int	Fixed::getRawBits( void ) const
{

	return (this->_fpNumber);
}

std::ostream	&operator<<(std::ostream &output, Fixed const & instObj)
{
	output << instObj.toFloat();
	return (output);
}

Fixed &	Fixed::min( Fixed & inst1, Fixed & inst2 )
{
	if (inst1.toFloat() < inst2.toFloat())
		return (inst1);
	return (inst2);
}

const Fixed & Fixed::min( Fixed const & inst1, Fixed const & inst2 )
{
	if (inst1.toFloat() < inst2.toFloat())
		return (inst1);
	return (inst2);
}

Fixed &	Fixed::max( Fixed & inst1, Fixed & inst2 )
{
	if (inst1.toFloat() > inst2.toFloat())
		return (inst1);
	return (inst2);
}

const Fixed &	Fixed::max( Fixed const & inst1, Fixed const & inst2 )
{
	if (inst1.toFloat() > inst2.toFloat())
		return (inst1);
	return (inst2);
}
