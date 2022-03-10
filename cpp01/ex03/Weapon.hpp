#pragma once

#include <iostream>
#include <string>

class Weapon
{
    public:

    Weapon(std::string type);

    const std::string&  getType() const;
    void                setType(std::string type);

    private:

    std::string _type;
};