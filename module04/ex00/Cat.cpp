#include "Cat.hpp"

Cat::Cat()
{
	this->setType("Cat");
	std::cout << "\e[0;33mDefault Constructor called: Wonderful a cat that make noise, who am i going to code now\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called: Ho no, more noisy Cats wonderful\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
{
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

void	Cat::makeSound() const
{
	std::cout
	<< "The "
	<< this->getType()
	<< " Meow: Meoooow Meoooow Meow Meooow"
	<< std::endl;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mThe noisy Cat is gone thanks\e[0m" << std::endl;
}
