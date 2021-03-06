#pragma once

#include <iostream>
#include <cmath>
#include <endian.h>


class Fixed
{
	private:
	int n;
	static const int dec;

	public:
	Fixed();
	Fixed(int val);
	Fixed(float val);
	Fixed(const Fixed&);
	~Fixed();
	Fixed &operator=(const Fixed &bp);

	int	toInt(void) const;
	float toFloat(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int	getNbBits(void) const;
};

std::ostream	&operator <<(std::ostream &out, const Fixed &x);