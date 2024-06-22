/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:09:26 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/17 09:15:16 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}


	std::ifstream file((std::string)argv[1], std::ios::in);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open infile" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::stringstream sstream;
	sstream << file.rdbuf();

	std::string data = sstream.str();

	file.close();

	if (s1 != s2) {
		ssize_t foundAt = data.find(s1);


		while (s1 != "" && foundAt != -1)
		{
			data.erase(foundAt, s1.size());
			data.insert(foundAt, s2);
			foundAt = data.find(s1);
		}
	}
	std::string out = (std::string)argv[1] + ".replace";
	std::ofstream outfile(out, std::ios::out);
	if (!outfile.is_open()) {
		std::cerr << "Error: Unable to open outfile" << std::endl;
		return 1;
	}
	outfile << data;
	outfile.close();
	return 0;
}
