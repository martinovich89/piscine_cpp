#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Passing through Cat default constructor" << std::endl;
	return;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Passing through Cat destructor" << std::endl;
	return;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Passing through Cat copy constructor" << std::endl;
	*this = other;
	return;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Passing through Cat operator=() overload" << std::endl;
	this->type = other.getType();
	*(this->brain) = *(other.get_brain());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::get_brain() const
{
	return (this->brain);
}