#include "Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
	this->setType("Cat");
	std::cout << "\e[0;33mDefault Constructor called: Wonderful a cat that make noise, who am i going to code now\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->_brain = new Brain();
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called: Ho no, more noisy Cats wonderful\e[0m" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\e[0;31mThe noisy Cat is gone thanks\e[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &assign)
{
	if (this != &assign)
	{
		*this->_brain = *assign._brain;
		this->_type = assign.getType();
	}
	return *this;
}

void	Cat::setIdea(int inx, std::string ideia) const {this->_brain->setIdea(ideia, inx);}

std::string Cat::getIdea(int inx) const {return (this->_brain->getIdeas(inx));}

void	Cat::makeSound() const
{
	std::cout
	<< "The "
	<< this->getType()
	<< " Meow: Meoooow Meoooow Meow Meooow"
	<< std::endl;
}
