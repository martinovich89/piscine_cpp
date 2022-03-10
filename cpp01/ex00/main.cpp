#include "Zombie.hpp"

int main(void)
{
    Zombie *JeanPaul = NULL;

    Zombie JeanPierre("Jean-Pierre");
    JeanPierre.announce();

    JeanPaul = newZombie("Jean-Paul");
    JeanPaul->announce();

    randomChump("Jean-Jacques");

    delete JeanPaul;
//    JeanPaul->randomChump("Hervé");

    return (0);
}