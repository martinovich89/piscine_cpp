#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat JeanLaposte;
		Bureaucrat JeanBCE("Jean-BCE", 42);
		Bureaucrat JeanAttali("Jean-Attali", 1);
		Bureaucrat JeanReptilien(JeanAttali);


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

		JeanAttali.upgrade();
		std::cout << "JeanAttali promoted";
		
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
		Bureaucrat JeanCancrelas("Jean-Cancrelas", 151);
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