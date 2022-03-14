#include "Fixed.hpp"
#include <iostream>

const int	Fixed::dec = 8;

Fixed::Fixed() : n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &bp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = bp;
}

Fixed	&Fixed::operator=(const Fixed &bp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->n = bp.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const nb)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->n = nb;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->n);
}