/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:57:03 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 12:25:25 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

// 생성자
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

// 소멸자
Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead." << std::endl;
}
