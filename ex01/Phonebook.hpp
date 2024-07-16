#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void	add(void);
	void	search(void);

private:
	Contact	contacts[8];
	int		contactCount;
	int		firstContactIndex;
};

#endif

