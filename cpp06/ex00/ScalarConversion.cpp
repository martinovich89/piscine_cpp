#include "ScalarConversion.hpp"
#include <cstdlib>
#include <climits>

ScalarConversion::ScalarConversion(void) : _doubleValue(0)
{

}

ScalarConversion::ScalarConversion(const ScalarConversion &other)
{
	*this = other;
}

ScalarConversion::~ScalarConversion(void)
{

}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion &other)
{
	_doubleValue = other.getDouble();
	return (*this);
}

ScalarConversion::operator char() const
{
	return (static_cast<char>(getDouble()));
}

ScalarConversion::operator int() const
{
	return (static_cast<int>(getDouble()));
}

ScalarConversion::operator float() const {

	return (static_cast<float>(getDouble()));
}

ScalarConversion::operator double() const {

	return (static_cast<double>(getDouble()));
}

void	ScalarConversion::fetchValue(const char *str) {

	_doubleValue = atof(str);
}

void	ScalarConversion::printChar(void) const {

	char c = *this;

	if (c > 127 || c < 0 || isnan(_doubleValue) || isinf(_doubleValue))
		std::cout << " impossible" << std::endl;
	else if (c > 126 || c < 33)
		std::cout << " Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
}

void	ScalarConversion::printInt(void) const {

	int i = *this;

	if (_doubleValue > INT_MAX || _doubleValue < INT_MIN || isnan(_doubleValue))
		std::cout << " impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	ScalarConversion::printFloat(void) const {

	float	f = *this;
	int		i = *this;

	std::cout << f;
	if (i == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	ScalarConversion::printDouble() const
{
	int		i = *this;

	std::cout << _doubleValue;
	if (i == _doubleValue)
		std::cout << ".0";
	std::cout << std::endl;
}

const char* ScalarConversion::WrongUsageException::what() const throw()
{
	return ("Need one argument");
}

const char* ScalarConversion::WrongEntryException::what() const throw()
{
	return ("Invalid argument");
}

double	ScalarConversion::getDouble() const
{
	return (_doubleValue);
}

std::ostream&	operator<<(std::ostream& out, ScalarConversion const &toPrint)
{
	out << "char: ";
	toPrint.printChar();
	out << "int: ";
	toPrint.printInt();
	out << "float: ";
	toPrint.printFloat();
	out << "double: ";
	toPrint.printDouble();
	return (out);
}
