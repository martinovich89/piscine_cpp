#include "Utils.hpp"

unsigned my_abs(int n)
{
	unsigned abs = n * (n >= 0) * 2 - n;
	return (abs);
}

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}