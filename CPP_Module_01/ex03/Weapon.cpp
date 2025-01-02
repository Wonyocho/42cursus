/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:13:19 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 15:13:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

const std::string& Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
