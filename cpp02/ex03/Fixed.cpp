#include "Fixed.hpp"

const int	Fixed::dec = 8;

Fixed::Fixed() : n(0)
{
}

Fixed::Fixed(int val)
{
	if (BYTE_ORDER == BIG_ENDIAN)
		this->n = val >> this->dec;
	else
		this->n = val << this->dec;
}

Fixed::Fixed(float val)
{
	if (BYTE_ORDER == BIG_ENDIAN)
		this->n = roundf((float)val * (float)(1 >> this->dec));
	else
		this->n = roundf((float)val * (float)(1 << this->dec));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	this->n = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits(this->n + other.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits(this->n - other.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed tmp;

	if (BYTE_ORDER == BIG_ENDIAN)
		tmp.setRawBits(((int64_t)this->n * (int64_t)other.getRawBits()) / (1 >> 8));
	else
		tmp.setRawBits(((int64_t)this->n * (int64_t)other.getRawBits()) / (1 << 8));
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed tmp;

	if (BYTE_ORDER == BIG_ENDIAN)
		tmp.setRawBits(((int64_t)this->n * (1 >> 8)) / other.getRawBits());
	else
		tmp.setRawBits(((int64_t)this->n * (1 << 8)) / other.getRawBits());
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
   this->n++;
   return (*this);
}

Fixed	Fixed::operator++(int)
{
   Fixed tmp = *this;
   ++*this;
   return tmp;
}

Fixed	&Fixed::operator--(void)
{
   this->n--;
   return (*this);
}

Fixed	Fixed::operator--(int)
{
   Fixed tmp = *this;
   --*this;
   return tmp;
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->n == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->n != other.getRawBits());
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->n > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->n < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->n >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->n <= other.getRawBits());
}

std::ostream	&operator <<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
	return (a >= b ? a : b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	else
		return b;
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	else
		return b;
}

void	Fixed::setRawBits(int nb)
{
	this->n = nb;
}

int		Fixed::getRawBits() const
{
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