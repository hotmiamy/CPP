#include "Dog.hpp"

Dog::Dog()
{
	this->setType("Dog");
	std::cout << "\e[0;33mDefault Constructor called: Wonderful a dog that make noise, who am i going to code now\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called: Ho no, more noisy Dogs wonderful\e[0m" << std::endl;
}

Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
		this->_type = assign.getType();
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

Dog::~Dog()
{
	std::cout << "\e[0;31mThe noisy Dog is gone thanks\e[0m" << std::endl;
}
