#include "Phonebook.hpp"

std::string	get_pn(std::string field)
{
	std::string	input;

	while (1)
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else
			std::cin.clear();
		if (input.find_first_not_of("0123456789") != std::string::npos)
			std::cout << field << " can only contain numbers" << std::endl;
		else if (input.length() != 10 && input.length() != 9)
			std::cout << field << " must be 9 or 10 digits" << std::endl;
		else
			return (input);
	}
	return ("");
}

std::string	get_nk(std::string field)
{
	std::string	input;

	while (1)
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else
			std::cin.clear();
		if (input.length() == 0)
			std::cout << field << " cannot be empty" << std::endl;
		else
			return (input);
	}
	return ("");
}

std::string	get_pb(std::string field)
{
	std::string	input;

	while (1)
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else
			std::cin.clear();
		if (input.length() == 0)
			std::cout << field << " cannot be empty" << std::endl;
		else if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
			std::cout << field << " can only contain letters" << std::endl;
		else
			return (input);
	}
	return ("");
}

void	PhoneBook::add(void)
{
	int index = this->contactCount;
	
	if (index == 8)
	{
		index = this->firstContactIndex;
		this->firstContactIndex++;
	}
	else
		this->contactCount++;

	this->contacts[index].setFirstName(get_pb("First name"));
	this->contacts[index].setLastName(get_pb("Last name"));
	this->contacts[index].setNickname(get_nk("Nickname"));
	this->contacts[index].setPhoneNumber(get_pn("Phone number"));
	this->contacts[index].setDarkestSecret(get_nk("Darkest secret"));
}

void	PhoneBook::search(void)
{
	if (this->contactCount == 0)
	{
		std::cout << "Phone Book is empty" << std::endl;
		return ;
	}
	std::cout << "  index   |first name|last name | nickname " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	int	i = 0;
	
	while (i < this->contactCount)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (this->contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(9) << this->contacts[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->contacts[i].getFirstName().substr(0, 10) << "|";
		if (this->contacts[i].getLastName().length() > 10)
			std::cout << std::setw(9) << this->contacts[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->contacts[i].getLastName().substr(0, 10) << "|";
		if (this->contacts[i].getNickname().length() > 10)
			std::cout << std::setw(9) << this->contacts[i].getNickname().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << this->contacts[i].getNickname().substr(0, 10) << std::endl;
		i++;
	}
	while (1)
	{
		std::string	index;
		std::cout << "Enter an index: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			break ;
		else
			std::cin.clear();
		if (index.length() > 1 || index[0] < '1' || index[0] > '8')
		{
			std::cout << "Invalid index" << std::endl;
			continue ;
		}
		else
			i = index[0] - '0';
		if (i > 0 && i <= this->contactCount)
		{
			std::cout << "First Name: " << this->contacts[i - 1].getFirstName() << std::endl;
			std::cout << "Last Name: " << this->contacts[i - 1].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[i - 1].getNickname() << std::endl;
			std::cout << "Phone Number: " << this->contacts[i - 1].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << this->contacts[i - 1].getDarkestSecret() << std::endl;
			return ;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		else
			std::cin.clear();
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
			phoneBook.add();
		else if (cmd == "SEARCH")
			phoneBook.search();
		else
			std::cout << "Invalid command, please type: 'EXIT', 'ADD' or 'SEARCH'" << std::endl;
	}
	return (0);
}