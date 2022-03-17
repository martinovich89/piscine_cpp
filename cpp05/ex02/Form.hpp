#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private :

	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;

	public :

	Form();
	virtual ~Form() = 0;
	Form(const Form &other);
	Form &operator=(const Form &other);

	Form(std::string name, bool sign, int signGrade, int execGrade);

	void beSigned(Bureaucrat someBureaucrat);

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	std::string	getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

};

std::ostream	&operator<<(std::ostream &out, Form &someForm);
