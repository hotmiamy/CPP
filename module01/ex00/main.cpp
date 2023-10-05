#include "Zombie.hpp"

int main( void )
{
    Zombie *vivald;

    vivald = newZombie("vivald");
    vivald->announce();
    randomChump("mozard");
    delete vivald;
    return (0);
}