#include "Fixed.hpp"
#include <iostream>

const int	Fixed::dec = 8;

Fixed::Fixed() : n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int val)
{
	std::cout << "int constructor is called" << std::endl;
	if (BYTE_ORDER == BIG_ENDIAN)
		this->n = val >> this->dec;
	else
		this->n = val << this->dec;
}

Fixed::Fixed(float val)
{
	std::cout << "float constructor is called" << std::endl;
	if (BYTE_ORDER == BIG_ENDIAN)
		this->n = roundf((float)val * (float)(1 >> this->dec));
	else
		this->n = roundf((float)val * (float)(1 << this->dec));
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

std::ostream	&operator <<(std::ostream &out, const Fixed &x) {
	out << x.toFloat();
	return out;
}

void	Fixed::setRawBits(int nb)
{
	this->n = nb;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->n);
}

int	Fixed::getNbBits() const
{
	return (this->dec);
}

int	Fixed::toInt(void) const
{
	if (BYTE_ORDER == BIG_ENDIAN)
		return (this->n << this->dec);
	else
		return (this->n >> this->dec);
}

float Fixed::toFloat(void) const
{
	if (BYTE_ORDER == BIG_ENDIAN)
		return (((float)(this->n) / (float)(1 >> this->dec)));
	else
		return (((float)(this->n) / (float)(1 << this->dec)));
}