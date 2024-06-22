/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:09:17 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/12 17:52:18 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};

Contact::Contact(std::string d1, std::string d2, std::string d3, std::string d4, std::string d5) 
	: firstname(d1),
	lastname(d2), 
	nickname(d3), 
	phonenumber(d4), 
	darkestsecret(d5) {};

std::string Contact::getFirstName() const {
	return this->firstname;
}

std::string Contact::getLastName() const {
	return this->lastname;
}

std::string Contact::getNickName() const {
	return this->nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->phonenumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestsecret;
}

void Contact::setFirstName(std::string data) {
	this->firstname = data;
}

void Contact::setLastName(std::string data) {
	this->lastname = data;
}
void Contact::setNickName(std::string data) {
	this->nickname = data;
}

void Contact::setPhoneNumber(std::string data) {
	this->phonenumber = data;
}

void Contact::setDarkestSecret(std::string data) {
	this->darkestsecret = data;
}

Contact::~Contact() {};