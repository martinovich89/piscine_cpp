#pragma once

#include "Form.hpp"
#include <iostream>

class Bureaucrat
{
	private :

	std::string	_name;
	int			_grade;

	public :

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);

	void	downgrade();
	void	upgrade();
	void	signForm(Form &someForm);

	std::string getName() const;
	int	getGrade() const;

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
};