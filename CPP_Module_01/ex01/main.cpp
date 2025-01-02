/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:28:38 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 13:03:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "woonshin");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}