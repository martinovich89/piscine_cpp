#pragma once

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

		typedef typename	std::stack<T>::container_type::iterator					iterator;
		typedef typename	std::stack<T>::container_type::const_iterator			citerator;
		typedef typename	std::stack<T>::container_type::reverse_iterator			riterator;
		typedef typename	std::stack<T>::container_type::const_reverse_iterator	criterator;

		iterator	begin() { return (this->c.begin()); }

		iterator	end() { return (this->c.end()); }

		citerator	begin() const { return (this->c.begin()); }

		citerator	end() const { return (this->c.end()); }

		riterator	rbegin() { return (this->c.rbegin()); }

		riterator	rend() { return (this->c.rend()); }

		criterator	rbegin() const { return (this->c.rbegin()); }

		criterator	rend() const { return (this->c.rend()); }
};
