#ifndef CONTACT_HPP
# define CONTACT_HPP

# define MAX_CONTACTS 8

# include "PhoneBook.hpp" 
# include <iostream>
# include <string>
# include <stdlib.h>

class Contact
{
//	Access specifier:
	private:

//	Data members:
	size_t id_;
	std::string first_name_;
	std::string last_name_;
	std::string nick_name_;
	std::string phone_number_;
	std::string darkest_secret_;

//  Access specifier:
	public:

// Member Functions()
	// Constructors
	Contact(void);
	// Setters
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nick_name(std::string nick_name);
	void set_phone_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);
	void set_id(size_t id);
	// Getters
	std::string get_first_name(void);
	std::string get_last_name(void);
	std::string get_nick_name(void);
	std::string get_phone_number(void);
	std::string get_darkest_secret(void);
	size_t get_id(void);

	void show_contact();
	void show_detailed_contact();
};

#endif
