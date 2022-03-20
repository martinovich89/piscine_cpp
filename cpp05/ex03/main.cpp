#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

int main(void)
{
	Bureaucrat JeanLaposte;
	Bureaucrat JeanBCE("Jean-BCE", 42);
	Bureaucrat JeanAttali("Jean-Attali", 1);
	Bureaucrat JeanReptilien(JeanAttali);

	try
	{
		std::cout << JeanLaposte;
		JeanLaposte.upgrade();
		std::cout << "JeanLaposte promoted" << std::endl;
		std::cout << JeanLaposte << std::endl;

		std::cout << JeanBCE;
		JeanBCE.downgrade();
		std::cout << "JeanBCE dismissed" << std::endl;
		std::cout << JeanBCE << std::endl;

		std::cout << JeanAttali << std::endl;
		
		std::cout << JeanReptilien << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Form	*a27;
	Form	*b19;
	Form	*c42;
	Form	*error;

	Intern	someIntern;

	try
	{
		a27 = someIntern.makeForm("shrubbery creation", "unknown");
		b19 = someIntern.makeForm("robotomy request", "xXDarkSasuke98Xx");
		c42 = someIntern.makeForm("presidential pardon", "SomeTarget");

		JeanAttali.executeForm(*c42);
		JeanAttali.signForm(*c42);
		JeanAttali.executeForm(*c42);

		std::cout << std::endl;

		JeanBCE.executeForm(*c42);

		std::cout << std::endl;

		JeanBCE.executeForm(*a27);
		JeanBCE.signForm(*a27);
		JeanBCE.executeForm(*a27);

		std::cout << std::endl;

		JeanBCE.signForm(*b19);
		JeanBCE.executeForm(*b19);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		error = someIntern.makeForm("wrong name", "nobody");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete a27;
	delete b19;
	delete c42;
	
	return (0);
}
