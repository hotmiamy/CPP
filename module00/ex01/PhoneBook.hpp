# ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_phones[8];
		static int	_inx;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void set_contact();
		void serch_contacts();
	private:
		void get_contacts(int inx);
};


#endif