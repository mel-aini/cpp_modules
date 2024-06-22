/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:52:05 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/13 09:02:24 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

	private:
		Contact contacts[8];
		int		numberOfContacts;
		int		index;

	public :
		PhoneBook();

		void setNumberOfContacts();

		int getIndex() const;
		
		int getNumberOfContacts() const;
		
		Contact getContact(int index) const;

		void setContactFirstName(int index, std::string data);
		
		void setContactLastName(int index, std::string data);
		
		void setContactNickName(int index, std::string data);
		
		void setContactPhoneNumber(int index, std::string data);

		void setContactDarkestSecret(int index, std::string data);

		~PhoneBook();
};

#endif