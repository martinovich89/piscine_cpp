#pragma once

#include <iostream>

template<typename T>
class Array
{
	private :

		T	*_array;
		unsigned _size;

	public :

		Array() : _array(new T[0]), _size(0) {}

		~Array()
		{
			if (_array != NULL)
				delete [] _array;
		}

		Array(const Array &other) : _array(NULL), _size(0)
		{
			*this = other;
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete [] _array;
				_array = new T[other._size];
				_size = other._size;
				for (unsigned i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		}

		Array(const unsigned size) : _array(new T[size]()), _size(size) {}

		T	&operator[](const unsigned index) const
		{
			if (index < _size)
			{
				return (_array[index]);
			}
			throw OutOfRange();
		}

		unsigned	size() const { return (_size); }

		class	OutOfRange : public std::exception
		{
			public :
			
				virtual const char *what() const throw()
				{
					return ("Out of range !");
				}
		};
};