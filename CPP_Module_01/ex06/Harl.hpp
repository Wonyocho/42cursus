/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:20:05 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 18:24:25 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		void complain(std::string level);
		Harl(void);
		~Harl(void);

	private:
		void Debug(void);
		void Info(void);
		void Warning(void);
		void Error(void);
};

#endif
