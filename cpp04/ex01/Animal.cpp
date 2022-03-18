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

Animal::Animal(Animal const &other)
{
	std::cout << "Passing through Animal copy constructor" << std::endl;
	*this = other;
	return;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Passing through operator=() overload" << std::endl;
    if ((this->type == "Cat" || this->type == "Dog") && (other.type == "Cat" || other.type == "Dog"))
        *get_brain() = *other.get_brain();
    this->type = other.type;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "Some noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

Brain	*Animal::get_brain(void) const
{
	return (NULL);
}
