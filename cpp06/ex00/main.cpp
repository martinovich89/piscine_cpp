#include "ScalarConversion.hpp"

bool	isChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return 1;
	return 0;
}

bool	isInt(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	isFloat(std::string str)
{
	size_t	i;
	bool	d = 0;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.')
			{
				if (d)
					return 0;
				d = 1;
			}
			else
				return 0;
		}
	}
	return 0;
}

bool	isDouble(std::string str)
{
	size_t	i;
	bool	d = 0;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (d)
					return 0;
				d = 1;
			}
			else
				return 0;
		}
	}
	return 1;
}

int		checkException(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return 2;
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return 3;
	return 4;
}

int		whichType(std::string str)
{
	int i;

	if ((i = checkException(str)) != 4)
		return i;
	if (isChar(str))
		return 0;
	if (isInt(str))
		return 1;
	if (isFloat(str))
		return 2;
	if (isDouble(str))
		return 3;
	return 4;
}

int main(int ac, char **av)
{
	ScalarConversion	ScalarConversion;

	try
	{
		if (ac != 2)
			throw ScalarConversion::WrongUsageException();
		int type = whichType(av[1]);
		std::cout << type << std::endl;
		ScalarConversion.fetchValue(av[1]);
		std::cout << ScalarConversion;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}