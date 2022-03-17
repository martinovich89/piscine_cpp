#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class RobotmyRequestForm : public Form
{
	private:

	void	beExecuted() const;

	public:

	RobotmyRequestForm();
	RobotmyRequestForm(const RobotmyRequestForm &other);
	virtual ~RobotmyRequestForm();
	RobotmyRequestForm &operator=(const RobotmyRequestForm& other);

	RobotmyRequestForm(const std::string &name);
};
