#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}
PhoneBook::~PhoneBook(void) {}

int PhoneBook::_inx = 0;

std::string non_empty_loop(std::string str)
{
	std::string cmd;

	while (true)
	{
		std::cout << str;
		std::getline(std::cin, cmd);
		if (!cmd.empty())
			break;
	}
	return (cmd);
}

void PhoneBook::set_contact()
{
	static int inx;
	
	if (inx > 7 || this->_inx == -1)
		inx = 0;
	_phones[inx].set_first_name(non_empty_loop("First Name: "));
	_phones[inx].set_last_name(non_empty_loop("Last Name: "));
	_phones[inx].set_nickname(non_empty_loop("Nickame: "));
	_phones[inx].set_phone_number(non_empty_loop("Phones Number: "));
	_phones[inx].set_dark_secret(non_empty_loop("Darkest secret: "));
	if (_inx <= 7)
		this->_inx++;
	inx++;
}

void contact_format(std::string str)
{
	if (str.size() >= 10)
		std::cout << std::setw(10) << std::right << str.substr(0, 9) + '.' +  '|';
	else
		std::cout << std::setw(10) << std::right << str << "|";
}

void PhoneBook::get_contacts(int inx)
{
	if (inx >= 0 && inx <= 7)
	{
		std::cout << _phones[inx].get_first_name() << std::endl;
		std::cout << _phones[inx].get_last_name() << std::endl;
		std::cout << _phones[inx].get_nickname() << std::endl;
		std::cout << _phones[inx].get_phone_number() << std::endl;
	}
	else
		std::cout << "index is invalid" << std::endl;
}

void PhoneBook::serch_contacts()
{
	char selec_inx;
	int inx;

	inx = 0;
	if (inx == -1)
	{
		std::cout << "The phonebook is empty, use ADD command" << std::endl;
		return ;
	}
	std::cout << "     Index|   F. Name| Last Name|  Nickname| P. Number|" << std::endl;
	while (inx < _inx)
	{
		std::cout << std::setw(10) << std::right << inx + 1  << "|";
		contact_format(_phones[inx].get_first_name());
		contact_format(_phones[inx].get_last_name());
		contact_format(_phones[inx].get_nickname());
		contact_format(_phones[inx].get_phone_number());
		inx++;
		std::cout << std::endl;
	} 
	std::cout << "Select a contact index: ";
	std::cin >> selec_inx;
	get_contacts((selec_inx - '0') - 1);
}

