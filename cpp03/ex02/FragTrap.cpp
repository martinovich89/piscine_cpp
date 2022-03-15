#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "A wild FragTrap appears. Serial Number : " << this->name << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " signing off." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "A FragTrap clone appears. Serial number : " << this->name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	(ClapTrap)*this = (ClapTrap)other;
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "A wild FragTrap appears ! Serial number : " << this->name << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

void	FragTrap::attack(std::string target)
{
	if (hp < 1)
	{
		std::cout << "FragTrap " << this->name << " can't attack, it is K.O." << std::endl;
		return ;
	}
	if (ep > 0)
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " tries to attack, but instead, says : \"NoT EnougH ManA\"" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " says : High-five, friend ! ... Uh, give me five ! ... please ? ... mate ? ... Hey ! It's starting to hurt ... Hah, whatever." << std::endl;
}
