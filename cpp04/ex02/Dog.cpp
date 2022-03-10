#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Passing through Dog default constructor" << std::endl;
	return;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Passing through Dog destructor" << std::endl;
	return;
}

Dog::Dog(Dog const &other)
{
	std::cout << "Passing through Dog copy constructor" << std::endl;
	*this = other;
	return;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Passing through Dog operator=() overload" << std::endl;
	this->type = other.getType();
	*(this->brain) = *(other.get_brain());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain	*Dog::get_brain(void) const
{
	return (this->brain);
}