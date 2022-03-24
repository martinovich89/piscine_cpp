#pragma once

#include <iostream>

template<typename T>
void	printeven(T const &toPrint)
{
	if (toPrint % 2 == 0)
		std::cout << toPrint << std::endl;
}
