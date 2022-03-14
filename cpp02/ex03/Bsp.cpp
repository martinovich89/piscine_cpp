#include "Point.hpp"

static Fixed side (const Point a, const Point b, const Point c)
{
    return (a.get_x() - c.get_x()) * (b.get_y() - c.get_y()) - (b.get_x() - c.get_x()) * (a.get_y() - c.get_y());
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed d1, d2, d3;
    bool left, right;

    d1 = side(point, a, b);
    d2 = side(point, b, c);
    d3 = side(point, c, a);

    left = (d1 < 0) || (d2 < 0) || (d3 < 0);
    right = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (d1 == 0 || d2 == 0 || d3 == 0)
        return (false);
    return !(left && right);
}