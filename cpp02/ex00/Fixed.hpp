#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

class Fixed
{
	private:
	int n;
	static const int dec;

	public:
	Fixed();
	Fixed(const Fixed&);
	~Fixed();
	Fixed &operator=(const Fixed &bp);

	int getRawBits(void) const;
	void setRawBits(int const val);
};