#pragma once

#include <iostream>

template<typename T>
const T	&min(const T &lhs, const T &rhs)
{
	return (lhs <= rhs ? lhs : rhs);
}
