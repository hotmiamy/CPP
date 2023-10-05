#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
	this->_name = "";
	this->_hit = 100;
	this->_energy = 50;
	this->_atkDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "\e[0;33mField Constructor called of ScavTrap\e[0m" << std::endl;
	this->_name = name;
	this->_hit = 100;
	this->_energy = 50;
	this->_atkDamage = 20;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
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

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_name() << " is on Gate Keeper mode " << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << this->get_name();
	if (this->get_hit() <= 0)
	{
		std::cout << " are dead" << std::endl;
		return ;
	}
	if (this->get_energy() <= 0)
	{
		std::cout << " dont have energy to attack" << std::endl;
	}
	this->_energy--;
	std::cout << " attacks " << target << ", causing " << this->get_atkDamage() << " points of damage!" << std::endl;
}
