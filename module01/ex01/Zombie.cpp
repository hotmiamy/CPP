#include "Zombie.hpp"

Zombie::Zombie() 
{}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": has been deleted" << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
