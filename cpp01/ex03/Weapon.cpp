#include "Weapon.hpp"

void    Weapon::setType(std::string type)
{
    _type = type;
}

const std::string    &Weapon::getType(void) const
{
    return (_type);
}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}