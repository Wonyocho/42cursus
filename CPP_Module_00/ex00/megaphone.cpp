/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:45:59 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 11:04:19 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
	if (argc <= 1) {	// 인자가 아무것도 안들어온 경우
		std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {			// 정상적으로 들어온 경우
		for (int i = 1; i < argc; i++) {
			std::string str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
		}
	}
	std::cout << std::endl; // 개행
	return (0);
}
