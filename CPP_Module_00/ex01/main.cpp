/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:31:24 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 14:20:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

int main()
{
	std::string command;
	PhoneBook page[8];
	int i = 0;

	while (std::getline(std::cin, command)) {
		if (command.compare("exit") == 0 || command.compare("EXIT") == 0) { // exit 입력시 종료
			exit(0);
		} else if (command.compare("add") == 0 || command.compare("ADD") == 0) { // add 입력시 연락처 추가
			i %= 8; // 차례대로 저장하다가 8개가 넘어가면 0부터 다시입력
			page[i].input_contact(i);
			i++;
		} else if (command.compare("search") == 0 || command.compare("SEARCH") == 0) { // search 입력시 연락처 출력
			show_privew(page);
			select_index(page);
		}
	}
}
