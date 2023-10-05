#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	this->operator=(copy);
	std::cout << "\e[0;33mCopy Constructor called: two brains thinks better than one\e[0m" << std::endl;
}


Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

Brain	&Brain::operator=(Brain const &assing)
{
	if (this != &assing)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = assing.getIdeas(i);
	}
	return *this;
}

//***************************************************
//*				Setter/Getter						*
//***************************************************
std::string	Brain::getIdeas(int inx) const {return this->_ideas[inx];}

void		Brain::setIdea(std::string str, int size)
{
	for (int i = 0; i <= size; i++)
		this->_ideas[i] = str;
}