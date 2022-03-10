#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->_name = "unnamed";
}

Zombie::Zombie(std::string name)
{
    this->set_name(name);
}

Zombie::~Zombie(void)
{
    std::cout << "<" << this->_name << "> " << "Gharrrgl...\n";
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ...\n";
}
