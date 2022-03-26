#include "Span.hpp"
#include "Utils.hpp"

Span::Span() : _N(0)
{

}

Span::~Span()
{

}

Span::Span(const Span &other) : _N(0)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_N = other._N;
	_vec = other._vec;
	return (*this);
}

Span::Span(const unsigned N) : _N(N)
{

}

void	Span::addNumber(const int n)
{
	if (_vec.size() < _N)
		_vec.push_back(n);
	else
		throw CantAddMoreElement();
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (static_cast<unsigned>(end - start) <= static_cast<unsigned>(_N - _vec.size()))
		_vec.insert(_vec.end(), start, end);
	else
		throw(CantAddMoreElement());
}

unsigned	Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw NotEnoughElements();
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}

unsigned	Span::shortestSpan(void)
{
	unsigned min_span = longestSpan();
	std::vector<int> tmp = _vec;

	std::sort(tmp.begin(), tmp.end());
	for ( std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++ )
	{
		if ( static_cast<unsigned int>(*(it + 1) - *it) < min_span )
			min_span = static_cast<unsigned int>(*(it + 1) - *it);
	}

	return (min_span);
}

const char 	*Span::CantAddMoreElement::what() const throw()
{
	return ("Can't add more element");
}

const char 	*Span::NotEnoughElements::what() const throw()
{
	return ("Not enough elements. Need at least 2");
}
