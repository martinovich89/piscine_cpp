#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Passing through WrongCat default constructor" << std::endl;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Passing through WrongCat destructor" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Passing through WrongCat copy constructor" << std::endl;
	*this = other;
	return;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Passing through WrongCat operator=() overload" << std::endl;
	this->type = other.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}