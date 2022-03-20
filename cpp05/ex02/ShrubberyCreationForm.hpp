#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class ShrubberyCreationForm : public Form
{
	private:

	std::string _target;
	void	beExecuted() const;

	public:
	
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	ShrubberyCreationForm(const std::string &target);
	void execute(Bureaucrat const &executor) const;

	std::string getTarget() const;
};