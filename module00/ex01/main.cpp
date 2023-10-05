#include "PhoneBook.hpp"

int main(void)
{
	std::string cmd;
	PhoneBook contacts;

	std::cout << "Welcome to your PhoneBook" << std::endl;
	while (true)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Enter a Command: ";
		std::cin >> cmd;
		if (!cmd.find("ADD"))
		{
			std::cin.ignore();
			contacts.set_contact();
		}
		else if (!cmd.find("SEARCH"))
			contacts.serch_contacts();
		else if (!cmd.find("EXIT"))
			break ;
	}
	return (0);
}
