#pragma once

#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

class Span
{
	private :

		unsigned			_N;
		std::vector<int>	_vec;

	public :

		Span();
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		Span(const unsigned N);

		void		addNumber(const int n);
		unsigned	longestSpan(void);
		unsigned	shortestSpan(void);

		template <class Iter>
		void	addRange(Iter begin, Iter end)
		{
			if (static_cast<unsigned>(end - begin) <= static_cast<unsigned>(_N - _vec.size()))
				_vec.insert(_vec.end(), begin, end);
			else
				throw(CantAddMoreElement());
		}

	class CantAddMoreElement : public std::exception
	{
		public :

			const char *what() const throw();
	};

	class NotEnoughElements : public std::exception
	{
		public :

			const char *what() const throw();
	};
};