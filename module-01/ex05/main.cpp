/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:04:33 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/15 15:46:10 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	Harl instance;
	std::string input = argv[1];

	instance.complain(input);
	return 0;
}
