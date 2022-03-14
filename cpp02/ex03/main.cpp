#include "Fixed.hpp"
#include "Point.hpp"

#define PRINT_BSP(a, b, c, p); {\
	if (bsp(a, b, c, p))\
		std::cout << "true" << std::endl;\
	else std::cout << "false" << std::endl;\
}

bool	bsp(Point a, Point b, Point c, Point p);

Point	a(1.0f, 1.0f),
		b(3.0f, 3.0f),
		c(3.0f, 1.0f),
		d(1.891623f, 1.932582f),
		e(2.0f, 2.0f),
		f(2.963530f, 1.278986f);

int	main(void) {
	PRINT_BSP(a, b, c, d);
	PRINT_BSP(a, b, c, e);
	PRINT_BSP(a, b, c, f);
	PRINT_BSP(a, b, c, a);
	PRINT_BSP(a, b, c, b);
	PRINT_BSP(a, b, c, c);
	return 0;
}