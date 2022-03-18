#include "Brain.hpp"

Brain::Brain() : ideas()
{
	std::cout << "Passing through Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Passing through Brain destructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Passing through Brain copy constructor" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	for (unsigned i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return *this;
}