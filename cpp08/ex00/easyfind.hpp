#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <list>

class NumberNotFoundException : public std::exception
{
	public :

		const char *what() const throw ()
		{
			return ("Couldn't find the required value in container");
		}
};

template<typename T>
void	easyfind(T &box, int n)
{
	typename T::iterator it = std::find(box.begin(), box.end(), n);

	if (it == box.end())
		throw NumberNotFoundException();
	std::cout << "Found " << n << " in container" << std::endl; 
}