#pragma once

#include <stdio.h>

template<typename T>
void	swap(T &var1, T &var2)
{
	T tmp = var1;

	var1 = var2;
	var2 = tmp;
}
