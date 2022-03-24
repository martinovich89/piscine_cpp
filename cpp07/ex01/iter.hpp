#pragma once

#include <iostream>

template<typename T>
void	iter(const T *array, const size_t length, void(*f)(const T &elem))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
	return ;
}