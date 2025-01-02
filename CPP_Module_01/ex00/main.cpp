/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:06:04 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 20:23:25 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie stackZombie1("Stack Zombie");
	Zombie stackZombie2("Stack Zombie");
	Zombie stackZombie3("Stack Zombie");
	Zombie *heapZombie1 = newZombie("Heap Zombie");
	randomChump("randomChump Zombie");
	stackZombie1.announce();
	stackZombie2.announce();
	stackZombie3.announce();
	heapZombie1->announce();

	delete heapZombie1;
	return (0);
}
