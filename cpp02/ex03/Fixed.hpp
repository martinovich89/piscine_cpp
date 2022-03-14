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
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	static Fixed max(Fixed &a, Fixed &b);
	static Fixed min(Fixed &a, Fixed &b);
	static Fixed max(const Fixed &a, const Fixed &b);
	static Fixed min(const Fixed &a, const Fixed &b);

	int	toInt(void) const;
	float toFloat(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int	getNbBits(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
