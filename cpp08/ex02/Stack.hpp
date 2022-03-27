#pragma once

#include <map>
#include <algorithm>
#include <list>
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :

		MutantStack() {}
		virtual ~MutantStack() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}

		MutantStack<T>	&operator=(MutantStack const &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}

		typedef typename	std::stack<T>::container_type::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
};
