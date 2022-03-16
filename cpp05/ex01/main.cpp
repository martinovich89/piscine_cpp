#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form a27;
	Form b19("Mecanisme Europeen de Stabilite", 0, 43, 42);
	Form c42("Rachat de Activision-Blizzard", 0, 1, 1);
	Form d19(b19);

	try
	{
		a27.beSigned(JeanLaposte);
		b19.beSigned(JeanBCE);
		c42.beSigned(JeanReptilien);

		b19.beSigned(JeanBCE);
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}	
}
