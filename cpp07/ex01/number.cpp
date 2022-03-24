#include "number.hpp"

Number::Number() :  _n(0)
{

}

Number::~Number()
{

}

Number::Number(const Number &other) : _n(other._n)
{

}

Number	&Number::operator=(const Number &other)
{
	_n = other._n;
	return (*this);
}

Number::Number(const int n) : _n(n)
{

}

int	Number::getNumber() const
{
	return (_n);
}

void	Number::setNumber(const int n)
{
	_n = n;
}

std::ostream	&operator<<(std::ostream &out, const Number &toPrint)
{
	out << toPrint.getNumber();
	return (out);
}