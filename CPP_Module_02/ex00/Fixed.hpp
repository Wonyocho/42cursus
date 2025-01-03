/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed..hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:29:34 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/03 22:32:21 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIEXED_HPP
# define FIEXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed &src);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
	private:
		int _flexedPointValue;
		const static int _fractionalBits = 8;
};
# endif