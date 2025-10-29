#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string name;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int			index;
public:
	Contact(std::string name, std::string lastname, \
		std::string nickname, std::string phone_number, \
		std::string darkest_secret);
	Contact();
	~Contact();
	std::string	getName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	void		setIndex(int idx);
	int			getIndex() const;
};
#endif
