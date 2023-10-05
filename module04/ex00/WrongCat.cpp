#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->setType("WrongCat");
	std::cout << "\e[0;33mDefault Constructor called: WTF a WrongCat that make noise, i wonder what sound it makes ?\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called: Ho no, more wierd WrongCats the world is crazy\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	_type = assign.getType();
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout
	<< "The "
	<< this->getType()
	<< " say: wrong cats don't make noise fix it programmer"
	<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mThe weird WrongCat is gone\e[0m" << std::endl;
}