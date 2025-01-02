/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:13:21 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/02 14:54:13 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

/*
1. `Weapon` 클래스 구현
    1. `private`속성 문자열 `type`
    2. `type`의 상수 참조를 반환하는 `getType()` 멤버함수
    3. 매개변수로 전달된 새로운 `type`을 사용하여 `type`을 설정하는 `setType()` 멤버함수
*/

class Weapon
{
	public:
		const std::string& getType(void) const;
		void setType(const std::string type);

		// 생성자
		Weapon(std::string type);

	private:
		std::string type;
};

#endif