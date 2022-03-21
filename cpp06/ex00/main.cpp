#include "scalarTypeConversions.hpp"

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << std::endl << "Format: " << std::endl;
		std::cout << " ----------------- " << std::endl;
		std::cout << "| Char    | \"'a'\" |" << std::endl;
		std::cout << "| Int     | 42    |" << std::endl;
		std::cout << "| Float   | 42.0f |" << std::endl;
		std::cout << "| Double  | 42.0  |" << std::endl;
		std::cout << " ----------------- " << std::endl;
		return (0);
	}
	std::string arg(av[1]);
	if (arg.length() == 0)
	{
		std::cout << "Empty argument" << std::endl;
		return (0);
	}

	int		t = whichType(arg);
	converter	converters[4] = {&fromChar, &fromInt, &fromFloat, &fromDouble};
	if (t == 4)
		std::cout << "Unknown type" << std::endl;
	else
		converters[t](arg);
	return (0);
}