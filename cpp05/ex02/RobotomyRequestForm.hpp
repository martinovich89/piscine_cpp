#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class RobotomyRequestForm : public Form
{
	private:

	std::string _target;
	void	beExecuted() const;

	public:

	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	RobotomyRequestForm(const std::string &target);
	void execute(Bureaucrat const &executor) const;

	std::string getTarget() const;
};
