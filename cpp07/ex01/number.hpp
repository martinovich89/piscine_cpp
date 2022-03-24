#pragma once

#include <iostream>

class Number
{
	private :

		int	_n;
	
	public :

		Number();
		~Number();
		Number(const Number &other);
		Number &operator=(const Number &other);

		Number(const int n);

		int	getNumber() const;
		void setNumber(const int n);
};

std::ostream	&operator<<(std::ostream &out, const Number &toPrint);
