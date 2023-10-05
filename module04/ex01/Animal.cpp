#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	_type = "Animal";
	std::cout << "\e[0;33mDefault Constructor called of Animal: But what animal is it?\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Animal: More mystery animals\e[0m" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal: I hope virtual extinction is not against the law\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	if (this != &assign)
		_type = assign.getType();
	return *this;
}


// Getters / Setters
std::string Animal::getType() const
{
	return _type;
}

void		Animal::setType(const std::string &type)
{
	this->_type = type;
}

//Member Funcions
void	Animal::makeSound() const
{
	std::cout << "What does the " << this->getType() << " say ?" << std::endl;
}
