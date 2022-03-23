#pragma once

#include <iostream>
#include <cmath>

class ScalarConversion
{
	private:

		bool	_intOverflow;
		bool	_floatOverflow;
		bool	_doubleOverflow;
		int		_type;
		char	_charValue;
		int		_intValue;
		float	_floatValue;
		double	_doubleValue;

	public:

		ScalarConversion();
		~ScalarConversion();
		ScalarConversion(const ScalarConversion &other);
		ScalarConversion& operator=(const ScalarConversion &other);

		double	getDouble() const;

		void	fetchValue(const char *str, int type);
		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;

		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

		class WrongUsageException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};
		class WrongEntryException : public std::exception
		{
			public:

				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const ScalarConversion &toPrint);
