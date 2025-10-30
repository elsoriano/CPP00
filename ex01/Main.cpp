#include <iostream>
#include <string>
#include <sstream>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int		ft_check_input(std::string name, std::string input)
{
	if (input.empty())
	{
		std::cout << name << " cannot be empty. Contact not added." << std::endl;
		return (1);
	}
	return (0);
};

void	ft_add_contact(PhoneBook &phonebook)
{
	std::string name, lastname, nickname, phone_number, darkest_secret;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, name);
	if(ft_check_input("First Name", name))
		return;
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastname);
	if(ft_check_input("Last Name", lastname))
		return;
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	if(ft_check_input("Nickname", nickname))
		return;
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phone_number);
	if(ft_check_input("Phone Number", phone_number))
		return;
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
	if(ft_check_input("Darkest Secret", darkest_secret))
		return;
	Contact new_contact(name, lastname, nickname, phone_number, darkest_secret);
	new_contact.setIndex(phonebook.getContactCount());
	phonebook.addContact(new_contact);
};

int	ft_search_contact(PhoneBook &phonebook)
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
			std::cerr << "Error: Invalid input. Please enter a valid index. Exiting SEARCH" << std::endl;
			return (1);
		}
		Contact contact = phonebook.displayContact(index);
		if (contact.getName() == "")
		{
			std::cout << "Exiting SEARCH" << std::endl;
			return (1);
		}
		std::cout << "First Name: " << contact.getName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nickname: " << contact.getNickname() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	}
	return (0);
};

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
			if (ft_search_contact(phonebook))
				continue;
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	
	return (0);
};
