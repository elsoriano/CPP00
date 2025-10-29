#include <string>
#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
};
PhoneBook::~PhoneBook()
{
};
void PhoneBook::addContact(const Contact &new_contact)
{
	if (contact_count < 8)
	{
		contacts[contact_count] = new_contact;
		contact_count++;
	}
	else
	{
		for (int i = 1; i < 8; i++)
		{
			contacts[i - 1] = contacts[i];
			contacts[i - 1].setIndex(i - 1);
		}
		contacts[7] = new_contact;
	}
};
void PhoneBook::displayContacts() const
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << contacts[i].getIndex() << "|";
		std::string first_name = contacts[i].getName();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::string last_name = contacts[i].getLastName();
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";
		std::string nickname = contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << "|" << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
};
Contact PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= contact_count)
	{
		std::cerr << "Error: Invalid contact index." << std::endl;
		return (Contact());
	}
	return (contacts[index]);
}
int PhoneBook::getContactCount() const
{
	return (contact_count);
}