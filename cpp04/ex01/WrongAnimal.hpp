#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected :

	std::string type;

	public :

	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	virtual WrongAnimal &operator=(const WrongAnimal &other);

	void makeSound() const;

	std::string getType() const;
};
