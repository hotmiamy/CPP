#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal: But what WrongAnimal is it?\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal: More mystery WrongAnimals\e[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal: I hope virtual extinction is not against the law\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	_type = assign.getType();
	return *this;
}


// Getters / Setters
std::string WrongAnimal::getType() const
{
	return _type;
}

void		WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

//Member Funcions
void	WrongAnimal::makeSound() const
{
	std::cout << "WTF this" << this->getType() << " is making a weird sound " << std::endl;
}
