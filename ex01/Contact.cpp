#include "Contact.hpp"

Contact::Contact(std::string name, std::string lastname, 
	std::string nickname, std::string phone_number, 
	std::string darkest_secret)
{
	this->name = name;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	index = 0;
}
Contact::Contact()
{
	this->name = "";
	this->lastname = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
	index = 0;
}
Contact::~Contact(){return ;}

std::string	Contact::getName() const
{
	return (this->name);
};
std::string	Contact::getLastName() const
{
	return (this->lastname);
};
std::string	Contact::getNickname() const
{
	return (this->nickname);
};
std::string	Contact::getPhoneNumber() const
{
	return (this->phone_number);
};
std::string	Contact::getDarkestSecret() const
{
	return (this->darkest_secret);
};
void	Contact::setIndex(int idx)
{
	this->index = idx;
};
int		Contact::getIndex() const
{
	return (this->index);
};