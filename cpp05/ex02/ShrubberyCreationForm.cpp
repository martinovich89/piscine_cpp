#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("unknown")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:	Form(other),
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
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream		out;
	std::string const	file = _target + "_shrubbery";

	//Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres ASCII à l’intérieur.
	if (!getSign())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	
	out.open(file.c_str(), std::ofstream::trunc | std::ofstream::out);
	if (!out.is_open())
	{
		std::cerr << "Error : failed to open file" << std::endl;
		return ;
	}
	out <<	"       /\\           /\\        " << std::endl
		<<	"      /||\\         /||\\ /\\   " << std::endl
		<<	"      /||\\         /||\\/||\\  " << std::endl
		<<	"     //||\\\\       //||\\/||\\  " << std::endl
		<<	"     //||\\\\       //||//||\\\\ " << std::endl
		<<	"    ///||\\\\\\     ///||//||\\\\ " << std::endl
		<<	"       ||           |///||\\\\\\" << std::endl
		<<	"                        ||   " << std::endl;



	out.close();
	
}

std::string		ShrubberyCreationForm::getTarget() const
{
	return (_target);
}