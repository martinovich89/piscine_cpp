#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Passing through Cat default constructor" << std::endl;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Passing through Cat destructor" << std::endl;
	return;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Passing through Cat copy constructor" << std::endl;
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Passing through Cat operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}