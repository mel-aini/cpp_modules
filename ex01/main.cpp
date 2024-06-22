/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:59:34 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/07 09:00:15 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

int main() {
	PhoneBook phonebook;
	while (1) {
		std::string buffer;

		std::getline(std::cin, buffer);
		if (std::cin.eof()) exit(0);
		if (buffer == "ADD") {
			std::string firstname = getInput("first name: ");
			std::string lastname = getInput("last name: ");
			std::string nickname = getInput("nickname: ");
			std::string phonenumber = getInput("phone number: ");
			std::string darkestSec = getInput("darkest secret: ");
			int index = phonebook.getIndex();
			phonebook.setContactFirstName(index, firstname);
			phonebook.setContactLastName(index, lastname);
			phonebook.setContactNickName(index, nickname);
			phonebook.setContactPhoneNumber(index, phonenumber);
			phonebook.setContactDarkestSecret(index, darkestSec);
			std::cout << "Contact Added successfully!" << std::endl;
			phonebook.setNumberOfContacts();
		}
		else if (buffer == "SEARCH") {
			bool status = displayAll(phonebook);
			if (status == true) {
				searchForIndex(phonebook);
			}
		}
		else if (buffer == "EXIT" || std::cin.eof()) {
			break ;
		} else {
			std::cout << "Invalid Command" << std::endl;
		}
	}
}