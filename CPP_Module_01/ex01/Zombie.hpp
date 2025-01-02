/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:28:35 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 12:47:52 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	public:
		void announce(void) const;
		void get_name(std::string inputName);

		~Zombie(void);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif