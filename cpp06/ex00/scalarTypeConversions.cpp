#include "scalarTypeConversions.hpp"

static int	isValidNumberFormat(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	if ((str[0] == '+' || str[0] == '-') && str.length() < 2)
		return (0);
	return (1);
}

bool	isChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

bool	isInt(std::string str)
{
	if (!isValidNumberFormat(str))
		return (0);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

bool	isFloat(std::string str)
{
	bool	dot = 0;

	if (!isValidNumberFormat(str))
		return (0);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			continue ;
		else if (str[i] == '.' && dot == 0)
			dot = 1;
		else if (str[i] == 'f' && i == str.length() - 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

bool	isDouble(std::string str)
{
	bool	dot = 0;

	if (!isValidNumberFormat(str))
		return (0);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			continue ;
		else if (str[i] == '.' && dot == 0)
			dot = 1;
		else
			return (0);
	}
	return (1);
}

/*bool	isFloat(std::string str)
{
	size_t	i;
	bool	dot = 0;

	if (!isValidNumberFormat(str))
		return (0);
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.')
			{
				if (dot)
					return (0);
				dot = 1;
			}
			else
				return (0);
		}
	}
	return (0);
}

bool	isDouble(std::string str)
{
	size_t	i;
	bool	dot = 0;

	if (!isValidNumberFormat(str))
		return (0);
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (dot)
					return (0);
				dot = 1;
			}
			else
				return (0);
		}
	}
	return (1);
}*/

static int		isSpecial(std::string str)
{
	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return (2);
	if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("nan"))
		return (3);
	return (4);
}

void fromInt(std::string const &str)
{
	double d = strtod(str.c_str(), NULL);

	if ( d < 0. || d > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	if ( d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void fromChar(std::string const &str)
{
	char c = str[1];
	if (static_cast<int> (c) < 32 || static_cast<int> (c)  > 126)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void fromFloat(std::string const &str)
{
	double d = strtod(str.c_str(), NULL);

	if (!str.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
		return;
	}
	if ( d < 0. || d > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	if ( d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
    
	std::cout << std::fixed << std::setprecision(2) << static_cast<float>(d) << std::endl;
}

void fromDouble(std::string const &str)
{
	double d = strtod(str.c_str(), NULL);

	if (!str.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
		return;
	}

	if ( d < 0. || d > 255.)
		std::cout << "char: Out of range" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	if ( d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

int		whichType(std::string str)
{
	int i;

	if ((i = isSpecial(str)) != 4)
		return (i);
	if (isChar(str))
		return (0);
	if (isInt(str))
		return (1);
	if (isFloat(str))
		return (2);
	if (isDouble(str))
		return (3);
	return (4);
}