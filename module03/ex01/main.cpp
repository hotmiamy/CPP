#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap clap("clap");
	ScavTrap scav("scav");

	clap.attack(scav.get_name());
	scav.takeDamage(clap.get_atkDamage());
	scav.attack(clap.get_name());
	clap.takeDamage(scav.get_atkDamage());
	clap.beRepaired(1);
	scav.beRepaired(1);
	scav.guardGate();

	return 0;
}