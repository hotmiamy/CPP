#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap scav("scav");
	FragTrap frag("frag");

	scav.attack(frag.get_name());
	frag.takeDamage(scav.get_atkDamage());
	frag.attack(scav.get_name());
	scav.takeDamage(frag.get_atkDamage());
	scav.beRepaired(10);
	frag.beRepaired(10);
	scav.guardGate();
	frag.highFivesGuys();

	return 0;
}