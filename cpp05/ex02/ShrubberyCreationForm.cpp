#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("unknown")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:	Form(
		other.getName(),
		other.getSignGrade(),
		other.getExecGrade()
	),
	_target(other.getTarget())
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	//Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres ASCII à l’intérieur.
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{

}

std::string		ShrubberyCreationForm::getTarget() const
{
	return (_target);
}