#pragma once

#include <iostream>

class Bureaucrat
{
	private :

	const std::string	_name;
	int			_grade;

	public :

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);

	void	downgrade();
	void	upgrade();

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

std::ostream &operator<<(std::ostream &out, Bureaucrat &toPrint);