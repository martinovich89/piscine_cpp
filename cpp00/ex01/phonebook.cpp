#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::set_first_name(std::string first_name) { first_name_ = first_name; }
void Contact::set_last_name(std::string last_name) { last_name_ = last_name; }
void Contact::set_nick_name(std::string nick_name) { nick_name_ = nick_name; }
void Contact::set_phone_number(std::string phone_number) { phone_number_ = phone_number; }
void Contact::set_darkest_secret(std::string darkest_secret) { darkest_secret_ = darkest_secret; }
void Contact::set_id(size_t id) { id_ = id; }
std::string Contact::get_first_name(void) { return (first_name_); }
std::string Contact::get_last_name(void) { return (last_name_); }
std::string Contact::get_nick_name(void) { return (nick_name_); }
std::string Contact::get_phone_number(void) { return (phone_number_); }
std::string Contact::get_darkest_secret(void) { return (darkest_secret_); }
size_t Contact::get_id(void) { return (id_); }

void	display_str(std::string to_print)
{
	std::string spaces = "          ";

	if (to_print.length() < 10)
		std::cout << spaces.substr(0, 10 - to_print.length());
	std::cout << to_print.substr(0, 9);
	if (to_print.length() > 10)
		std::cout << ".";
	else if (to_print.length() == 10)
		std::cout << to_print[9];
}

void Contact::show_contact()
{
	char index[2] = {id_ + '1', '\0'};
	display_str(index);
	std::cout << "|";
	display_str(get_first_name());
	std::cout << "|";
	display_str(get_last_name());
	std::cout << "|";
	display_str(get_nick_name());
	std::cout << "|";
	display_str(get_phone_number());
	std::cout << "\n";
}

Contact::Contact(void)
{
	first_name_ = "";
	last_name_ = "";
	nick_name_ = "";
	phone_number_ = "";
	darkest_secret_ = "";
}

PhoneBook::PhoneBook(void)
{
	amount = 0;
}

void PhoneBook::add_contact(void)
{
	std::string input;

	std::cout << "Enter first name :\n";
	std::getline(std::cin, input);
	Contactlist[amount].set_first_name(input);
	std::cout << "Enter last name :\n";
	std::getline(std::cin, input);
	Contactlist[amount].set_last_name(input);
	std::cout << "Enter nickname name :\n";
	std::getline(std::cin, input);
	Contactlist[amount].set_nick_name(input);
	std::cout << "Enter phone number :\n";
	std::getline(std::cin, input);
	Contactlist[amount].set_phone_number(input);
	std::cout << "Enter darkest secret :\n";
	std::getline(std::cin, input);
	Contactlist[amount].set_darkest_secret(input);
	Contactlist[amount].set_id(amount);
	amount++;
}

void PhoneBook::new_contact(void)
{
	if (amount < MAX_CONTACTS)
		add_contact();
	else
		std::cout << "Can't add any new contact. Phonebook is full.\n";
}

void PhoneBook::show_contactlist()
{
	for (size_t i = 0; i < amount; i++)
	{
		Contactlist[i].show_contact();
	}
}

int PhoneBook::check_index_validity(std::string index)
{
	if (index.length() != 1 || index[0] < '1' || index[0] > '8' || size_t(index[0] - '0') > amount)
		return (1);
	return (0);
}

void Contact::show_detailed_contact()
{
	std::cout << get_first_name() << "\n";
	std::cout << get_last_name() << "\n";
	std::cout << get_nick_name() << "\n";
	std::cout << get_phone_number() << "\n";
	std::cout << get_darkest_secret() << "\n";
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::string input_cmd = "";
	std::string index = "";
	PhoneBook my_phonebook;

	std::cout << "===================================\n";
	std::cout << "Welcome to your awesome phonebook !\n";
	std::cout << "===================================\n\n";

	while (input_cmd.compare("EXIT") != 0)
	{
		if (input_cmd.compare("ADD") == 0)
		{
			my_phonebook.new_contact();
		}
		else if (input_cmd.compare("SEARCH") == 0)
		{
			my_phonebook.show_contactlist();
			std::cout << "Please enter the index of the contact you want to search\n";
			std::getline(std::cin, index);
			while (my_phonebook.check_index_validity(index))
			{
				std::cout << "Please enter a valid index\n";
				my_phonebook.show_contactlist();
				std::getline(std::cin, index);
			}
			my_phonebook.Contactlist[index[0] - '1'].show_detailed_contact();
		}
		input_cmd = "";
		index = "";
		std::cout << "Please type \"ADD\", \"SEARCH\", or \"EXIT\".\n";
		std::getline(std::cin, input_cmd);
	}
	return (0);
}
