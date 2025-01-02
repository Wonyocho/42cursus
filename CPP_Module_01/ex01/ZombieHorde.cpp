/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:28:33 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 12:51:10 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0) { // N이 0보다 작으면 NULL 반환
		std::cout << "Error: N must be greater than 0" << std::endl;
		return (NULL);
	}
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombieHorde[i].get_name(name);
	}
	return (zombieHorde);
}
