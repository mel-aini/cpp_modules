/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:27 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/07 08:59:45 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numberOfContacts(0), index(0) {}

void PhoneBook::setNumberOfContacts() {
	if (this->numberOfContacts < 8)
		this->numberOfContacts++;
	this->index++;
	if (this->index > 7)
	this->index = 0;
}

int PhoneBook::getIndex() const {
	return this->index;
}

int PhoneBook::getNumberOfContacts() const {
	return this->numberOfContacts;
}

Contact PhoneBook::getContact(int index) const {
	return contacts[index];
}

void PhoneBook::setContactFirstName(int index, std::string data) {
	contacts[index].setFirstName(data);
}

void PhoneBook::setContactLastName(int index, std::string data) {
	contacts[index].setLastName(data);
}

void PhoneBook::setContactNickName(int index, std::string data) {
	contacts[index].setNickName(data);
}

void PhoneBook::setContactPhoneNumber(int index, std::string data) {
	contacts[index].setPhoneNumber(data);
}
void PhoneBook::setContactDarkestSecret(int index, std::string data) {
	contacts[index].setDarkestSecret(data);
}

PhoneBook::~PhoneBook() {};