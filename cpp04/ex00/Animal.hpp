#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected :

	std::string type;

	public :

	Animal();
	~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	virtual void makeSound() const;

	std::string get_type() const;
};
