#include "ScalarConversion.hpp"
#include <cstdlib>
#include <climits>
#include <limits>
#include <cerrno>

ScalarConversion::ScalarConversion(void)
:	_intOverflow(0),
	_floatOverflow(0),
	_doubleOverflow(0),
	_type(4),
	_charValue(0),
	_intValue(0),
	_floatValue(0),
	_doubleValue(0)
{

}

ScalarConversion::ScalarConversion(const ScalarConversion &other)
:	_intOverflow(other._intOverflow),
	_floatOverflow(other._floatOverflow),
	_doubleOverflow(other._doubleOverflow),
	_type(other._type),
	_charValue(other._charValue),
	_intValue(other._intValue),
	_floatValue(other._floatValue),
	_doubleValue(other._doubleValue)
{

}

ScalarConversion::~ScalarConversion(void)
{

}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion &other)
{
	_intOverflow = other._intOverflow;
	_floatOverflow = other._floatOverflow;
	_doubleOverflow = other._doubleOverflow;
	_type = other._type;
	_charValue = other._charValue;
	_intValue = other._intValue;
	_floatValue = other._floatValue;
	_doubleValue = other._doubleValue;
	return (*this);
}

ScalarConversion::operator char() const
{
	switch (_type)
	{
		case 1:
			return (static_cast<char>(_intValue));
		case 2:
			return (static_cast<char>(_floatValue));
		case 3:
			return (static_cast<char>(_doubleValue));
		default:
			return (_charValue);
	}
}

ScalarConversion::operator int() const
{
	switch (_type)
	{
		case 0:
			return (static_cast<int>(_charValue));
		case 2:
			return (static_cast<int>(_floatValue));
		case 3:
			return (static_cast<int>(_doubleValue));
		default:
			return (_intValue);
	}
}

ScalarConversion::operator float() const
{
	switch (_type)
	{
		case 0:
			return (static_cast<float>(_charValue));
		case 1:
			return (static_cast<float>(_intValue));
		case 3:
			return (static_cast<float>(_doubleValue));
		default:
			return (_floatValue);
	}
}

ScalarConversion::operator double() const
{
	switch (_type)
	{
		case 0:
			return (static_cast<double>(_charValue));
		case 1:
			return (static_cast<double>(_intValue));
		case 2:
			return (static_cast<double>(_floatValue));
		default:
			return (_doubleValue);
	}
}

void    ScalarConversion::fetchValue(const char *str, int type)
{
    long    longValue;
	float	floatValue;
	double	doubleValue;

    _type = type;
    errno = 0;
    longValue = strtol(str, NULL, 0);
    _intOverflow = (longValue > INT_MAX || longValue < INT_MIN || errno == ERANGE);
    errno = 0;
    floatValue = strtof(str, NULL);
    _floatOverflow = (errno == ERANGE);
    errno = 0;
    doubleValue = strtod(str, NULL);
    _doubleOverflow = (errno == ERANGE);

	if (type == 0)
		_charValue = str[1];
	else if (type == 1)
		_intValue = longValue;
	else if (type == 2)
		_floatValue = floatValue;
	else if (type == 3)
		_doubleValue = doubleValue;
}

void    ScalarConversion::printChar(void) const
{
    char    c = *this;
    float    f = *this;
    double    d = *this;

    if (_type == 4 || isnanf(f) || isinff(f) || isnan(d) || isinf(d)
        || d < CHAR_MIN || d > CHAR_MAX || _intOverflow || _floatOverflow || _doubleOverflow)
        std::cout << " impossible" << std::endl;
    else if (c > 126 || c < 33)
        std::cout << " Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
}

void    ScalarConversion::printInt(void) const
{
    int        i = *this;
    float    f = *this;
    double    d = *this;

    if (_type == 4 || _intOverflow || _floatOverflow || _doubleOverflow
    || isnanf(f) || isinff(f) || isnan(d) || isinf(d))
        std::cout << " impossible" << std::endl;
    else
        std::cout << i << std::endl;
}

void    ScalarConversion::printFloat(void) const
{
    float    f = *this;
    int        i = *this;

    if (_type == 4 || (_intOverflow && _type == 1) || _floatOverflow || _doubleOverflow)
        std::cout << " impossible" << std::endl;
    else
    {
//		Uncomment to add precision, at some cost.
//		std::cout.precision(std::numeric_limits<float>::digits10);
        std::cout << f;
        if (f < 1000000 && f > -1000000 && i == f)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void    ScalarConversion::printDouble() const
{
    double    d = *this;
    int        i = *this;

    if (_type == 4 || (_intOverflow && _type == 1) || (_floatOverflow && _type == 2) || _doubleOverflow)
        std::cout << " impossible" << std::endl;
    else
    {
//		Uncomment to add precion, at some cost.
//		std::cout.precision(std::numeric_limits<double>::digits10);
        std::cout << d;
        if (d < 1000000 && d > -1000000 && i == d)
            std::cout << ".0";
        std::cout << std::endl;
    }
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
