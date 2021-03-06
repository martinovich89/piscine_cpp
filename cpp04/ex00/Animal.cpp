#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Passing through Animal default constructor" << std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << "Passing through Animal destructor" << std::endl;
	return;
}

Animal::Animal(Animal const &other) : type(other.type)
{
	std::cout << "Passing through Animal copy constructor" << std::endl;
	return;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << "Passing through animal operator=() overload" << std::endl;
	type = other.type;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "Some noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
