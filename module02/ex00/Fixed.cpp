#include "Fixed.hpp"

const int Fixed::_fracNumber = 8;

Fixed::Fixed() : _fpNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Fixed::~Fixed()
{
		std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw)
{
	this->_fpNumber = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpNumber);
}

Fixed	&Fixed::operator=( Fixed const & copyAssig )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyAssig)
		this->_fpNumber = copyAssig.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, Fixed const & instObj)
{
	output << instObj.getRawBits();
	return (output);
}
