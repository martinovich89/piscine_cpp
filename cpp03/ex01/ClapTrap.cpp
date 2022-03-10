#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hp(10), ep(10), ad(0)
{
	std::cout << "A wild Claptrap appears ! Serial number : " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " signing off" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
	std::cout << "A Claptrap clone appears ! Serial number : " << name << std::endl;
}

ClapTrap::ClapTrap(std::string new_name) : name(new_name), hp(10), ep(10), ad(0)
{
	std::cout << "Created ClapTrap " << name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << this->name << " takes the appearance of " << other.name << ". Fwoshhh !" << std::endl;
	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hp > 0 && this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!\n";
		this->ep -= 1;
	}
	else if (this->hp < 1)
		std::cout << "ClapTrap " << this->name << " can't attack, it is K.O." << std::endl;
	if (this->ep < 1)
		std::cout << "ClapTrap " << this->name << " tries to attack, but instead, says : \"NoT EnougH ManA !\"" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > (uint)this->hp)
		amount = this->hp;
	if (this->hp > 0)
	{
		std::cout << this->name << " takes " << amount << " damage !\n";
		this->hp -= amount;
		if (this->hp == 0)
			std::cout << "ClapTrap " << this->name << " is K.O !" << std::endl;
	}
	else
		std::cout << this->name << " is already K.O." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp < 1)
	{
		std::cout << "ClapTrap " << this->name << " can't repair, it is K.O." << std::endl;
		return ;
	}
	if (this->ep < 1)
	{
		std::cout << "ClapTrap " << this->name << " tries to repair, but instead, says : \"NoT EnougH ManA !\"" << std::endl;
		return ;
	}
	if (amount > 100 - (uint)this->hp)
		amount = 100 - this->hp;
	if (this->hp < 100)
	{
		std::cout << this->name << " heals for " << amount << " hps !\n";
		this->hp += amount;
		this->ep -= 1;
		if (this->hp == 100)
			std::cout << "ClapTrap " << this->name << " has fully recovered.";
	}
	else
		std::cout << this->name << " has nothing to be repaired.";
}