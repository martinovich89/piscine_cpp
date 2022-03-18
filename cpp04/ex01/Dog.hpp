#pragma once

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	private :

	Brain *brain;

	public :

	Dog();
	virtual ~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	void makeSound() const;

	Brain *get_brain(void) const;
};
