#include "Zombie.hpp"

int main(void)
{
    Zombie *Horde = zombieHorde(8, "Jean-Claude");

    for (int i = 0; i < 8; i++)
    {
        Horde[i].announce();
    }

    delete[] Horde;
}