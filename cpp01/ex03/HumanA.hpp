#pragma once

#include "Weapon.hpp"

class HumanA
{
    public:

    void    attack(void);
    HumanA(std::string name, Weapon &weapon);

    private:
    std::string     _name;
    Weapon          &_weapon;
};
