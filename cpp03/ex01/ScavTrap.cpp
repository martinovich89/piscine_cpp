#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "A wild ScavTrap appears. Serial number : " << this->name << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " signing off" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "A ScavTrap clone appears ! Serial number : " << this->name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	(ClapTrap)*this = (ClapTrap)other;
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "A wild ScavTrap appears. Serial number : " << this->name << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
}

void	ScavTrap::attack(std::string target)
{
	if (this->hp < 1)
	{
		std::cout << "ScavTrap " << this->name <<  " can't attack. It's K.O." << std::endl;
		return ;
	}
	if (this->ep > 1)
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " tries to attack " << target << ", but instead, says : \"NoT EnougH ManA\"" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " has entered \"Gate Keeper\" mode." << std::endl;
}

std::string ClapTrap::get_name()
{
	return (name);
}

int	ClapTrap::get_hp()
{
	return (hp);
}

int ClapTrap::get_ep()
{
	return (ep);
}

int ClapTrap::get_ad()
{
	return (ad);
}
