#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

void	Bureaucrat::upgrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downgrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &someForm)
{
	try
	{
		someForm.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << someForm.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << someForm.getName() << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &toPrint)
{
	out << "Name : " << toPrint.getName() << " | Grade : " << toPrint.getGrade() << std::endl;
	return (out);
}
