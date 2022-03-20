#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		std::cout << "JeanLaposte name : " << JeanLaposte.getName() << std::endl;
		std::cout << "JeanLaposte grade : " << JeanLaposte.getGrade() << std::endl;
		JeanLaposte.upgrade();
		std::cout << "JeanLaposte promoted" << std::endl;
		std::cout << "JeanLaposte grade : " << JeanLaposte.getGrade() << std::endl;

		std::cout << std::endl;

		std::cout << "JeanBCE name : " << JeanBCE.getName() << std::endl;
		std::cout << "JeanBCE grade : " << JeanBCE.getGrade() << std::endl;
		JeanBCE.downgrade();
		std::cout << "JeanBCE dismissed" << std::endl;
		std::cout << "JeanBCE grade : " << JeanBCE.getGrade() << std::endl;

		std::cout << std::endl;

		std::cout << "JeanAttali name : " << JeanAttali.getName() << std::endl;
		std::cout << "JeanAttali grade : " << JeanAttali.getGrade() << std::endl;

		std::cout << std::endl;
		
		std::cout << "JeanReptilien name : " << JeanReptilien.getName() << std::endl;
		std::cout << "JeanReptilien grade : " << JeanReptilien.getGrade() << std::endl;

		std::cout << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	ShrubberyCreationForm	a27;
	RobotomyRequestForm		b19("xXDarkSasuke98Xx");
	PresidentialPardonForm	c42("SomeTarget");
	PresidentialPardonForm	d42(c42);

	JeanAttali.signForm(d42);
	JeanAttali.executeForm(c42);
	JeanAttali.signForm(c42);
	JeanAttali.executeForm(d42);

	std::cout << std::endl;

	JeanBCE.executeForm(c42);

	std::cout << std::endl;

	JeanBCE.executeForm(a27);
	JeanBCE.signForm(a27);
	JeanBCE.executeForm(a27);

	std::cout << std::endl;

	JeanBCE.signForm(b19);
	JeanBCE.executeForm(b19);
}
