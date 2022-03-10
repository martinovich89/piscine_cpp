#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);

	ScavTrap(std::string name);

	void attack(std::string target);
	void guardGate(void);
};