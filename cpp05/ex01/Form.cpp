#include "Form.hpp"

Form::Form()
:	_name("unnamed form"),
	_signed(0),
	_signGrade(150),
	_execGrade(150)
{

}

Form::~Form()
{
	std::cout << "Destroyed " << _name << std::endl;
}

Form::Form(const Form &other)
:	_name(other._name),
	_signed(0),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{

}

Form	&Form::operator=(const Form &other)
{
	static_cast <void>(other);
	return (*this);
}

Form::Form(
	std::string name,
	int signGrade, int execGrade
) :	_name(name),
	_signed(0),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat someBureaucrat)
{
	if (someBureaucrat.getGrade() <= _signGrade)
		_signed = 1;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high (Form)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low (Form)");
}

std::string	Form::getName() const
{
	return (_name);
}

bool				Form::getSign() const
{
	return (_signed);
}

int			Form::getSignGrade() const
{
	return (_signGrade);
}

int			Form::getExecGrade() const
{
	return (_execGrade);
}

std::ostream	&operator<<(std::ostream &out, Form &someForm)
{
	out << someForm.getName() << std::endl;
	out << someForm.getSign() << std::endl;
	out << someForm.getSignGrade() << std::endl;
	out << someForm.getExecGrade() << std::endl;
	return (out);
}