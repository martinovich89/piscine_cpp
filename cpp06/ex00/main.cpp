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
	bool dot;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-' && str[0] != '.')
		return 0;
	dot = (str[0] == '.');
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (i = 1; i < str.length() && isdigit(str[i]); i++) {}
	if (str[i] == 'f' && i == str.length() - 1)
		return (1);
	else if (str[i] != '.' || dot == 1)
		return (0);
	for (i += 1; i < str.length() && isdigit(str[i]); i++) {}
	if (str[i] != 'f' || i != str.length() - 1)
		return (0);
	return (1);
}

bool	isDouble(std::string str)
{
	size_t	i;
	bool dot = 0;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-' && str[0] != '.')
		return 0;
	dot = (str[0] == '.');
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return 0;
	for (i = 1; i < str.length() && isdigit(str[i]); i++) {}
	if (str[i] && (str[i] != '.' || dot == 1))
		return (0);
	for (i += 1; i < str.length() && isdigit(str[i]); i++) {}
	if (str[i])
		return (0);
	return (1);
}

int		isSpecial(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return 2;
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return 3;
	return 4;
}

int		noDigit(std::string str)
{
	int ret = 1;

	for (unsigned i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			ret = 0;
	}
	return (ret);
}

int		whichType(std::string str)
{
	int i;

	if ((i = isSpecial(str)) != 4)
		return (i);
	if (isChar(str))
		return (0);
	if (noDigit(str))
		return (4);
	if (isInt(str))
		return (1);
	if (isFloat(str))
		return (2);
	if (isDouble(str))
		return (3);
	return (4);
}

int main(int ac, char **av)
{
	ScalarConversion	ScalarConversion;

	try
	{
		if (ac != 2)
			throw ScalarConversion::WrongUsageException();
		int type = whichType(av[1]);
		ScalarConversion.fetchValue(av[1], type);
		std::cout << ScalarConversion;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}