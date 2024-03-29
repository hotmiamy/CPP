#include "Contact.hpp"

Contact::~Contact() {}

Contact::Contact(void)
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

void Contact::set_first_name(std::string first_name) {
	this->_first_name = first_name;
}

void Contact::set_last_name(std::string last_name) {
	this->_last_name = last_name;
}

void Contact::set_nickname(std::string nickname) {
	this->_nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number) {
	this->_phone_number = phone_number;
}

void Contact::set_dark_secret(std::string darkerst_secret) {
	this->_darkest_secret = darkerst_secret;
}

std::string Contact::get_first_name(void) {
	return(this->_first_name);
}

std::string Contact::get_last_name(void) {
	return(this->_last_name);
}

std::string Contact::get_nickname(void) {
	return(this->_nickname);
}

std::string Contact::get_phone_number(void) {
	return(this->_phone_number);
}
