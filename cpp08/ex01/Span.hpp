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
		void		addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned	longestSpan(void);
		unsigned	shortestSpan(void);

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