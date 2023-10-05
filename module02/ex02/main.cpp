#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	if (a == Fixed::min( a, b ))
		std::cout << "a equal min function" << std::endl;
	if (b != Fixed::min( a, b ))
		std::cout << "b diff min function" << std::endl;
	if (a < b)
		std::cout << "a is less than b" << std::endl;
	if (b > a)
		std::cout << "b is more than a" << std::endl;
	if (a <= a)
		std::cout << "a is less or equal than a" << std::endl;
	if (b >= b)
		std::cout << "b is more or equal than b" << std::endl;
	return 0;
}
