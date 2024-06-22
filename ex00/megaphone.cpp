/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:40:28 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/16 10:45:26 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < argc; i++) {
			std::string str = argv[i];
			for (int j = 0; str[j]; j++) {
				std::cout << (char)std::toupper(str[j]);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}