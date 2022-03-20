#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat JeanLaposte;
		Bureaucrat JeanBCE("Jean-BCE", 42);
		Bureaucrat JeanReptilien(JeanLaposte);
		Bureaucrat JeanAttali("Jean-Attali", 1);


		std::cout << JeanLaposte;
		JeanLaposte.upgrade();
		std::cout << "JeanLaposte promoted" << std::endl;
		std::cout << JeanLaposte << std::endl;

		std::cout << JeanBCE;
		JeanBCE.downgrade();
		std::cout << "JeanBCE dismissed" << std::endl;
		std::cout << JeanBCE << std::endl;

		
		std::cout << JeanReptilien << std::endl;
		JeanReptilien = JeanAttali;
		std::cout << JeanReptilien << std::endl;

		std::cout << JeanAttali;
		JeanAttali.upgrade();
		std::cout << "JeanAttali promoted";
		std::cout << JeanAttali << std::endl;
		
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat JeanDentsTropLongues("Jean-Dent-Trop-Longues", 0);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat JeanCancre("Jean-Cancre", 151);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}