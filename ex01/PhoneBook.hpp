#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int     contact_count;
public:
	PhoneBook();
	~PhoneBook();
	void    addContact(const Contact &new_contact);
	void    displayContacts() const;
	Contact	displayContact(int index) const;
	int     getContactCount() const;
};

#endif