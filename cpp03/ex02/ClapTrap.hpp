#pragma once

#include <iostream>
#include <string>

typedef unsigned int uint;

class ClapTrap
{
	protected :

	std::string name;
	int hp;
	int ep;
	int ad;

	public :

	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	ClapTrap(std::string Name);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string get_name();
	int get_hp();
	int get_ep();
	int get_ad();
};
