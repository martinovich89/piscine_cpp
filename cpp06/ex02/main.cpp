#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*	generate()
{
	srand(time(NULL));
	if (rand() % 3 == 0)
		return (new A());
	else if (rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *toCast)
{
	if (dynamic_cast<A*>(toCast) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(toCast) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(toCast) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &toCast)
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

	someClass = generate();
	std::cout << "identify by pointer: ";
	identify(someClass);
	std::cout << "identify by reference: ";
	identify(*someClass);

	delete someClass;

	return (0);
}
