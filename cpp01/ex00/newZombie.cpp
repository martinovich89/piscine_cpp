#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *my_zombie = new Zombie;
    my_zombie->set_name(name);
    return (my_zombie);
}