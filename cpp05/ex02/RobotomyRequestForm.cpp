#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("unknown")
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:	Form(
		other.getName(),
		other.getSignGrade(),
		other.getExecGrade()
	),
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
	//Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée avec succès 50% du temps. Dans le cas contraire, informe que l’opération a échoué
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{

}

std::string		RobotomyRequestForm::getTarget() const
{
	return (_target);
}
