/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:59:50 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/07 16:06:29 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

static bool isEmpty(std::string data) {
	for (size_t i = 0; i < data.length(); i++) {
		if ((data[i] > 13 || data[i] < 9) && data[i] != 32) return false;
	}
	return true;
}

std::string getInput(std::string data)
{
	std::string input;
	std::cout << data;
	std::getline(std::cin, input);
	if (std::cin.eof()) exit(0);
	while (isEmpty(input)) {
		std::cout << "Empty field, try again\n";
		std::cout << data;
		std::getline(std::cin, input);
		if (std::cin.eof()) exit(0);
		continue ;
	}
	return input;
}

void displayPart(std::string part)
{
	std::cout << std::right << std::setw(10);
	if (part.length() > 10) {
		part.resize(9);
		part += '.';
	}
	std::cout << part << '|';
}

bool displayAll(PhoneBook& phonebook)
{
	int length = phonebook.getNumberOfContacts();

	if (length == 0) {
		std::cout << "Empty list" << std::endl;
		return false;
	}
	else {
		displayPart("index");
		displayPart("first name");
		displayPart("last name");
		displayPart("nickname");
		std::cout << std::endl;
		for (int i = 0; i < length; i++) {
			displayPart(std::to_string(i));
			displayPart(phonebook.getContact(i).getFirstName());
			displayPart(phonebook.getContact(i).getLastName());
			displayPart(phonebook.getContact(i).getNickName());
			std::cout << std::endl;
		}
	}
	return true;
}

void searchForIndex(PhoneBook phonebook) {
	std::string index;
	std::cout << "Enter Contact Index: ";
	std::getline(std::cin, index);
	if (std::cin.eof()) exit(0);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7') {
		if (index[0] - 48 < phonebook.getNumberOfContacts()) {
			std::cout << "first name: " << phonebook.getContact(index[0] - 48).getFirstName() << std::endl;
			std::cout << "last name: " << phonebook.getContact(index[0] - 48).getLastName() << std::endl;
			std::cout << "nickname: " << phonebook.getContact(index[0] - 48).getLastName() << std::endl;
			std::cout << "phone number: " << phonebook.getContact(index[0] - 48).getPhoneNumber() << std::endl;
			std::cout << "darkest secret: " << phonebook.getContact(index[0] - 48).getDarkestSecret() << std::endl;
		} else {
			std::cout << "out of range" << std::endl;
		}
	} else {
		std::cout << "Bad Index" << std::endl;
	}
}