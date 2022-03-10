#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Passing through WrongAnimal default constructor" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Passing through WrongAnimal destructor" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal copy constructor" << std::endl;
	*this = other;
	return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Passing through WrongAnimal operator=() overload" << std::endl;
	this->type = other.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some noise" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
