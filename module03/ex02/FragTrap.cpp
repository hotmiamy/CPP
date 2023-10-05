#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_atkDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap( std::string name) : ClapTrap(name)
{
	std::cout << "\e[0;33mField Constructor called of FragTrap\e[0m" << std::endl;
	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_atkDamage = 30;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		this->_atkDamage = assign.get_atkDamage();
		this->_energy = assign.get_energy();
		this->_hit = assign.get_hit();
		this->_name = assign.get_name();
	}
	return *this;
}


//Member Functions
void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->get_name() << " request an super high five" << std::endl; 
}