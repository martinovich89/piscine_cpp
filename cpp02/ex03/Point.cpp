#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point	&Point::operator=(const Point &other)
{
/*	this->set_x(other.get_x());
	this->set_y(other.get_y());*/
	(void)other;
	return *this;
}

bool	Point::operator==(const Point &other)
{
	return this->get_x() == other.get_x() && this->get_y() == other.get_y();
}

const Fixed	&Point::get_x(void) const
{
	return (this->x);
}

const Fixed	&Point::get_y(void) const
{
	return (this->y);
}

/*void	Point::set_x(const Fixed &val)
{
	this->get_x().setRawBits(val.getRawBits());
}

void	Point::set_y(const Fixed &val)
{
	this->get_y().setRawBits(val.getNbBits());
}*/