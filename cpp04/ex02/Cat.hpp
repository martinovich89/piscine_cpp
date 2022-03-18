#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	private :

	Brain *brain;

	public :

	Cat();
	virtual ~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound() const;

	Brain *get_brain() const;
};
