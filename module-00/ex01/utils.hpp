/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:59:53 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/13 09:02:11 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
#include "PhoneBook.hpp"

std::string getInput(std::string data);
void		displayPart(std::string part);
bool		displayAll(PhoneBook& phonebook);
void 		searchForIndex(PhoneBook phonebook);

#endif