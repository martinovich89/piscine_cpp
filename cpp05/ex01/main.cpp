#include "Bureaucrat.hpp"

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

		std::cout << JeanReptilien;

		std::cout << JeanAttali;
		JeanAttali.upgrade();
		std::cout << "JeanAttali dismissed" << std::endl;
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

	std::cout << std::endl;

	Form a27;
	Form b19("Mecanisme Europeen de Stabilite", 43, 42);
	Form c42("Rachat de Activision-Blizzard", 1, 1);
	Form d19(b19);
	std::cout << a27 << std::endl;
	std::cout << b19 << std::endl;
	std::cout << c42 << std::endl;
	std::cout << d19 << std::endl;

	JeanLaposte.signForm(a27);
	std::cout << a27 << std::endl;
	JeanBCE.signForm(b19);
	std::cout << b19 << std::endl;
	JeanReptilien.signForm(c42);
	std::cout << c42 << std::endl;

	JeanBCE.downgrade();
	std::cout << "JeanBCE dismissed" << std::endl;
	JeanBCE.signForm(d19);
	std::cout << d19 << std::endl;

	JeanBCE.upgrade();
	JeanBCE.signForm(d19);
	std::cout << d19 << std::endl;

	try
	{
		Form f99("Interstellar Consortium Planet Annexion Treaty", 0, -1);
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);	
}
