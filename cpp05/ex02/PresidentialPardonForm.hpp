#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class PresidentialPardonForm : public Form
{
	private:

	std::string _target;
	void	beExecuted() const;

    public:

	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	PresidentialPardonForm(const std::string &target);
	execute(Bureaucrat const &executor);

	std::string getTarget() const;
};