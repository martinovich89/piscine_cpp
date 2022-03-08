#pragma once

#include "Weapon.hpp"

class HumanB
{
    public:

    HumanB(std::string name);
    void    attack(void);
    void    setWeapon(Weapon &weapon);
    void    setName(std::string name);

    private:
    
    Weapon      *_weapon;
    std::string _name;
};