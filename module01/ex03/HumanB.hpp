#ifndef	HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	Weapon		*_weapon;
	std::string _name;
public:
// Constructors
	HumanB(std::string name);
// Destructors
	~HumanB();
// Setters
	void	setWeapon(Weapon &weapon);
// Member functions
	void	attack();
};

#endif
