#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class ShrubberyCreationForm : public Form
{
	private:

	void	beExecuted() const;

	public:
	
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);


	ShrubberyCreationForm(std::string const & target);
};