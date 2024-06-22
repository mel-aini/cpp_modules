/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:55:17 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/12 17:50:51 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

	private:
		std::string firstname, lastname, nickname, phonenumber, darkestsecret;

	public :
		Contact();

		Contact(std::string d1, std::string d2, std::string d3, std::string d4, std::string d5);

		std::string getFirstName() const;
		
		std::string getLastName() const;

		std::string getNickName() const;

		std::string getPhoneNumber() const;
		
		std::string getDarkestSecret() const;
		
		void setFirstName(std::string data);

		void setLastName(std::string data);

		void setNickName(std::string data);

		void setPhoneNumber(std::string data);
		
		void setDarkestSecret(std::string data);

		~Contact();
};

#endif