#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("unknown")
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
:	Form(other),
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

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSign())
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (_target);
}
