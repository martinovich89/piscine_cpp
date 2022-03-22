#include "Base.class.hpp"
#include <iostream>
#include <cstdlib>

Base*	randomize_class()
{
	srand(time(NULL));
	if (rand() % 3 == 0)
		return (new A());
	else if (rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	identify_class(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify_class(Base &toCast)
{
	Base casted;
	try
	{
		casted = dynamic_cast<A&>(toCast);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		casted = dynamic_cast<B&>(toCast);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		casted = dynamic_cast<C&>(toCast);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}	
}

int		main(void)
{
	Base	*someClass;

	someClass = randomize_class();
	std::cout << "identify by pointer: ";
	identify_class(someClass);
	std::cout << "identify by reference: ";
	identify_class(*someClass);

	delete someClass;

	return (0);
}
