#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _hit(10), _energy(10), _atkDamage(0)
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy.get_name();
	_hit = copy.get_hit();
	_energy = copy.get_energy();
	_atkDamage = copy.get_atkDamage();
	std::cout << "\e[0;32mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hit(10), _energy(10), _atkDamage(0)
{
	_name = name;
	std::cout << "\e[0;32mFields Constructor called of ClapTrap\e[0m" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign.get_name();
	_hit = assign.get_hit();
	_energy = assign.get_energy();
	_atkDamage = assign.get_atkDamage();
	return *this;
}


// Getters
std::string ClapTrap::get_name() const
{
	return _name;
}
int ClapTrap::get_hit() const
{
	return _hit;
}
int ClapTrap::get_energy() const
{
	return _energy;
}
int ClapTrap::get_atkDamage() const
{
	return _atkDamage;
}

// Member Functons
void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->get_name();
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->get_name();
	if (this->get_hit() <= 0)
	{
		std::cout << " are dead, and cant be repair!" << std::endl;
		return ;
	}
	this->_hit -= amount;
	std::cout << " take " << amount << " of damage, now have " << this->get_hit() << " points of health!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->get_name();
	if (this->get_hit() <= 0)
	{
		std::cout << " are dead, and cant be repair!" << std::endl;
		return ;
	}
	if (this->get_energy() <= 0)
	{
		std::cout << " dont have energy to be repair" << std::endl;
	}
	this->_hit += amount;
	this->_energy--;
	std::cout << " repair " << amount << ", now have " << this->get_hit() << " points of health!" << std::endl;
}
