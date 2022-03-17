#include "Bureaucrat.hpp"

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
	std::cout << a27 << std::endl;
	std::cout << b19 << std::endl;
	std::cout << c42 << std::endl;
	std::cout << d19 << std::endl;

	try
	{
		a27.beSigned(JeanLaposte);
		std::cout << a27 << std::endl;
		b19.beSigned(JeanBCE);
		std::cout << b19 << std::endl;
		c42.beSigned(JeanReptilien);
		std::cout << c42 << std::endl;

		JeanBCE.downgrade();
		d19.beSigned(JeanBCE);
		std::cout << d19 << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Form e11;
	e11 = d19;
	std::cout << e11 << std::endl;

	try
	{
		JeanBCE.upgrade();
		JeanBCE.signForm(e11);
		std::cout << e11 << std::endl;
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr <<e.what() << std::endl;
	}

	try
	{
		Form f99("Interstellar Consortium Planet Annexion Treaty", 0, 0, -1);
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr <<e.what() << std::endl;
	}
	
}
