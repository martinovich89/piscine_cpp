#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	_name = other.getName();
	_grade = other.getGrade();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{

}

const char	*Bureaucrat::GradeTooHighException::what() const
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const
{
	return ("Grade is too low");
}