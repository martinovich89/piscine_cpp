#include "Intern.hpp"

const std::string Intern::_formName[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	Form	*form;
	Form	*(Intern::*f[3])(const std::string &) = {
		&Intern::_makeShrubberyCreation,
		&Intern::_makeRobotomyRequest,
		&Intern::_makePresidentialPardon
	};

	for (unsigned i = 0; i < 3; i++)
	{
		if (!_formName[i].compare(name))
		{
			form = (this->*(f[i]))(target);
			std::cout << "Intern created " << form->getName() << std::endl;
			return (form);
		}
	}
	throw InvalidFormNameException();
	return NULL;
}

Form	*Intern::_makeShrubberyCreation(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::_makeRobotomyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::_makePresidentialPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

const char*	Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid form name");
}