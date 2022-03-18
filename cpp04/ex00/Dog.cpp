#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Passing through Dog default constructor" << std::endl;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Passing through Dog destructor" << std::endl;
	return;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Passing through Dog copy constructor" << std::endl;
	*this = other;
	return;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Passing through Dog operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}