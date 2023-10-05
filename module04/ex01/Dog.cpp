#include "Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain();
	this->setType("Dog");
	std::cout << "\e[0;33mDefault Constructor called: Wonderful a dog that make noise, who am i going to code now\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->_brain = new Brain();
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called: Ho no, more noisy Dogs wonderful\e[0m" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\e[0;31mThe noisy Dog is gone thanks\e[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		*this->_brain = *assign._brain;
		this->_type = assign.getType();
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout
	<< "The "
	<< this->getType()
	<< " Barks: AU AU AU AU AU AU AU"
	<< std::endl;
}
