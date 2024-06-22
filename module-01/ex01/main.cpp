/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:55:06 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/17 09:14:02 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int main() {
	Zombie *zombies = zombieHorde(N, "Foo");

	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}

	delete[] zombies;

	return 0;
}
