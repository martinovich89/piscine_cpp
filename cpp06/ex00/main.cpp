#include "ScalarConversion.hpp"

int main(int ac, char **av)
{
	ScalarConversion	ScalarConversion;

	try
	{
		if (ac != 2)
			throw ScalarConversion::WrongUsageException();
		ScalarConversion.fetchValue(av[1]);
		std::cout << ScalarConversion;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}