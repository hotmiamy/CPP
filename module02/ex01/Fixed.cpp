#include "Fixed.hpp"

const int Fixed::_fracNumber = 8;

//	Constructors
Fixed::Fixed()
{
	this->_fpNumber = 0;
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
}

//	Copy Constructor
Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

//	Member Functions
Fixed	&Fixed::operator=( Fixed const & copyAssig )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyAssig)
		this->_fpNumber = copyAssig.getRawBits();
	return (*this);
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->_fpNumber) / (1 << this->_fracNumber);
}

int	Fixed::toInt() const
{
	return this->_fpNumber >> this->_fracNumber;
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
