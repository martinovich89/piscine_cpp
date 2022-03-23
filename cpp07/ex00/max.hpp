#pragma once

#include <iostream>

template<typename T>
const T	&max(const T &lhs, const T &rhs)
{
	return (lhs >= rhs ? lhs : rhs);
}
