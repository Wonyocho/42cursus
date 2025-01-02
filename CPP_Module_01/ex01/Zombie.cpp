/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:28:24 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 12:49:05 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::get_name(std::string inputName)
{
	this->_name = inputName;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead." << std::endl;
}