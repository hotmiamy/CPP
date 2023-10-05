#include "Zombie.hpp"

int main( void )
{
    Zombie *michael;

    michael = zombieHorde(5, "michael");
    for (size_t i = 0; i < 5; i++)
    {
        michael[i].announce();
    }
    delete[] michael;
    return (0);
}