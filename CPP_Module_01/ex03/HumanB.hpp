/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:13:15 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 14:59:44 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		void attack(void);
		void setWeapon(Weapon &weapon);
		
		HumanB(std::string name);
		~HumanB(void);
	
	private:
		std::string name;
		Weapon *weapon;
};

#endif