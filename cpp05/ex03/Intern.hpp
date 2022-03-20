#pragma once

#include "Form.hpp"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"



class Intern
{
	private:

	static const std::string	_formName[3];
	Form						*_makeShrubberyCreation(const std::string &target);
	Form						*_makeRobotomyRequest(const std::string &target);
	Form						*_makePresidentialPardon(const std::string &target);

	public:
	
	Intern();
	virtual	~Intern();
	Intern(Intern const &other);
	Intern	&operator=(Intern const &other);

	Form	*makeForm(std::string name, std::string target);

	class InvalidFormNameException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};