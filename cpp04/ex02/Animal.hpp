#pragma once

#include "Brain.hpp"
#include <iostream>
#include <string>

class Animal
{
	protected :

	std::string type;

	public :

	Animal();
	virtual ~Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound(void) const = 0;
	virtual Brain *get_brain(void) const;

	std::string getType(void) const;
};
