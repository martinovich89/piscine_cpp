#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>

class PhoneBook
{
	public:

	Contact Contactlist[MAX_CONTACTS];
	size_t amount;

	PhoneBook(void);
	void new_contact(void);
	void add_contact(void);
	void show_contactlist(void);
	void show_contact(int index);
	int check_index_validity(std::string index);
};

#endif
