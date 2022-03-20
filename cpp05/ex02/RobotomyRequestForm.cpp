#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("unknown")
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:	Form(other),
	_target(other.getTarget())
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestform", 72, 45), _target(target)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	//Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée avec succès 50% du temps. Dans le cas contraire, informe que l’opération a échoué
	if (!getSign())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "vwiiiiiiBRRRRRRRRRRRRRRRRiiiiiBRRRiiiiiiiBRRRRRRiiiiiBRRRRRRRRRR" << std::endl;
	if (std::time(0) % 2)
		std::cout << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << std::endl;
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (_target);
}
