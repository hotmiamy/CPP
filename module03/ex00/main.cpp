#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap clap("clap");
	ClapTrap trap("trap");

	clap.attack(trap.get_name());
	trap.takeDamage(clap.get_atkDamage());
	trap.attack(clap.get_name());
	clap.takeDamage(trap.get_atkDamage());
	clap.beRepaired(1);
	trap.beRepaired(1);

	return 0;
}