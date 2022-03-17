#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("unknown")
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:	Form(
		other.getName(),
		other.getSignGrade(),
		other.getExecGrade()
	),
	_target(other.getTarget())
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{

}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	//Informe que la <target> a été pardonnée par Zaphod Beeblebrox.
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (_target);
}
