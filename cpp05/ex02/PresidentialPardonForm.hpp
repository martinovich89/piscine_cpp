#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class PresidentialPardonForm : public Form
{
	private:
	void	beExecuted() const;

    public:

		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& op);

		PresidentialPardonForm(std::string const & target);
};