#pragma once

#include "Fixed.hpp"

class Point
{
	private:

	const Fixed x;
	const Fixed y;

	public:

	Point();
	~Point();
	Point(const Point &other);
	Point(const float x, const float y);
//	Point(const Fixed x, const Fixed y);

	Point &operator=(const Point &other);
	bool operator==(const Point &other);

	const Fixed &get_x(void) const;
	const Fixed &get_y(void) const;
	void set_x(const Fixed &f);
	void set_y(const Fixed &f);
};
