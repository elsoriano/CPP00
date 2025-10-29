#include <iostream>
#include <string>
#include <sstream>

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	ft_add_contact(PhoneBook &phonebook)
{
	std::string name, lastname, nickname, phone_number, darkest_secret;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, name);
	if(name.empty())
	{
		std::cout << "First Name cannot be empty. Contact not added." << std::endl;
		return;
	}
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastname);
	if (lastname.empty())
	{
		std::cout << "Last Name cannot be empty. Contact not added." << std::endl;
		return;
	}
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "Nickname cannot be empty. Contact not added." << std::endl;
		return;
	}
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty())
	{
		std::cout << "Phone Number cannot be empty. Contact not added." << std::endl;
		return;
	}
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.empty())
	{
		std::cout << "Darkest Secret cannot be empty. Contact not added." << std::endl;
		return;
	}
	Contact new_contact(name, lastname, nickname, phone_number, darkest_secret);
	new_contact.setIndex(phonebook.getContactCount());
	phonebook.addContact(new_contact);
}

int	main(void)
{
	PhoneBook	phonebook;
	
	std::string command;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			ft_add_contact(phonebook);
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			std::cout << "Enter the index of the contact to view details: ";
			std::string index_str;
			if (std::getline(std::cin, index_str))
			{
				std::stringstream ss(index_str);
				int index;
				if (!(ss >> index))
				{
					std::cerr << "Error: Invalid input. Please enter a valid index." << std::endl;
					continue;
				}
				Contact contact = phonebook.displayContact(index);
				if (contact.getName() != "")
				{
					std::cout << "First Name: " << contact.getName() << std::endl;
					std::cout << "Last Name: " << contact.getLastName() << std::endl;
					std::cout << "Nickname: " << contact.getNickname() << std::endl;
					std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
					std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
				}
			}
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	
	return (0);
}